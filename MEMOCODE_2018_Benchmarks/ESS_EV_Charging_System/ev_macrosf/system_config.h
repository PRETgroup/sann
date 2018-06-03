#ifndef SYS_CONFIG_H
#define SYS_CONFIG_H

#pragma once

#include <math.h>

#define TICKS_PER_HOUR          				6
#define TICKS_PER_PRICE_PERIOD  				100
#define SECONDS_PER_TICK        				(3600 / TICKS_PER_HOUR)

#define BATTERY_STORAGE_EFFICIENCY              0.95
#define BATTERY_MAX_CHARGE_WATTS                2000
#define BATTERY_MAX_CAPACITY 					10000000.0
#define BATTERY_CHARGE_STEP						100
//#define MAX_BINARY							(int)(log2(BATTERY_MAX_CAPACITY/BATTERY_CHARGE_STEP) + 1)
#define MAX_BINARY                              24
//#define BATTERY_STEPS							(BATTERY_MAX_CHARGE_WATTS / BATTERY_CHARGE_STEP * 2 + 1)
#define BATTERY_STEPS                           41
#define BATTERY_ACTIONS							((int)(log2(BATTERY_STEPS) + 1)
//#define BATTERY_CAPACITY_STEPS                (int)(BATTERY_MAX_CAPACITY / BATTERY_STEP)
#define BATTERY_CAPACITY_STEPS                  167

#define WATTS_DEMAND_PER_CAR                    2000
#define TICKS_PER_CARS_PERIOD                   25

#define PI 										3.14159265

#define MAX_CARS								5
#define MAX_WATTS_PER_TICK						(MAX_CARS * WATTS_DEMAND_PER_CAR)
#define MAX_PRICE								50
#define MAX_EXPENSE_KW							(float)((MAX_WATTS_PER_TICK + BATTERY_MAX_CHARGE_WATTS) / TICKS_PER_HOUR * MAX_PRICE / 1000)

#define DEMAND_STEP								100
//#define DEMAND_STEPS                          (int)(MAX_WATTS_PER_TICK / DEMAND_STEP)
#define DEMAND_STEPS                            100
//#define DEMAND_STATES							((int)(log2(DEMAND_STEPS)) + 1)
#define DEMAND_STATES                           7

#define PRICE_STEP								5
//#define PRICE_STEPS                           (int)(MAX_PRICE / PRICE_STEP)
#define PRICE_STEPS                             10
//#define PRICE_STATES							((int)(log2(PRICE_STEPS)) + 1)
#define PRICE_STATES                            4

#define BATTERY_STEP							(BATTERY_CHARGE_STEP * SECONDS_PER_TICK)
//#define BATTERY_STATES					    ((int)(log2(BATTERY_CAPACITY_STEPS)) + 1)
#define BATTERY_STATES                          8

#define GAMMA									0.2
#define NUM_RUN_TICKS 							100
#define NUM_TRAIN_TICKS_MAIN					100
#define EXPLORE_INCREASE						(1.75 * NUM_RUN_TICKS)
#define EXPLORE_MAX								0.9
#define EXPLORE_START							0.1

#define REWARD_FACTOR 							0.0
#define FUTURE_VALUE_FACTOR						0.5

#define PREVIOUS_VALUES      					1
#define NUM_TRAIN_TICKS      					1000
#define NUM_TRAIN_EPOCHS						1000
#define TRAIN_ERROR								0.01
//#define TICK_STATES        					((int)(log2(NUM_TRAIN_TICKS)) + 1)
#define TICK_STATES                             10



#endif


























