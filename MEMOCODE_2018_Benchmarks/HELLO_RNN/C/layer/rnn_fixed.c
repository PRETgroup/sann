#include "rnn_fixed.h"

// Initialization
void rnn_init_fixed_custom(RNN_F * rnn, int num_layers, int layers[], fix16_t weights[][MAX_WEIGHTS_BIAS], int loss, int bias, int activation[])
{
    // printf("rnn -> Beginning initialization of rnn.\n");
	int i = 0;
	int j = 0;
	//srand(time(NULL));
	rnn->max_weights = 0;
    rnn->r_layer = 1;

#pragma loopbound min 0 max MAX_NEURONS
    for(i = 0; i < layers[rnn->r_layer]; i++)
    {
        rnn->hidden[i] = 0;
    }

	rnn->num_layers = num_layers;
	// printf("rnn -> Constructing layers.\n");
#pragma loopbound min 0 max MAX_LAYERS
	for(i = 0; i < num_layers; i++)
	{
		rnn->layers[i] = layers[i];
        int num_weights = 0;
        if(i == 0)  // input layer
        {
            num_weights = layers[i]*layers[i + 1]; // number of weights = no. in following layer * no. in current layer
            if(bias)
                num_weights += layers[i]; // add the number of weights as neurons in following layer for bias (at last positions)
#pragma loopbound min 0 max MAX_WEIGHTS_BIAS
            for(j = 0; j < num_weights; j++)
            {
                rnn->weights[i][j] = weights[i][j];
            }
        }
        else if(i == 1)  // recurrent layer
        {
            num_weights = layers[i]*layers[i];
#pragma loopbound min 0 max MAX_WEIGHTS_BIAS
            for(j = 0; j < num_weights; j++)
            {
                rnn->weights[num_layers - 1][j] = weights[num_layers - 1][j];
            }
        }
        else  // every other layer
        {
            num_weights = layers[i]*layers[i - 1]; // number of weights = no. in previous layer * no. in current layer
            if(bias)
                num_weights += layers[i]; // add the number of weights as neurons in following layer for bias (at last positions)
#pragma loopbound min 0 max MAX_WEIGHTS_BIAS
            for(j = 0; j < num_weights; j++)
            {
                rnn->weights[i - 1][j] = weights[i - 1][j];
            }
        }

        if(num_weights > rnn->max_weights) // reassign max_weights if needed (with bias weights)
            rnn->max_weights = num_weights;
	}

	// printf("rnn -> Applying bias and activation.\n");
	rnn->bias = bias;
    rnn->loss = loss;
#pragma loopbound min 0 max MAX_LAYERS_LESS1
	for(i = 0; i < rnn->num_layers - 1; i++)
	{
		rnn->activation[i] = activation[i];
	}
}

// Run functions

// Run an RNN time sequence
void rnn_run_sequence(int inputs, fix16_t input_set[][MAX_UNICODE], fix16_t output_set[][MAX_UNICODE], RNN_F *rnn)
{
    // zero hidden layer previous
#pragma loopbound min 0 max MAX_NEURONS
    for(int i = 0; i < rnn->layers[rnn->r_layer]; i++)
    {
        rnn->hidden[i] = 0;
    }

#pragma loopbound min 0 max MAX_INPUTS
    for(int t = 0; t < inputs; t++)
    {
        int i, j, k;
        fix16_t weighted_sum;
        fix16_t temp[MAX_UNICODE];

        RUN_RNN_LAYER_FIXED(input_set[t], temp, rnn, 1, i, j, k, weighted_sum, MAX_NEURONS, MAX_NEURONS, MAX_NEURONS)
        RUN_RNN_LAYER_FIXED(temp, output_set[t], rnn, 2, i, j, k, weighted_sum, MAX_NEURONS, MAX_NEURONS, MAX_NEURONS)

        // rnn_run_fixed_layer(input_set[t], temp, rnn, 1);
        // rnn_run_fixed_layer(temp, output_set[t], rnn, 2);
        // printf("Inputs: ");
        // for(int i = 0; i < 5; i++)
        // {
        //     printf("%f ", fix16_to_float(input_set[t][i]));
        // }
        // printf("\n");
        // rnn_run_fixed(input_set[t], output_set[t], rnn);
        // printf("Outputs: ");
        // for(int i = 0; i < 5; i++)
        // {
        //     printf("%f ", fix16_to_float(output_set[t][i]));
        // }
        // printf("\n\n");
    }

// transform output into one-hot vector
#pragma loopbound min 0 max MAX_INPUTS
    for(int t = 0; t < inputs; t++)
    {
        int index = 0;
#pragma loopbound min 0 max MAX_UNICODE
        for(int i = 0; i < MAX_UNICODE; i++)
        {
            if(output_set[t][i] > output_set[t][index])
            {
                index = i;
            }
        }

#pragma loopbound min 0 max MAX_UNICODE
        for(int i = 0; i < MAX_UNICODE; i++)
        {
            if(i == index)
            {
                output_set[t][i] = (fix16_t)65536;
            }
            else
            {
                output_set[t][i] = 0;
            }
        }
    }
}

