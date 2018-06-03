/*
 * adder_data.c
 *
 *  Created on: Feb 26, 2018
 *      Author: keyan
 */

#include "adder.h"
#include "ann_weights.h"
#include "libfixmath/fix16.c"
#include "libfixmath/fix16_exp.c"

ANN_F newadder;
ANN_F * adderANN = &newadder;

int i, j, k;
fix16_t weighted_sum;

fix16_t hidden[NEURONS2];

void init()
{
	int num_weights;
	int layers[3] = {2, 2, 1};
	int activation[2] = {1, 1};
	INIT_ANN_CUSTOM_FIXED(adderANN, 3, layers, weights, 1, activation, i, j, num_weights, MAX_WEIGHTS_BIAS, MAX_LAYERS, MAX_LAYERS_LESS1)
}

void addLayer1(int x, int y)
{
	fix16_t inputs[2] = {(fix16_t)x, (fix16_t)y};

	RUN_ANN_LAYER_FIXED(inputs, hidden, adderANN, 1, i, j, k, weighted_sum, NEURONS1, NEURONS2)
}

int addLayer2()
{
	fix16_t output[1];
	
	RUN_ANN_LAYER_FIXED(hidden, output, adderANN, 2, i, j, k, weighted_sum, NEURONS2, NEURONS3)

	return (int)output[0];
}


