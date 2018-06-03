#ifndef SYSTEM_H
#define SYSTEM_H

#pragma once

#define MAX_Q_NEURONS       41
#define Q_NEURONS1          21
#define Q_NEURONS2          10
#define Q_NEURONS3          41

#include <stdio.h>
#include <stdlib.h>
#include "system_config.h"
#include "ann_fixed.h"
#include "battery.h"
#include "energyConsumer.h"
#include "energyProducer.h"

typedef struct {
    struct Battery battery;         //the battery in the system
    struct EnergyConsumer consumer; //the electric demand (i.e. the car drawing current)
    struct EnergyProducer producer; //the power plant
    float batteryWatts[BATTERY_STEPS];

    int currentTick;

    int priceIncreasing;
    int demandIncreasing;

    double currentExpense;
}EVSystem;

void EVSystemInit(EVSystem* me);
float EVSystemRunTick(EVSystem* me, fix16_t Q_values[]);

void int_to_binary(int num, int length, int binary[]);

// helper functions
void getQValue(EVSystem *sys, ANN_F *Q, float future_price, float future_demand, float price, float demand, float battery_level, fix16_t q_values[]);


#endif