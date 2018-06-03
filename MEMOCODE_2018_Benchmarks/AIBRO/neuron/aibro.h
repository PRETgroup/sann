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

int activate2(int input1, int input2, int network, int layer, int neuron, int function);
int activate3(int input1, int input2, int input3, int network, int layer, int neuron, int function);
int activate4(int input1, int input2, int input3, int input4, int network, int layer, int neuron, int function);
int activate5(int input1, int input2, int input3, int input4, int input5, int network, int layer, int neuron, int function);

void debug(int val);

#endif /* ADDER_H_ */
