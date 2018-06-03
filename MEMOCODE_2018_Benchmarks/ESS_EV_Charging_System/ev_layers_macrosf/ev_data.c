#include "ev.h"
// #include "ann.c"
// #include "ann_fixed.c"
#include "libfixmath/fix16_exp.c"
#include "libfixmath/fix16.c"
// #include "system.c"
// #include "battery.c"
// #include "energyConsumer.c"
// #include "energyProducer.c"
#include "ann_weights.h"

// demand predictor ANN
ANN_F new_demand_ann;
ANN_F *demand_ann = &new_demand_ann;

//price predictor ANN
ANN_F new_price_ann;
ANN_F *price_ann = &new_price_ann;

//Q-value ANN
ANN_F new_ann;
ANN_F *Q = &new_ann;

// EV system
EVSystem new_sys;
EVSystem *sys = &new_sys;

// system variables
fix16_t future_price[1];
fix16_t future_demand[1];
fix16_t q_values[BATTERY_STEPS];

// Hidden layer arrays
fix16_t hiddenQ[Q_NEURONS2];
fix16_t hiddenPrice[PRICE_NEURONS2];
fix16_t hiddenDemand[DEMAND_NEURONS2];

// Shared variables
int i, j, k;
fix16_t weighted_sum;

void init()
{
	//printf("Initialising\n");
	int i, j, num_weights;
	int train_num_layers1 = 3;
	int train_layers1[3] = {TICK_STATES, TICK_STATES, 1};
	int train_bias1 = 1;
	int train_activation1[2] = {1, 1};
	INIT_ANN_CUSTOM_FIXED(demand_ann, train_num_layers1, train_layers1, demand_weightsf, train_bias1, train_activation1, 
	i, j, num_weights, DEMAND_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

	int train_num_layers2 = 3;
	int train_layers2[3] = {TICK_STATES, (TICK_STATES + 1) / 2, 1};
	int train_bias2 = 1;
	int train_activation2[2] = {1, 1};
	INIT_ANN_CUSTOM_FIXED(price_ann, train_num_layers2, train_layers2, price_weightsf, 
	train_bias2, train_activation2, i, j, num_weights, PRICE_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

	int num_layers = 3;
	int layers[3] = {2 + DEMAND_STATES + PRICE_STATES + BATTERY_STATES, (int)(2 + DEMAND_STATES + PRICE_STATES + BATTERY_STATES) / 2, BATTERY_STEPS};
	int bias = 1;
	int activation[2] = {0, 3};
	INIT_ANN_CUSTOM_FIXED(Q, num_layers, layers, Q_weightsf, bias, activation, i, j, num_weights, Q_LAYER2, MAX_LAYERS, MAX_LAYERS_LESS1)

	EVSystemInit(sys);
}

// predict future price with the price ANN
void predictPriceLayer1()
{
	int i;
	int tick_binary[TICK_STATES];
	fix16_t tick_float[TICK_STATES];
	if(sys->currentTick < 200)
		int_to_binary(sys->currentTick + 1 + 600, TICK_STATES, tick_binary);
	else if(sys->currentTick < 600)
		int_to_binary(sys->currentTick + 1 + 400, TICK_STATES, tick_binary);
	else
		int_to_binary(sys->currentTick + 1, TICK_STATES, tick_binary);
#pragma loopbound min 0 max TICK_STATES
	for(i = 0; i < TICK_STATES; i++)
	{
		tick_float[i] = fix16_from_int(tick_binary[i] == 1 ? 1 : -1);
	}

	RUN_ANN_LAYER_FIXED(tick_float, hiddenPrice, price_ann, 1, i, j, k, weighted_sum, PRICE_NEURONS1, PRICE_NEURONS2)
}

void predictPriceLayer2()
{
	RUN_ANN_LAYER_FIXED(hiddenPrice, future_price, price_ann, 2, i, j, k, weighted_sum, PRICE_NEURONS2, PRICE_NEURONS3)

	future_price[0] = fix16_mul(fix16_div(fix16_add(future_price[0], 65536), fix16_from_int(2)), fix16_from_int(MAX_PRICE));
}

// predict future demand with the demand ANN
void predictDemandLayer1()
{
	int i;
	int tick_binary[TICK_STATES];
	fix16_t tick_float[TICK_STATES];
	if(sys->currentTick < 200)
		int_to_binary(sys->currentTick + 1 + 600, TICK_STATES, tick_binary);
	else if(sys->currentTick < 600)
		int_to_binary(sys->currentTick + 1 + 400, TICK_STATES, tick_binary);
	else
		int_to_binary(sys->currentTick + 1, TICK_STATES, tick_binary);
#pragma loopbound min 0 max TICK_STATES
	for(i = 0; i < TICK_STATES; i++)
	{
		tick_float[i] = fix16_from_int(tick_binary[i] == 1 ? 1 : -1);
	}

	RUN_ANN_LAYER_FIXED(tick_float, hiddenDemand, demand_ann, 1, i, j, k, weighted_sum, DEMAND_NEURONS1, DEMAND_NEURONS2)	
}

void predictDemandLayer2()
{
	RUN_ANN_LAYER_FIXED(hiddenDemand, future_demand, demand_ann, 2, i, j, k, weighted_sum, DEMAND_NEURONS2, DEMAND_NEURONS3)

	future_demand[0] = fix16_mul(fix16_div(fix16_add(future_demand[0], 65536), fix16_from_int(2)), fix16_from_int(MAX_WATTS_PER_TICK));
}

// run the Q ANN with the given inputs
void runQLayer1(float price, float demand)
{
	// printf("Sys tick1: %d\n", sys->currentTick);
	// printf("Inputs -> FP: %f, FD: %f, P: %f, D: %f, B: %f\n", 
	// fix16_to_float(future_price[0]), fix16_to_float(future_demand[0]), price, demand, sys->battery.storedColumbs);

	fix16_t inputs[Q_NEURONS1];
	getQInputs(sys, Q, fix16_to_float(future_price[0]), fix16_to_float(future_demand[0]), price, demand, sys->battery.storedColumbs, inputs);

	RUN_ANN_LAYER_FIXED(inputs, hiddenQ, Q, 1, i, j, k, weighted_sum, Q_NEURONS1, Q_NEURONS2)
}

void runQLayer2()
{
	// printf("Sys tick2: %d\n", sys->currentTick);
	RUN_ANN_LAYER_FIXED(hiddenQ, q_values, Q, 2, i, j, k, weighted_sum, Q_NEURONS2, Q_NEURONS3)
}

// updates the system and returns the watts produced by the battery in the previous tick
float systemUpdate()
{
	// Update the system with this tick's values
	return EVSystemRunTick(sys, q_values); // update system
}
