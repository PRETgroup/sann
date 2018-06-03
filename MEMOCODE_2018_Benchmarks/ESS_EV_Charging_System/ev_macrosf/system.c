#include "system.h"

void EVSystemInit(EVSystem* me) {
    BatteryInit(&me->battery);
    EnergyConsumerInit(&me->consumer);
    EnergyProducerInit(&me->producer);
    me->currentExpense = 0;
    me->currentTick = 1;

    me->priceIncreasing = 1;
    me->demandIncreasing = 1;

    int i;
#pragma loopbound min 0 max BATTERY_STEPS
    for(i = 0; i < BATTERY_STEPS; i++)
    {
    	if(i < BATTERY_MAX_CHARGE_WATTS / BATTERY_CHARGE_STEP)
    		me->batteryWatts[i] = - 1 * BATTERY_CHARGE_STEP * (BATTERY_MAX_CHARGE_WATTS/BATTERY_CHARGE_STEP - i);
    	else if(i == BATTERY_MAX_CHARGE_WATTS / BATTERY_CHARGE_STEP)
    		me->batteryWatts[i] = 0;
    	else
    		me->batteryWatts[i] = BATTERY_CHARGE_STEP * (i - BATTERY_MAX_CHARGE_WATTS/BATTERY_CHARGE_STEP);
    }
}

void UpdateChildren(EVSystem* me) {
    EnergyConsumerUpdateDemand(&me->consumer, 1);
    EnergyProducerUpdatePrice(&me->producer, 1);
    me->currentTick++;
}

float EVSystemRunTick(EVSystem* me, fix16_t Q_values[]) {
	// find action with biggest reward and return Q value
	int i = 0;
	//printf("Finding correct action to take in tick: %d\n", tick);

	int q_index = 0;
	fix16_t q_max = 0;

#pragma loopbound min 0 max BATTERY_STEPS
	for(i = 0; i < BATTERY_STEPS; i++)
	{
		if(Q_values[i] > q_max)
		{
			q_max = Q_values[i];
			q_index = i;
		}
	}

	//printf("Tick: %d; Price: $ %f; Demand: %f Watts; Battery level: %f Watts\n", me->currentTick, me->producer.currentKWhPrice, me->consumer.currentDemandWatts, me->battery.storedColumbs / SECONDS_PER_TICK);
	//printf("Expense starting at: %f\n", me->currentExpense);
	//charge the battery at the current price according to the battery current
	double demandWattsThisTick = EnergyConsumerGetDemandWatts(&me->consumer);
	//printf("Watts being demanded by consumers: %f\n", demandWattsThisTick);
	EnergyConsumerConsumeWatts(&me->consumer, demandWattsThisTick);

	double batteryControlWatts = me->batteryWatts[q_index];
	if(batteryControlWatts > BATTERY_MAX_CHARGE_WATTS) {
		batteryControlWatts = BATTERY_MAX_CHARGE_WATTS;
	}

	//printf("^^^^^^ Watts of battery this tick: %f\n", batteryControlWatts);

	if(batteryControlWatts > 0) { //we want to charge battery
		// Watts is Coulombs/second, so we multiply it by number of seconds
		BatteryAttemptInputCoulombs(&me->battery, batteryControlWatts * SECONDS_PER_TICK);
		demandWattsThisTick += batteryControlWatts;
		//printf("Battery is charging %f Watts\n", batteryControlWatts);
		//printf("------ Consumed by battery: %f Watts\n", batteryControlWatts);
	} else if(batteryControlWatts < 0) {    //we want to discharge battery
		if(abs(batteryControlWatts) > demandWattsThisTick) {
			batteryControlWatts = -demandWattsThisTick;
		}
		double battRemvCoulombs = BatteryAttemptRemoveCoulombs(&me->battery, abs(batteryControlWatts) * SECONDS_PER_TICK);
		demandWattsThisTick -= (battRemvCoulombs / SECONDS_PER_TICK);
		batteryControlWatts = -(battRemvCoulombs / SECONDS_PER_TICK);
//			/if((battRemvCoulombs / SECONDS_PER_TICK) != 0)
			//printf("Battery is discharging %f Watts\n", (battRemvCoulombs / SECONDS_PER_TICK));
		//printf("------ Supplied by battery: %f Watts\n", battRemvCoulombs / SECONDS_PER_TICK);
	}
	else {
		//printf("Battery is doing nothing\n");
	}
	double expenseThisTick = demandWattsThisTick / TICKS_PER_HOUR * EnergyProducerGetCurrentKWhPrice(&me->producer) / 1000;

	//printf("====== Watts being produced by supplier: %f\n", demandWattsThisTick);
	EnergyProducerProduceWatts(&me->producer, demandWattsThisTick);

	// update current expense
	me->currentExpense += expenseThisTick;
	//printf("Expense this tick is: $ %f\n", expenseThisTick);

	UpdateChildren(me);

	return batteryControlWatts;
}