// Run the RNN with a single input
void rnn_run_fixed(fix16_t inputs[], fix16_t outputs[], RNN_F *rnn)
{
    int i = 0;
	int j = 0;
	int k = 0;

#pragma loopbound min 0 max MAX_NEURONS
	for(i = 0; i < rnn->layers[0]; i++) // run through inputs and add to NN
	{
		//printf("Adding input: %f\n", inputs[i]);
		rnn->neurons[0][i] = inputs[i];
		rnn->sums[0][i] = 0; // no sums for inputs
	}

#pragma loopbound min 0 max MAX_LAYERS
	for(i = 1; i < rnn->num_layers; i++) // run for every layer except input layer
	{
		// printf("Running through layer: %d\n", i);
#pragma loopbound min 0 max MAX_NEURONS
		for(j = 0; j < rnn->layers[i]; j++) // run through every neuron in current layer
		{	
			// printf("Running through current neuron: %d\n", j);
			fix16_t weighted_sum = 0;
#pragma loopbound min 0 max MAX_NEURONS
			for(k = 0; k < rnn->layers[i - 1]; k++) // run through every neuron (input) in previous layer
			{
				//printf("Running through previous neuron %d with value: %f\n", k, rnn->neurons[i - 1][k]);
				//printf("Multiplying it by weight: %f\n", rnn->weights[i - 1][j * rnn->layers[i - 1] + k]);
				weighted_sum = fix16_add(weighted_sum, fix16_mul(rnn->neurons[i - 1][k], rnn->weights[i - 1][j * rnn->layers[i - 1] + k]));
			}

            // Recurrent layer iteration
            if(i == rnn->r_layer)
            {
                // printf("Adding recurrent neurons to %d\n", weighted_sum);
#pragma loopbound min 0 max MAX_NEURONS
                for(k = 0; k < rnn->layers[i - 1]; k++) // run through every neuron (hidden) in previous hidden layer
                {
                    weighted_sum = fix16_add(weighted_sum, fix16_mul(rnn->hidden[k], rnn->weights[rnn->num_layers - 1][j * rnn->layers[rnn->r_layer] + k]));
                    // printf("Multiplying %f by %f to get %f\n", 
                    // fix16_to_float(rnn->hidden[k]), 
                    // fix16_to_float(rnn->weights[rnn->num_layers - 1][j * rnn->layers[rnn->r_layer] + k]),
                    // fix16_to_float(weighted_sum));
                }
                // printf("Result: %d\n", weighted_sum);
            }

			if(rnn->bias) // add bias if necessary (from last position in previous layer)
			{
				//printf("Bias present\n");
				weighted_sum = fix16_add(weighted_sum, rnn->weights[i - 1][rnn->layers[i] * rnn->layers[i - 1] + j]); // add bias weight for respective neuron in current layer
			}

			rnn->sums[i][j] = weighted_sum; // add weighted sum to sum array for future use
			//printf("Weighted sum is: %f\n", weighted_sum);

            if(rnn->activation[i - 1] != 4)  // not softmax activation
            {
			    rnn->neurons[i][j] = rnn_activation_fixed(rnn->activation[i - 1], weighted_sum);
            }
			//printf("Value after activation is: %f\n", activation);
		}
        if(rnn->activation[i - 1] == 4)
        {
            softmax(rnn->layers[rnn->num_layers - 1], rnn->sums[i], rnn->neurons[i]);
        }
	}

    // printf("Hidden before: ");
    // for(int i = 0; i < 5; i++)
    // {
    //     printf("%f ", fix16_to_float(rnn->hidden[i]));
    // }
    // printf("\n");
#pragma loopbound min 0 max MAX_NEURONS
    for(j = 0; j < rnn->layers[rnn->r_layer]; j++)
    {
        rnn->hidden[j] = rnn->neurons[rnn->r_layer][j];
    }
#pragma loopbound min 0 max MAX_NEURONS
	for(i = 0; i < rnn->layers[rnn->num_layers - 1]; i++) // fill outputs for return and update hidden layer with current values
	{
		outputs[i] = rnn->neurons[rnn->num_layers - 1][i];
	}
    // printf("Hidden after: ");
    // for(int i = 0; i < 5; i++)
    // {
    //     printf("%f ", fix16_to_float(rnn->hidden[i]));
    // }
    // printf("\n");
}

