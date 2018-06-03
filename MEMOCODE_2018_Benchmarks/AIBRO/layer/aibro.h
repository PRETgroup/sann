/*
 * adder.h
 *
 *  Created on: Feb 26, 2018
 *      Author: keyan
 */

#ifndef AIBRO_H_
#define AIBRO_H_

#include <stdio.h>
#include <time.h>
#include "ann_fixed.h"
#include "main.h"

#define MAX_STRING  8

void init();

void runFrontSensorsLayer1(int input1, int input2, int input3);
void runFrontSensorsLayer2();
void runSideSensorsLayer1(int input1, int input2, int input3, int input4);
void runSideSensorsLayer2();
void runDecisionLayer1();
void runDecisionLayer2();

int getAction();

#endif /* ADDER_H_ */
