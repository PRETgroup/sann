/*
 * adder_data.c
 *
 *  Created on: Feb 26, 2018
 *      Author: keyan
 */

#include "aibro.h"
#include "ann_weights.h"
#include "libfixmath/fix16.c"
#include "libfixmath/fix16_exp.c"
// #include "ann_fixed.c"
// #include "ann_fixed.h"

// Neural Network declarations

// Activation function for a 2 input neuron.
// Takes weighted input sum and returns the activation output
int activate2(int input1, int input2, int network, int layer, int neuron, int function)
{
	fix16_t fixedI1 = (fix16_t)input1;
	fix16_t fixedI2 = (fix16_t)input2;

	fix16_t fixedWeight1 = 0;
	fix16_t fixedWeight2 = 0;
	fix16_t fixedWeightB = 0;

	int weight_index = 0;
	
	if(network == 0)
	{
		weight_index = neuron * A_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, A_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, A_weights[layer - 1][weight_index + 1]);
		fixedWeightB = A_weights[layer - 1][A_neurons[layer - 1] * A_neurons[layer] + neuron];
	}
	else if(network == 1)
	{
		weight_index = neuron * B_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, B_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, B_weights[layer - 1][weight_index + 1]);
		fixedWeightB = B_weights[layer - 1][B_neurons[layer - 1] * B_neurons[layer] + neuron];
	}
	else
	{
		weight_index = neuron * C_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, C_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, C_weights[layer - 1][weight_index + 1]);
		fixedWeightB = C_weights[layer - 1][C_neurons[layer - 1] * C_neurons[layer] + neuron];
	}


	fix16_t weightedSum = fix16_add(fixedWeight1, fixedWeight2);
	weightedSum = fix16_add(weightedSum, fixedWeightB);

	fix16_t output = ann_activation_fixed(function, weightedSum);

	return (int)output;
}

// Activation function for a 3 input neuron.
// Takes weighted input sum and returns the activation output
int activate3(int input1, int input2, int input3, int network, int layer, int neuron, int function)
{
	fix16_t fixedI1 = (fix16_t)input1;
	fix16_t fixedI2 = (fix16_t)input2;
	fix16_t fixedI3 = (fix16_t)input3;

	fix16_t fixedWeight1 = 0;
	fix16_t fixedWeight2 = 0;
	fix16_t fixedWeight3 = 0;
	fix16_t fixedWeightB = 0;

	int weight_index = 0;
	
	if(network == 0)
	{
		weight_index = neuron * A_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, A_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, A_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, A_weights[layer - 1][weight_index + 2]);
		fixedWeightB = A_weights[layer - 1][A_neurons[layer - 1] * A_neurons[layer] + neuron];
	}
	else if(network == 1)
	{
		weight_index = neuron * B_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, B_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, B_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, B_weights[layer - 1][weight_index + 2]);
		fixedWeightB = B_weights[layer - 1][B_neurons[layer - 1] * B_neurons[layer] + neuron];
	}
	else
	{
		weight_index = neuron * C_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, C_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, C_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, C_weights[layer - 1][weight_index + 2]);
		fixedWeightB = C_weights[layer - 1][C_neurons[layer - 1] * C_neurons[layer] + neuron];
	}


	fix16_t weightedSum = fix16_add(fixedWeight1, fixedWeight2);
	weightedSum = fix16_add(weightedSum, fixedWeight3);
	weightedSum = fix16_add(weightedSum, fixedWeightB);

	fix16_t output = ann_activation_fixed(function, weightedSum);

	return (int)output;
}

