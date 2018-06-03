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

fix16_t hidden[NEURONS2];

void init()
{
	int i, j, num_weights;
	int layers[3] = {2, 2, 1};
	int activation[2] = {1, 1};
	INIT_ANN_CUSTOM_FIXED(adderANN, 3, layers, weights, 1, activation, i, j, num_weights, MAX_WEIGHTS_BIAS, MAX_LAYERS, MAX_LAYERS_LESS1)
}

int activate2(int input1, int input2, int layer, int neuron, int function)
{
	fix16_t fixedI1 = (fix16_t)input1;
	fix16_t fixedI2 = (fix16_t)input2;

	int weight_index = neuron * neurons[layer - 1];
	fix16_t fixedWeight1 = fix16_mul(fixedI1, weights[layer - 1][weight_index]);
	fix16_t fixedWeight2 = fix16_mul(fixedI2, weights[layer - 1][weight_index + 1]);
	fix16_t fixedWeightB = weights[layer - 1][neurons[layer - 1] * neurons[layer] + neuron];

	fix16_t weightedSum = fix16_add(fixedWeight1, fixedWeight2);
	weightedSum = fix16_add(weightedSum, fixedWeightB);

	return (int)ann_activation_fixed(function, weightedSum);
}
