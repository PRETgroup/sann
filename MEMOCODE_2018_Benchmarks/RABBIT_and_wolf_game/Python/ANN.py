import numpy as np
import random as rand
import math
from timeit import default_timer as timer


class ANN:
    def __init__(self, num_layers=3, bias=1, activation=1, layers=[]):
        self.num_layers = num_layers
        self.layers = layers
        self.weights = []
        self.delta_weights = []
        self.neurons = []
        self.sums = []
        self.bias = bias
        self.activation = activation

        for i in range(self.num_layers):
            self.weights.append([])
            if i > 0:
                num_weights = self.layers[i - 1] * self.layers[i]
                if self.bias:
                    num_weights = num_weights + self.layers[i]

                for j in range(num_weights):
                    self.weights[i - 1].append(rand.gauss(0, 5))

    def sigmoid(self, x):
        if x > 100:
            return 0
        if x < -100:
            return 1

        return 1 / (1 + math.exp(-x))

    def activation_function(self, val):
        if self.activation == 0:
            return self.sigmoid(val)
        if self.activation == 1:
            return np.tanh(val)
        if self.activation > 1:
            return self.sigmoid(val)

    def run(self, inputs=[]):
        self.neurons = []
        self.neurons.append([])
        self.sums = []
        self.sums.append([0 for x in range(len(inputs))])
        self.neurons[0] = inputs

        # print "Neural network input:", inputs

        for i in range(1, self.num_layers):  # go through all layers
            self.neurons.append([])
            self.sums.append([])
            for j in range(self.layers[i]):  # current layer neurons
                weighted_sum = 0
                for k in range(self.layers[i - 1]):  # previous layer neurons
                    weighted_sum = weighted_sum + \
                                   self.neurons[i - 1][k] * self.weights[i - 1][j * self.layers[i - 1] + k]
                if self.bias:
                    weighted_sum = weighted_sum + self.weights[i - 1][self.layers[i] * self.layers[i - 1] + j]
                self.sums[i].append(weighted_sum)
                self.neurons[i].append(self.activation_function(weighted_sum))

        # print "Neural network output:", self.neurons[self.num_layers - 1]

        return self.neurons[self.num_layers - 1]

    def print_ann(self, weights_only, inputs=[]):
        print "\n+++++++++++++++ PRINTING NEURAL NETWORK STRUCTURE +++++++++++++++\n"
        print "NUMBER OF LAYERS:", self.num_layers
        print "NUMBER OF INPUTS:", self.layers[0]
        print "NUMBER OF OUTPUTS:", self.layers[self.num_layers - 1]
        print "NEURONS PER LAYER:",
        for i in range(self.num_layers):
            print "->", self.layers[i],
        print ""

        if self.bias:
            print "THIS NEURAL NETWORK HAS BIAS NEURONS"
        else:
            print "THIS NEURAL NETWORK DOES NOT HAVE BIAS NEURONS"
        print "ACTIVATION FUNCTION:",
        if self.activation == 0:
            print "SIGMOID"
        elif self.activation == 1:
            print "TANH (SYMMETRIC SIGMOID)"

        if not weights_only:
            self.run(inputs)

        for i in range(self.num_layers - 1):
            print "\n<============ Listing LAYER", i,"============>\n"
            for j in range(self.layers[i]):
                if not weights_only:
                    print "LAYER", i, "NEURON", j, "has a WEIGHTED INPUT SUM of", self.sums[i][j], "and an ACTIVATION OUTPUT of", self.neurons[i][j]
                print "LAYER", i, "NEURON", j, "has", self.layers[i + 1], "connections to LAYER", (i+1)
                for k in range(self.layers[i + 1]):
                    print "-> Connection to NEURON", k, "in LAYER", (i + 1), "has a WEIGHT of", self.weights[i][k * self.layers[i] + j]
            if self.bias:
                print "LAYER", i, "has a BIAS NEURON with", self.layers[i + 1], "connections"
                for j in range(self.layers[i + 1]):
                    print "-> Connection to NEURON", j, "in LAYER", (i+1), "has a WEIGHT of", self.weights[i][self.layers[i] * self.layers[i + 1] + j]

        if not weights_only:
            print "\n<============ Listing OUTPUT LAYER ============>\n"
            output_layer = self.num_layers - 1
            for i in range(self.layers[output_layer]):
                print "LAYER", output_layer, "NEURON", i, "has a WEIGHTED INPUT SUM of", self.sums[output_layer][i], \
                    "and an ACTIVATION OUTPUT of", self.neurons[output_layer][i]

        print "\n+++++++++++++++ FINISHED PRINTING NEURAL NETWORK STRUCTURE +++++++++++++++\n"

# ann = ANN(3, True, 1, [20, 20, 4])
#
# start = timer()
#
# in_arr = [1 for x in range(20)]
# out = ann.run(in_arr)
#
# end = timer()
#
# print "Time taken:", (end - start)







