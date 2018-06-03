#pragma once

#include "system.h"
#include "main.h"

// system initialization
void init();

void predictPrice();
void predictDemand();

void runQValues(float price, float demand);

float systemUpdate();






















