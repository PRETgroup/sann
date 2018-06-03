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