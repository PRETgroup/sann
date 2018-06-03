/*
 * rnn_fixed.h
 *
 *  Created on: Mar 5, 2018
 *      Author: keyan
 */

// This Fixed Point Artificial Neural Network implementation uses the C Fixed Point library "libfixmath" by MIT: 
// Copyright <2018> <MIT>

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once

// includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "libfixmath/fix16.h"
#include "inttypes.h"

// definitions
// Macros
#define DO_PRAGMA_(x) _Pragma (#x)
#define DO_PRAGMA(x) DO_PRAGMA_(x)

// Macro to run a layer of the RNN
#define RUN_RNN_LAYER_FIXED(INPUTS, OUTPUTS, RNN, LAYER, i, j, k, weighted_sum, MAX_NEURONS1, MAX_NEURONS2, MAX_HIDDEN)\
	if(LAYER > 0)\
	{\
		i = LAYER;\
		j = 0;\
		k = 0;\
DO_PRAGMA(loopbound min 0 max MAX_NEURONS2)\
		for(j = 0; j < RNN->layers[i]; j++)\
		{\
			weighted_sum = 0;\
DO_PRAGMA(loopbound min 0 max MAX_NEURONS1)\
			for(k = 0; k < RNN->layers[i - 1]; k++)\
			{\
				weighted_sum = fix16_add(weighted_sum, fix16_mul(INPUTS[k], RNN->weights[i - 1][j * RNN->layers[i - 1] + k]));\
			}\
            if(i == RNN->r_layer)\
            {\
DO_PRAGMA(loopbound min 0 max MAX_HIDDEN)\
                for(k = 0; k < RNN->layers[i - 1]; k++)\
                {\
                    weighted_sum = fix16_add(weighted_sum, fix16_mul(RNN->hidden[k], RNN->weights[RNN->num_layers - 1][j * RNN->layers[RNN->r_layer] + k]));\
                }\
            }\
			if(RNN->bias)\
			{\
				weighted_sum = fix16_add(weighted_sum, RNN->weights[i - 1][RNN->layers[i] * RNN->layers[i - 1] + j]);\
			}\
			RNN->sums[i][j] = weighted_sum;\
			if(RNN->activation[i - 1] != 4)\
            {\
			    RNN->neurons[i][j] = rnn_activation_fixed(RNN->activation[i - 1], weighted_sum);\
            }\
		}\
        if(RNN->activation[i - 1] == 4)\
        {\
            softmax(RNN->layers[RNN->num_layers - 1], RNN->sums[i], RNN->neurons[i]);\
        }\
		if(i == RNN->r_layer)\
        {\
DO_PRAGMA(loopbound min 0 max MAX_HIDDEN)\
            for(j = 0; j < RNN->layers[i]; j++)\
            {\
                RNN->hidden[j] = RNN->neurons[i][j];\
            }\
        }\
DO_PRAGMA(loopbound min 0 max MAX_NEURONS2)\
		for(j = 0; j < RNN->layers[i]; j++)\
		{\
			OUTPUTS[j] = RNN->neurons[i][j];\
		}\
	}

#define MAX_LAYERS 			3
#define MAX_LAYERS_LESS1	2
#define MAX_NEURONS 		4
#define MAX_WEIGHTS			16
#define MAX_WEIGHTS_BIAS	20
#define MAX_DATA 			4
#define MAX_INPUTS          4
#define MAX_UNICODE         4
#define MAX_EPOCHS			1000
#define LEARNING_RATE 		0.2
#define LR_STEP 			0.9
#define LR_EPOCHS 			100
#define MOMENTUM 			0.0
#define LINEAR_A 			1

#define sigmoid_f(sum) 		(fix16_div(fix16_from_int(1), fix16_add(fix16_from_int(1), fix16_exp(fix16_mul(fix16_from_int(-1), sum))))) // [0, 1]
#define relu_f(sum) 		(sum > 0 ? sum : 0)
#define linear_f(sum)		(fix16_mul(fix16_from_int(LINEAR_A), sum))
#define tanh_f(sum)			(fix16_div(\
							fix16_sub(fix16_from_int(1), fix16_exp(fix16_mul(fix16_from_int(-2), sum))),\
							fix16_add(fix16_from_int(1), fix16_exp(fix16_mul(fix16_from_int(-2), sum)))\
							))
#define cosh_f(sum)			(fix16_div(\
							fix16_add(fix16_from_int(1), fix16_exp(fix16_mul(fix16_from_int(-2), sum))),\
							fix16_mul(fix16_from_int(2), fix16_exp(fix16_mul(fix16_from_int(-1), sum)))\
							))

// RNN type struct
typedef struct{
	int num_layers; // stores number of layers (I + H + ... + O)
	int layers[MAX_LAYERS]; // stores number of neurons per layer (I, H, ..., O)
	fix16_t weights[MAX_LAYERS][MAX_WEIGHTS_BIAS]; // stores weight values
	fix16_t delta_weights[MAX_LAYERS][MAX_WEIGHTS_BIAS]; // stores previous weight update values for use in momentum calculations
	int max_weights;
	// weights are assigned by future neuron, i.e. the first x weights belong to future neuron 1, the next x to future neuron 2, etc...
	// weights per layer = (neurons in previous layer + 1) * neurons in next layer
	fix16_t neurons[MAX_LAYERS][MAX_NEURONS]; // stores neuron output values during calculations (current training values)
	fix16_t sums[MAX_LAYERS][MAX_NEURONS]; // stores neuron weighted sum values during calculations (current training values)
    fix16_t hidden[MAX_NEURONS];
    int r_layer;
    int loss;
	int bias;
	int activation[MAX_LAYERS];
}RNN_F;

// train data struct
typedef struct{
	int size; // stores the number of samples
	fix16_t inputs[MAX_DATA][MAX_NEURONS]; // stores the data inputs
	fix16_t outputs[MAX_DATA][MAX_NEURONS]; // stored the data expected outputs
}Train_Data_Fixed;

// functions

// Initialization
void rnn_init_fixed_custom(RNN_F * rnn, int num_layers, int layers[], fix16_t weights[][MAX_WEIGHTS_BIAS], int loss, int bias, int activation[]);

// Run functions
void rnn_run_sequence(int inputs, fix16_t input_set[][MAX_UNICODE], fix16_t output_set[][MAX_UNICODE], RNN_F *rnn);
void rnn_run_fixed(fix16_t inputs[], fix16_t outputs[], RNN_F *rnn);
void rnn_run_fixed_layer(fix16_t inputs[], fix16_t outputs[], RNN_F *rnn, int layer);

// Misc
fix16_t rnn_activation_fixed(int activation, fix16_t sum);
void softmax(int length, fix16_t in[], fix16_t out[]);