// Run a single layer of the RNN
void rnn_run_fixed_layer(fix16_t inputs[], fix16_t outputs[], RNN_F *rnn, int layer)
{
    if(layer > 0)
	{
		int i = layer;
		int j = 0;
		int k = 0;
#pragma loopbound min 0 max MAX_NEURONS
		for(j = 0; j < rnn->layers[i]; j++)
		{
			fix16_t weighted_sum = 0;
#pragma loopbound min 0 max MAX_NEURONS
            // Previous layer inputs
			for(k = 0; k < rnn->layers[i - 1]; k++)
			{
				weighted_sum = fix16_add(weighted_sum, fix16_mul(inputs[k], rnn->weights[i - 1][j * rnn->layers[i - 1] + k]));
			}
            // Recurrent layer iteration
            if(i == rnn->r_layer)
            {
#pragma loopbound min 0 max MAX_NEURONS
                for(k = 0; k < rnn->layers[i - 1]; k++) // run through every neuron (hidden) in previous hidden layer
                {
                    weighted_sum = fix16_add(weighted_sum, fix16_mul(rnn->hidden[k], rnn->weights[rnn->num_layers - 1][j * rnn->layers[rnn->r_layer] + k]));
                }
            }
            // Bias input
			if(rnn->bias)
			{
				weighted_sum = fix16_add(weighted_sum, rnn->weights[i - 1][rnn->layers[i] * rnn->layers[i - 1] + j]);
			}
			rnn->sums[i][j] = weighted_sum;
			if(rnn->activation[i - 1] != 4)  // not softmax activation
            {
			    rnn->neurons[i][j] = rnn_activation_fixed(rnn->activation[i - 1], weighted_sum);
            }
			//printf("Value after activation is: %f\n", activation);
		}
        if(rnn->activation[i - 1] == 4)
        {
            softmax(rnn->layers[rnn->num_layers - 1], rnn->sums[i], rnn->neurons[i]);
        }
        if(i == rnn->r_layer)  // if this is a recurrent layer, update recurrent outputs
        {
#pragma loopbound min 0 max MAX_NEURONS
            for(j = 0; j < rnn->layers[i]; j++)
            {
                rnn->hidden[j] = rnn->neurons[i][j];
            }
        }
#pragma loopbound min 0 max MAX_NEURONS
		for(j = 0; j < rnn->layers[i]; j++)
		{
			outputs[j] = rnn->neurons[i][j];
		}
	}
}

fix16_t rnn_activation_fixed(int activation, fix16_t sum)
{
    fix16_t result;
	switch(activation){
	case 0:
		result = sigmoid_f(sum);
		break;
	case 1:
		result = tanh_f(sum);
		break;
	case 2:
		result = relu_f(sum);
		break;
	case 3:
		result = linear_f(sum);
		break;
	default:
		result = sigmoid_f(sum);
		break;
	}

	return result;
}

// softmax activation function
void softmax(int length, fix16_t in[], fix16_t out[])
{
    fix16_t exp_sum = 0;
#pragma loopbound min 0 max MAX_UNICODE
    for(int i = 0; i < length; i++)
    {
        exp_sum += fix16_exp(in[i]);
    }
#pragma loopbound min 0 max MAX_UNICODE
    for(int i = 0; i < length; i++)
    {
        out[i] = fix16_div(fix16_exp(in[i]), exp_sum);
    }
}