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

// Neural network outputs
fix16_t outputsA[A_NEURONS3];
fix16_t outputsB[B_NEURONS3];
fix16_t outputsC[C_NEURONS3];

// Neural network training data
fix16_t trainDataA[ANN_A_DATA][2 * MAX_NEURONS] = {
{-65536, -65536, -65536, -65536, -65536, -65536},
{-65536, -65536, 65536, -65536, -65536, -65536},
{-65536, 65536, -65536, -65536, 65536, 65536},
{-65536, 65536, 65536, -65536, 65536, -65536},
{65536, -65536, -65536, -65536, -65536, -65536},
{65536, -65536, 65536, -65536, -65536, -65536},
{65536, 65536, -65536, -65536, -65536, 65536},
{65536, 65536, 65536, 65536, 65536, 65536}};

fix16_t trainDataB[ANN_B_DATA][2 * MAX_NEURONS] = {
{-65536, -65536, -65536, -65536, -65536, -65536},{-65536, -65536, -65536, 65536, -65536, 65536},
{-65536, -65536, 65536, -65536, -65536, 65536},{-65536, -65536, 65536, 65536, -65536, 65536},
{-65536, 65536, -65536, -65536, 65536, -65536},{-65536, 65536, -65536, 65536, 65536, 65536},
{-65536, 65536, 65536, -65536, 65536, 65536},{-65536, 65536, 65536, 65536, 65536, 65536},
{65536, -65536, -65536, -65536, 65536, -65536},{65536, -65536, -65536, 65536, 65536, 65536},
{65536, -65536, 65536, -65536, 65536, 65536},{65536, -65536, 65536, 65536, 65536, 65536},
{65536, 65536, -65536, -65536, 65536, -65536},{65536, 65536, -65536, 65536, 65536, 65536},
{65536, 65536, 65536, -65536, 65536, 65536},{65536, 65536, 65536, 65536, 65536, 65536}};

fix16_t trainDataC[ANN_C_DATA][2 * MAX_NEURONS] = {
{-65536, -65536, -65536, -65536, -65536, -65536, -65536},{-65536, -65536, -65536, -65536, 65536, -65536, -65536},
{-65536, -65536, -65536, 65536, -65536, -65536, -65536},{-65536, -65536, -65536, 65536, 65536, -65536, -65536},
{-65536, -65536, 65536, -65536, -65536, -65536, 65536},{-65536, -65536, 65536, -65536, 65536, 65536, 65536},
{-65536, -65536, 65536, 65536, -65536, -65536, 65536},{-65536, -65536, 65536, 65536, 65536, 65536, 65536},
{-65536, 65536, -65536, -65536, -65536, 65536, -65536},{-65536, 65536, -65536, -65536, 65536, 65536, -65536},
{-65536, 65536, -65536, 65536, -65536, 65536, 65536},{-65536, 65536, -65536, 65536, 65536, 65536, 65536},
{-65536, 65536, 65536, -65536, -65536, -65536, 65536},{-65536, 65536, 65536, -65536, 65536, 65536, -65536},
{-65536, 65536, 65536, 65536, -65536, -65536, 65536},{-65536, 65536, 65536, 65536, 65536, 65536, 65536},
{65536, -65536, -65536, -65536, -65536, 65536, 65536},{65536, -65536, -65536, -65536, 65536, 65536, 65536},
{65536, -65536, -65536, 65536, -65536, 65536, 65536},{65536, -65536, -65536, 65536, 65536, 65536, 65536},
{65536, -65536, 65536, -65536, -65536, 65536, 65536},{65536, -65536, 65536, -65536, 65536, 65536, 65536},
{65536, -65536, 65536, 65536, -65536, 65536, 65536},{65536, -65536, 65536, 65536, 65536, 65536, 65536},
{65536, 65536, -65536, -65536, -65536, 65536, 65536},{65536, 65536, -65536, -65536, 65536, 65536, 65536},
{65536, 65536, -65536, 65536, -65536, 65536, 65536},{65536, 65536, -65536, 65536, 65536, 65536, 65536},
{65536, 65536, 65536, -65536, -65536, 65536, 65536},{65536, 65536, 65536, -65536, 65536, 65536, 65536},
{65536, 65536, 65536, 65536, -65536, 65536, 65536},{65536, 65536, 65536, 65536, 65536, 65536, 65536}};

// Neural network training variables
// Epoch counter
int epochsA;
int epochsB;
int epochsC;

