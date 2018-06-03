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

#define ANN_A_DATA  8
#define ANN_B_DATA  16
#define ANN_C_DATA  32

void init();

void doTrainTick();

void runFrontSensors(int input1, int input2, int input3);
void runSideSensors(int input1, int input2, int input3, int input4);
void runDecision();

int getAction();

#endif /* ADDER_H_ */
