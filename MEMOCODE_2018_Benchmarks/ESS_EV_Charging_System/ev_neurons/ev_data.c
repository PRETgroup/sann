#include "ev.h"
// #include "ann.c"
// #include "ann_fixed.c"
// #include "libfixmath/fix16_exp.c"
// #include "libfixmath/fix16.c"
// #include "system.c"
// #include "battery.c"
// #include "energyConsumer.c"
// #include "energyProducer.c"
#include "ann_weights.h"

// predict future price with the price ANN
void predictPrice()
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

	int j, k;
	fix16_t hidden[PRICE_NEURONS2];
	fix16_t weighted_sum;

	RUN_ANN_LAYER_FIXED(tick_float, hidden, price_ann, 1, i, j, k, weighted_sum, PRICE_NEURONS1, PRICE_NEURONS2)
	RUN_ANN_LAYER_FIXED(hidden, future_price, price_ann, 2, i, j, k, weighted_sum, PRICE_NEURONS2, PRICE_NEURONS3)

	future_price[0] = fix16_mul(fix16_div(fix16_add(future_price[0], 65536), fix16_from_int(2)), fix16_from_int(MAX_PRICE));
}
// predict future demand with the demand ANN
void predictDemand()
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

	int j, k;
	fix16_t middle[DEMAND_NEURONS2];
	fix16_t weighted_sum;

	RUN_ANN_LAYER_FIXED(tick_float, middle, demand_ann, 1, i, j, k, weighted_sum, DEMAND_NEURONS1, DEMAND_NEURONS2)
	RUN_ANN_LAYER_FIXED(middle, future_demand, demand_ann, 2, i, j, k, weighted_sum, DEMAND_NEURONS2, DEMAND_NEURONS3)

	future_demand[0] = fix16_mul(fix16_div(fix16_add(future_demand[0], 65536), fix16_from_int(2)), fix16_from_int(MAX_WATTS_PER_TICK));
}

// run the Q ANN with the given inputs
void runQValues(float price, float demand)
{
	// printf("Sys tick: %d\n", sys->currentTick);
	// printf("Inputs -> FP: %f, FD: %f, P: %f, D: %f, B: %f\n", 
	// fix16_to_float(future_price[0]), fix16_to_float(future_demand[0]), price, demand, sys->battery.storedColumbs);
	getQValue(sys, Q, fix16_to_float(future_price[0]), fix16_to_float(future_demand[0]), price, demand, sys->battery.storedColumbs, q_values);
}

// updates the system and returns the watts produced by the battery in the previous tick
float systemUpdate()
{
	// Update the system with this tick's values
	return EVSystemRunTick(sys, q_values); // update system
}
