#ifndef EC_H
#define EC_H

#pragma once

#include "system_config.h"

struct EnergyConsumer {
    double currentDemandWatts;
    double previousDemandWatts;
    double futureDemandWatts;
    double totalConsumedWatts;
    int currentTick;
};

void EnergyConsumerInit(struct EnergyConsumer* me);
void EnergyConsumerUpdateDemand(struct EnergyConsumer* me, int deltaTick);
void EnergyConsumerConsumeWatts(struct EnergyConsumer* me, double watts);
double EnergyConsumerGetDemandWatts(struct EnergyConsumer* me);
double EnergyConsumerGetTotalWattsConsumption(struct EnergyConsumer* me);

#endif