void int_to_binary(int num, int length, int binary[])
{
	int pos = 0;
	// printf("Input is: %d\n", num);
	int k; 
#pragma loopbound min 0 max MAX_BINARY
	for(k = 0; k < length; k++) 
	{ 
		binary[k] = 0; 
	} 

	int i;
#pragma loopbound min 0 max MAX_BINARY
	for(i = 0; i < MAX_BINARY; i++)
	{
		if(num <= 0)
		{
			break;
		}
		binary[length - 1 - pos] = num%2;
		num /= 2;
		pos += 1;
	}
}

// this is the Q(s, a) ANN function for this system
void getQValue(EVSystem *sys, ANN_F *Q, float future_price, float future_demand, float price, float demand, float battery_level, fix16_t q_values[]) {
    //TODO: Keyan, this should be smart
	int i;

	// put future values in range [0, MAX_VAL]
	if(future_price > MAX_PRICE)
		future_price = MAX_PRICE;
	if(future_price < 0)
		future_price = 0;
	if(future_demand > MAX_WATTS_PER_TICK)
		future_demand = MAX_WATTS_PER_TICK;
	if(future_demand < 0)
		future_demand = 0;

	fix16_t inputs[2 + DEMAND_STATES + PRICE_STATES + BATTERY_STATES];  // scale inputs

	if(future_price > price)
	{
		sys->priceIncreasing = 1;
	}
	else if(future_price < price)
	{
		sys->priceIncreasing = 0;
	}
	inputs[0] = fix16_from_int(sys->priceIncreasing);

	if(future_demand > demand)
	{
		sys->demandIncreasing = 1;
	}
	else if(future_demand < demand)
	{
		sys->demandIncreasing = 0;
	}
	inputs[1] = fix16_from_int(sys->demandIncreasing);

	int demand_state = 0;
	int found = 0;
#pragma loopbound min 0 max DEMAND_STEPS
	for(i = 0; i < DEMAND_STEPS; i++)
	{
		if((i + 1) * DEMAND_STEP > demand)
		{
			demand_state = i;
			found = 1;
			break;
		}
	}
	if(!found)
	{
		demand_state = i;
	}

	found = 0;
	int price_state = 0;
#pragma loopbound min 0 max PRICE_STEPS
	for(i = 0; i < PRICE_STEPS; i++)
	{
		if((i + 1) * PRICE_STEP > price)
		{
			price_state = i;
			found = 1;
			break;
		}
	}
	if(!found)
	{
		price_state = i;
	}

	found = 0;
	int battery_state = 0;
//	//printf("Battery level is: %f\n", battery_level / SECONDS_PER_TICK);
#pragma loopbound min 0 max BATTERY_CAPACITY_STEPS
	for(i = 0; i < BATTERY_CAPACITY_STEPS; i++)
	{
//		//printf("Battery step is: %f\n", (float)(i + 1) * BATTERY_STEP);
		if((i + 1) * BATTERY_STEP > battery_level)
		{
//			//printf("%f > %f\n", (float)(i + 1) * BATTERY_STEP, battery_level);
			battery_state = i;
			found = 1;
			break;
		}
	}
	if(!found)
	{
		battery_state = i;
	}

	int binary_demand[DEMAND_STATES];
	int_to_binary(demand_state, DEMAND_STATES, binary_demand);
#pragma loopbound min 0 max DEMAND_STATES
	for(i = 0; i < DEMAND_STATES; i++)
	{
		inputs[i + 2] = fix16_from_int(binary_demand[i]);
	}

	int binary_price[PRICE_STATES];
	int_to_binary(price_state, PRICE_STATES, binary_price);
#pragma loopbound min 0 max PRICE_STATES
	for(i = 0; i < PRICE_STATES; i++)
	{
		inputs[i + 2 + DEMAND_STATES] = fix16_from_int(binary_price[i]);
	}

	int binary_battery[BATTERY_STATES];
	int_to_binary(battery_state, BATTERY_STATES, binary_battery);
#pragma loopbound min 0 max BATTERY_STATES
	for(i = 0; i < BATTERY_STATES; i++)
	{
		inputs[i + 2 + DEMAND_STATES + PRICE_STATES] = fix16_from_int(binary_battery[i]);
	}

	int j, k;
	fix16_t hidden[Q_NEURONS2];
	fix16_t weighted_sum;

	RUN_ANN_LAYER_FIXED(inputs, hidden, Q, 1, i, j, k, weighted_sum, Q_NEURONS1, Q_NEURONS2)

	RUN_ANN_LAYER_FIXED(hidden, q_values, Q, 2, i, j, k, weighted_sum, Q_NEURONS2, Q_NEURONS3)
}