// Activation function for a 4 input neuron.
// Takes weighted input sum and returns the activation output
int activate4(int input1, int input2, int input3, int input4, int network, int layer, int neuron, int function)
{
	fix16_t fixedI1 = (fix16_t)input1;
	fix16_t fixedI2 = (fix16_t)input2;
	fix16_t fixedI3 = (fix16_t)input3;
	fix16_t fixedI4 = (fix16_t)input4;

	fix16_t fixedWeight1 = 0;
	fix16_t fixedWeight2 = 0;
	fix16_t fixedWeight3 = 0;
	fix16_t fixedWeight4 = 0;
	fix16_t fixedWeightB = 0;

	int weight_index = 0;
	
	if(network == 0)
	{
		weight_index = neuron * A_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, A_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, A_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, A_weights[layer - 1][weight_index + 2]);
		fixedWeight4 = fix16_mul(fixedI4, A_weights[layer - 1][weight_index + 3]);
		fixedWeightB = A_weights[layer - 1][A_neurons[layer - 1] * A_neurons[layer] + neuron];
	}
	else if(network == 1)
	{
		weight_index = neuron * B_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, B_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, B_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, B_weights[layer - 1][weight_index + 2]);
		fixedWeight4 = fix16_mul(fixedI4, B_weights[layer - 1][weight_index + 3]);
		fixedWeightB = B_weights[layer - 1][B_neurons[layer - 1] * B_neurons[layer] + neuron];
	}
	else
	{
		weight_index = neuron * C_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, C_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, C_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, C_weights[layer - 1][weight_index + 2]);
		fixedWeight4 = fix16_mul(fixedI4, C_weights[layer - 1][weight_index + 3]);
		fixedWeightB = C_weights[layer - 1][C_neurons[layer - 1] * C_neurons[layer] + neuron];
	}


	fix16_t weightedSum = fix16_add(fixedWeight1, fixedWeight2);
	weightedSum = fix16_add(weightedSum, fixedWeight3);
	weightedSum = fix16_add(weightedSum, fixedWeight4);
	weightedSum = fix16_add(weightedSum, fixedWeightB);

	fix16_t output = ann_activation_fixed(function, weightedSum);

	return (int)output;
}

// Activation function for a 5 input neuron.
// Takes weighted input sum and returns the activation output
int activate5(int input1, int input2, int input3, int input4, int input5, int network, int layer, int neuron, int function)
{
	fix16_t fixedI1 = (fix16_t)input1;
	fix16_t fixedI2 = (fix16_t)input2;
	fix16_t fixedI3 = (fix16_t)input3;
	fix16_t fixedI4 = (fix16_t)input4;
	fix16_t fixedI5 = (fix16_t)input5;

	fix16_t fixedWeight1 = 0;
	fix16_t fixedWeight2 = 0;
	fix16_t fixedWeight3 = 0;
	fix16_t fixedWeight4 = 0;
	fix16_t fixedWeight5 = 0;
	fix16_t fixedWeightB = 0;

	int weight_index = 0;
	
	if(network == 0)
	{
		weight_index = neuron * A_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, A_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, A_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, A_weights[layer - 1][weight_index + 2]);
		fixedWeight4 = fix16_mul(fixedI4, A_weights[layer - 1][weight_index + 3]);
		fixedWeight5 = fix16_mul(fixedI5, A_weights[layer - 1][weight_index + 4]);
		fixedWeightB = A_weights[layer - 1][A_neurons[layer - 1] * A_neurons[layer] + neuron];
	}
	else if(network == 1)
	{
		weight_index = neuron * B_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, B_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, B_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, B_weights[layer - 1][weight_index + 2]);
		fixedWeight4 = fix16_mul(fixedI4, B_weights[layer - 1][weight_index + 3]);
		fixedWeight5 = fix16_mul(fixedI5, B_weights[layer - 1][weight_index + 4]);
		fixedWeightB = B_weights[layer - 1][B_neurons[layer - 1] * B_neurons[layer] + neuron];
	}
	else
	{
		weight_index = neuron * C_neurons[layer - 1];
		fixedWeight1 = fix16_mul(fixedI1, C_weights[layer - 1][weight_index]);
		fixedWeight2 = fix16_mul(fixedI2, C_weights[layer - 1][weight_index + 1]);
		fixedWeight3 = fix16_mul(fixedI3, C_weights[layer - 1][weight_index + 2]);
		fixedWeight4 = fix16_mul(fixedI4, C_weights[layer - 1][weight_index + 3]);
		fixedWeight5 = fix16_mul(fixedI5, C_weights[layer - 1][weight_index + 4]);
		fixedWeightB = C_weights[layer - 1][C_neurons[layer - 1] * C_neurons[layer] + neuron];
	}


	fix16_t weightedSum = fix16_add(fixedWeight1, fixedWeight2);
	weightedSum = fix16_add(weightedSum, fixedWeight3);
	weightedSum = fix16_add(weightedSum, fixedWeight4);
	weightedSum = fix16_add(weightedSum, fixedWeight5);
	weightedSum = fix16_add(weightedSum, fixedWeightB);

	fix16_t output = ann_activation_fixed(function, weightedSum);

	return (int)output;
}


void debug(int val)
{
	// printf("DEBUG -> %d\n", val);
}

