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
ANN_F tempA;
ANN_F * A = &tempA;
ANN_F tempB;
ANN_F * B = &tempB;
ANN_F tempC;
ANN_F * C = &tempC;

// Neural network inputs
fix16_t inputsA[A_NEURONS1];
fix16_t inputsB[B_NEURONS1];
fix16_t inputsC[C_NEURONS1];

// Neural network hidden layers
fix16_t hiddenA[A_NEURONS2];
fix16_t hiddenB[B_NEURONS2];
fix16_t hiddenC[C_NEURONS2];

// Neural network outputs
fix16_t outputsA[A_NEURONS3];
fix16_t outputsB[B_NEURONS3];
fix16_t outputsC[C_NEURONS3];

// Variables for macro use
int i, j, k;
fix16_t weighted_sum;

// Initialisation function for the neural networks
void init()
{
	// Structure of the ANNs
	int layersA[3] = {3, 3, 3};
    int layersB[3] = {4, 3, 2};
    int layersC[3] = {5, 4, 2};

    int num_layers = 3;
    int bias = 1;
    int activation[2] = {1, 1};

	int i, j, num_weights;

	// Initialisation macros to initialise the ANNs from a header file
    INIT_ANN_CUSTOM_FIXED(A, num_layers, layersA, A_weights, bias, activation, i, j, num_weights, A_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    INIT_ANN_CUSTOM_FIXED(B, num_layers, layersB, B_weights, bias, activation, i, j, num_weights, B_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    INIT_ANN_CUSTOM_FIXED(C, num_layers, layersC, C_weights, bias, activation, i, j, num_weights, C_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)
}

// Run function for neural network A, layer 1
void runFrontSensorsLayer1(int input1, int input2, int input3)
{
	// Set inputs for the ANN to the signals received
	inputsA[0] = fix16_from_int(input1);
	inputsA[1] = fix16_from_int(input2);
	inputsA[2] = fix16_from_int(input3);

	// printf("Front sensors are detecting: [%s		%s		  %s]\n", 
	// inputsA[0] == 65536 ? "OBJECT" : "NOTHING", inputsA[1] == 65536? "OBJECT" : "NOTHING", inputsA[2] == 65536 ? "OBJECT" : "NOTHING");

	// Set inputs for ANN A -> [0, 1, 0]
	// inputsA[0] = fix16_from_int(-1);
	// inputsA[1] = fix16_from_int(1);
	// inputsA[2] = fix16_from_int(-1);

	// Macros to run the neural network as a black box
	RUN_ANN_LAYER_FIXED(inputsA, hiddenA, A, 1, i, j, k, weighted_sum, A_NEURONS1, A_NEURONS2)
}
// Run function for neural network A, layer 2
void runFrontSensorsLayer2()
{
	RUN_ANN_LAYER_FIXED(hiddenA, outputsA, A, 2, i, j, k, weighted_sum, A_NEURONS2, A_NEURONS3)

	// printf("Neural network A outputting: [%f	%f	  %f]\n", fix16_to_float(outputsA[0]), fix16_to_float(outputsA[1]), fix16_to_float(outputsA[2]));
}

// Run function for neural network B, layer 1
void runSideSensorsLayer1(int input1, int input2, int input3, int input4)
{
	// Set inputs for the ANN to the signals received
	inputsB[0] = fix16_from_int(input1);
	inputsB[1] = fix16_from_int(input2);
	inputsB[2] = fix16_from_int(input3);
	inputsB[3] = fix16_from_int(input4);

	// printf("Side sensors are detecting: [%s	    %s		  %s	   %s]\n", 
	// inputsB[0] == 65536 ? "OBJECT" : "NOTHING", inputsB[1] == 65536 ? "OBJECT" : "NOTHING", 
	// inputsB[2] == 65536 ? "OBJECT" : "NOTHING", inputsB[3] == 65536 ? "OBJECT" : "NOTHING");

	// Set inputs for ANN B -> [0, 1, 0, 0]
	// inputsB[0] = fix16_from_int(-1);
	// inputsB[1] = fix16_from_int(1);
	// inputsB[2] = fix16_from_int(-1);
	// inputsB[3] = fix16_from_int(-1);

	// Macros to run the neural network as a black box
	RUN_ANN_LAYER_FIXED(inputsB, hiddenB, B, 1, i, j, k, weighted_sum, B_NEURONS1, B_NEURONS2)
}
// Run function for neural network B, layer 2
void runSideSensorsLayer2()
{
	RUN_ANN_LAYER_FIXED(hiddenB, outputsB, B, 2, i, j, k, weighted_sum, B_NEURONS2, B_NEURONS3)

	// printf("Neural network B outputting: [%f	%f]\n", fix16_to_float(outputsB[0]), fix16_to_float(outputsB[1]));
}

// Run function for neural network C, layer 1
void runDecisionLayer1()
{
	// Fetch inputs for this ANN from outputs of A and B
	inputsC[0] = outputsA[0];
	inputsC[1] = outputsA[1];
	inputsC[2] = outputsA[2];
	inputsC[3] = outputsB[0];
	inputsC[4] = outputsB[1];

	// printf("Neural network C inputs: [%f	%f	  %f	%f	  %f]\n", 
	// fix16_to_float(outputsA[0]), fix16_to_float(outputsA[1]), fix16_to_float(outputsA[2]), fix16_to_float(outputsB[0]), fix16_to_float(outputsB[1]));

	// Macros to run the neural network as a black box
	RUN_ANN_LAYER_FIXED(inputsC, hiddenC, C, 1, i, j, k, weighted_sum, C_NEURONS1, C_NEURONS2)
}
// Run function for neural network C, layer 2
void runDecisionLayer2()
{
	RUN_ANN_LAYER_FIXED(hiddenC, outputsC, C, 2, i, j, k, weighted_sum, C_NEURONS2, C_NEURONS3)
}

int getAction()
{
	//char actions[4][10] = {{"FORWARD"}, {"RIGHT"}, {"LEFT"}, {"STOP"} };

	//*str = strcopy(actions[(outputsC[0] > 0 ? 1 : 0) * 2 + (outputsC[1] > 0 ? 1 : 0)]);

	// return the output as a integer: 
	// 0 -> Go forward
	// 1 -> Turn right
	// 2 -> Turn left
	// 3 -> Stop!
	return (outputsC[0] > 0 ? 1 : 0) * 2 + (outputsC[1] > 0 ? 1 : 0);

	//printf("Action is: %s\n", *str);
}

