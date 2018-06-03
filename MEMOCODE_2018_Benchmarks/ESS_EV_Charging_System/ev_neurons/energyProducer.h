#ifndef EP_H
#define EP_H

#pragma once

#include "system_config.h"

struct EnergyProducer {
    double currentKWhPrice;
    double futureKWhPrice;
    double previousKWhPrice;
    double totalProducedWatts;
    int currentTick;
};

void EnergyProducerInit(struct EnergyProducer* me);
void EnergyProducerUpdatePrice(struct EnergyProducer* me, int deltaTick);
void EnergyProducerProduceWatts(struct EnergyProducer* me, double numWatts);
double EnergyProducerGetCurrentKWhPrice(struct EnergyProducer* me);

#endif