#include "battery.h"

void BatteryInit(struct Battery* me) {
    me->storedColumbs = 200000;
}

double BatteryAttemptInputCoulombs(struct Battery* me, double inputCoulombs) {
	// printf("++++++ Coulombs being input into battery with charge %f C: %f\n", me->storedColumbs, inputCoulombs * BATTERY_STORAGE_EFFICIENCY);
    me->storedColumbs += (inputCoulombs * BATTERY_STORAGE_EFFICIENCY); 
    if(me->storedColumbs > BATTERY_MAX_CAPACITY)
    {
    	me->storedColumbs = BATTERY_MAX_CAPACITY;
    }
    // printf("****** Battery charge remaining: %f C\n", me->storedColumbs);
    return (inputCoulombs * BATTERY_STORAGE_EFFICIENCY);
}

double BatteryAttemptRemoveCoulombs(struct Battery* me, double removeCoulombs) {
    if(me->storedColumbs - removeCoulombs < 0) {
        double total = me->storedColumbs;
        me->storedColumbs = 0;
        return total;
    }
    // printf("###### Coulombs being removed from battery with charge %f C: %f\n", me->storedColumbs, removeCoulombs);

    me->storedColumbs -= removeCoulombs;
    // printf("////// Battery charge remaining: %f C\n", me->storedColumbs);
    return removeCoulombs;
}

double BatteryGetCoulombs(struct Battery* me) {
    return me->storedColumbs;
}