// Train data indices
int indexA;
int indexB;
int indexC;


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
    // INIT_ANN_CUSTOM_FIXED(A, num_layers, layersA, A_weights, bias, activation, i, j, num_weights, A_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    // INIT_ANN_CUSTOM_FIXED(B, num_layers, layersB, B_weights, bias, activation, i, j, num_weights, B_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    // INIT_ANN_CUSTOM_FIXED(C, num_layers, layersC, C_weights, bias, activation, i, j, num_weights, C_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

	// Initialise ANNs randomely, since training will happen while running
	ann_init_fixed(A, num_layers, layersA, bias, activation);
	ann_init_fixed(B, num_layers, layersB, bias, activation);
	ann_init_fixed(C, num_layers, layersC, bias, activation);

	// set training data indices and epoch counters to 0
	indexA = 0;
	indexB = 0;
	indexC = 0;
	epochsA = 0;
	epochsB = 0;
	epochsC = 0;
}

// Train all ANNs this tick
void doTrainTick()
{
	// printf("ANNs are being trained\n");

	ann_train_online_once(A, indexA, trainDataA, epochsA);
	ann_train_online_once(B, indexB, trainDataB, epochsB);
	ann_train_online_once(C, indexC, trainDataC, epochsC);

	if(indexA == 7) // reached end of epoch for ANN A
	{
		indexA = 0;  // reset data index
		epochsA++;  // increment epoch
	}
	else 
		indexA++;
	if(indexB == 15) // reached end of epoch for ANN B
	{
		indexB = 0;  // reset data index
		epochsB++;  // increment epoch
	}
	else 
		indexB++;
	if(indexC == 31) // reached end of epoch for ANN C
	{
		indexC = 0;  // reset data index
		epochsC++;  // increment epoch
	}
	else 
		indexC++;
}

// Run function for neural network A
void runFrontSensors(int input1, int input2, int input3)
{
	int i, j, k;
	fix16_t weighted_sum;
	fix16_t hidden[A_NEURONS2];

	// Randomize inputs for the neural network 
	// This can be changed
	// for(i = 0; i < A_NEURONS2; i++)
	// 	inputsA[i] = fix16_from_int(((int)rand() % 2) > 0 ? 1 : -1);

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
	RUN_ANN_LAYER_FIXED(inputsA, hidden, A, 1, i, j, k, weighted_sum, A_NEURONS1, A_NEURONS2)

	RUN_ANN_LAYER_FIXED(hidden, outputsA, A, 2, i, j, k, weighted_sum, A_NEURONS2, A_NEURONS3)

	// printf("A outputs are: [%f	%f	%f]\n", fix16_to_float(outputsA[0]), fix16_to_float(outputsA[1]), fix16_to_float(outputsA[2]));
}

// Run function for neural network B
void runSideSensors(int input1, int input2, int input3, int input4)
{
	int i, j, k;
	fix16_t weighted_sum;
	fix16_t hidden[B_NEURONS2];

	// Randomize inputs for the neural network 
	// This can be changed
	// for(i = 0; i < B_NEURONS1; i++)
	// 	inputsB[i] = fix16_from_int(((int)rand() % 2) > 0 ? 1 : -1);

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
	RUN_ANN_LAYER_FIXED(inputsB, hidden, B, 1, i, j, k, weighted_sum, B_NEURONS1, B_NEURONS2)

	RUN_ANN_LAYER_FIXED(hidden, outputsB, B, 2, i, j, k, weighted_sum, B_NEURONS2, B_NEURONS3)

	// printf("B outputs are: [%f	%f]\n", fix16_to_float(outputsB[0]), fix16_to_float(outputsB[1]));
}

// Run function for neural network C
void runDecision()
{
	int i, j, k;
	fix16_t weighted_sum;
	fix16_t hidden[C_NEURONS2];

	// Fetch inputs for this ANN from outputs of A and B
	inputsC[0] = outputsA[0];
	inputsC[1] = outputsA[1];
	inputsC[2] = outputsA[2];
	inputsC[3] = outputsB[0];
	inputsC[4] = outputsB[1];

	// Macros to run the neural network as a black box
	RUN_ANN_LAYER_FIXED(inputsC, hidden, C, 1, i, j, k, weighted_sum, C_NEURONS1, C_NEURONS2)

	RUN_ANN_LAYER_FIXED(hidden, outputsC, C, 2, i, j, k, weighted_sum, C_NEURONS2, C_NEURONS3)

	// printf("C outputs are: [%f	%f]\n", fix16_to_float(outputsC[0]), fix16_to_float(outputsC[1]));
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

