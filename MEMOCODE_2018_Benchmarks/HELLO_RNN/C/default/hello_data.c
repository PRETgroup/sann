/*
 * adder_data.c
 *
 *  Created on: Feb 26, 2018
 *      Author: keyan
 */

#include "hello.h"
#include "rnn_weights.h"
#include "libfixmath/fix16.c"
#include "libfixmath/fix16_exp.c"

// Neural Network declarations
RNN_F temp;
RNN_F * rnn = &temp;

// Neural network inputs
fix16_t RNNinputs[NEURONS1];

// Neural network outputs
fix16_t RNNoutputs[NEURONS3];


// Initialisation function for the neural networks
void init()
{
	// Structure of the ANNs
    int num_layers = 3;
	int layers[3] = {4, 4, 4};
    int bias = 1;
	int loss = 0;
    int activation[2] = {1, 0};

	// Initialisation macros to initialise the ANNs from a header file
    rnn_init_fixed_custom(rnn, num_layers, layers, weights, loss, bias, activation);
}

// Run function for neural network A
void runLetter(int input1, int input2, int input3, int input4)
{
	int i, j, k;
	fix16_t weighted_sum;
	fix16_t hidden[NEURONS2];

	// Randomize inputs for the neural network 
	// This can be changed
	// for(i = 0; i < A_NEURONS2; i++)
	// 	inputsA[i] = fix16_from_int(((int)rand() % 2) > 0 ? 1 : -1);

	// Set inputs for the ANN to the signals received
	RNNinputs[0] = fix16_from_int(input1);
	RNNinputs[1] = fix16_from_int(input2);
	RNNinputs[2] = fix16_from_int(input3);
	RNNinputs[3] = fix16_from_int(input4);

	// printf("Binary input is: [%d %d %d %d]\n", RNNinputs[0], RNNinputs[1], RNNinputs[2], RNNinputs[3]);
	// int index = 0;
	// for(int i = 1; i < 4; i++)
	// {
	// 	if(RNNinputs[i] > RNNinputs[index])
	// 	{
	// 		index = i;
	// 	}
	// }
	// char letters[4] = {'O', 'L', 'H', 'E'};
	// printf("Input letter is: %c\n", letters[index]);

	// Set inputs for ANN A -> [0, 1, 0]
	// inputsA[0] = fix16_from_int(-1);
	// inputsA[1] = fix16_from_int(1);
	// inputsA[2] = fix16_from_int(-1);

	// Macros to run the neural network as a black box
	// rnn_run_fixed(RNNinputs, RNNoutputs, rnn);
	RUN_RNN_LAYER_FIXED(RNNinputs, hidden, rnn, 1, i, j, k, weighted_sum, NEURONS1, NEURONS2, NEURONS2)

	RUN_RNN_LAYER_FIXED(hidden, RNNoutputs, rnn, 2, i, j, k, weighted_sum, NEURONS2, NEURONS3, NEURONS2)

	// printf("Binary output is: [%d %d %d %d]\n", RNNoutputs[0], RNNoutputs[1], RNNoutputs[2], RNNoutputs[3]);
}

int getLetter()
{
	int index = 0;
	for(int i = 1; i < 4; i++)
	{
		if(RNNoutputs[i] > RNNoutputs[index])
		{
			index = i;
		}
	}

	return index;
}