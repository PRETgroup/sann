#pragma once

#include <stdint.h>
#include <stdbool.h>

#define CONFIG_NAME "XOR"

#define LAYERS_LEN 3 //the total number of layers (must be at least 3)
#define LAYERS_INPUT_LEN 2 //the length of the input layer (in neurons)
#define LAYERS_OUTPUT_LEN 1 //the length of the output layer (in neurons)
#define LAYERS_HIDDEN_LEN 3 //the length of hidden layers (in neurons)

#define NUM_CONNECTIONS (LAYERS_INPUT_LEN * LAYERS_HIDDEN_LEN + (LAYERS_HIDDEN_LEN * LAYERS_HIDDEN_LEN) * (LAYERS_LEN - 3) + LAYERS_HIDDEN_LEN * LAYERS_OUTPUT_LEN)
#define NUM_NEURONS (LAYERS_INPUT_LEN + (LAYERS_HIDDEN_LEN) * (LAYERS_LEN - 2) + LAYERS_OUTPUT_LEN)

//A NeuralNetworkConnection provides a connection between two neurons in the MLP
//It also provides the Weight for that connection
struct NeuralNetworkConnection {
	uint32_t Source;
	uint32_t Destination;
	float Weight;
};

//A NeuralNetworkNeuron provides just the sum of all values sent to it. 
//To calculate the OutputValue, just pass the InputValue through an appropriate activation function
struct NeuralNetworkNeuron {
	float InputValue;
};

//A NeuralNetwork provides the arrays of Neurons and Connections.
//In a MLP, all neurons between layers N and N+1 are connected.
struct NeuralNetwork
{
	//a neural network is made up of a directed acyclic graph of neurons
	struct NeuralNetworkNeuron Neurons[NUM_NEURONS];
	struct NeuralNetworkConnection Connections[NUM_CONNECTIONS];
};

//Some Activation Functions
//float SigmoidFunction(float input);
float ThresholdFunction(float input);

//InitNetwork needs to be provided to initialise the network connection graph
void InitNetwork();

//RunNetwork will run the network and feed-forward all values
void RunNetwork(float inputs[LAYERS_INPUT_LEN]);

void __attribute__((noinline)) run_XOR_ANN_l1(float x1, float x2);
void __attribute__((noinline)) run_XOR_ANN_l2();
float __attribute__((noinline)) run_XOR_ANN_l3();

void RunNetwork_l1(float inputs[LAYERS_INPUT_LEN]);
void RunNetwork_l2();
void RunNetwork_l3();

void run_XOR_ANN_i1(float);
void run_XOR_ANN_i2(float);

void run_XOR_ANN_h1();
void run_XOR_ANN_h2();
void run_XOR_ANN_h3();

float run_XOR_ANN_o1();
