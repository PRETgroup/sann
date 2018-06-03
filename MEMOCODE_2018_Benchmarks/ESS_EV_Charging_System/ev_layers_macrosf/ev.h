#pragma once

#include "system.h"
#include "main.h"

// system initialization
void init();

void predictPriceLayer1();
void predictPriceLayer2();

void predictDemandLayer1();
void predictDemandLayer2();

void runQLayer1(float price, float demand);
void runQLayer2();

float systemUpdate();






















