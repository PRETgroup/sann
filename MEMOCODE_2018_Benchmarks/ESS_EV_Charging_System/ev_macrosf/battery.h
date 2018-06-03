#pragma once

#include <stdio.h>
#include "system_config.h"

struct Battery {
    double storedColumbs;
};

void BatteryInit(struct Battery* me);

//BatteryAttemptInputCoulombs attempts to add "inputColumbs" coulombs to the battery's charge
//it will return the actual number of coulombs it added
double BatteryAttemptInputCoulombs(struct Battery* me, double inputCoulombs);

//BatteryAttemptRemoveCoulombs attempts to remove "inputColumbs" coulombs to the battery's charge
//it will return the actual number of coulombs it removed
double BatteryAttemptRemoveCoulombs(struct Battery* me, double removeCoulombs);

double BatteryGetCoulombs(struct Battery* me);
