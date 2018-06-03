import numpy as np
import random as rand
import math
from timeit import default_timer as timer


class RNN:
    def __init__(self, num_layers=3, bias=1, lr=0.01, weights=[], activation=[1, 0], layers=[]):
        self.num_layers = num_layers
        self.layers = layers
        self.weights = weights
        self.neurons = []
        self.sums = []
        self.bias = bias
        self.activation = activation
        self.hidden_prev = [0 for _ in range(self.layers[1])]
        self.lr = lr
        self.loss = 0
        self.max_weights = 0
        self.r_layer = 1

        self.weights_unfolded = []
        self.sums_unfolded = []
        self.neurons_unfolded = []
        self.delta_sums = []

        if len(self.weights) < num_layers:
            self.weights = [[] for _ in range(num_layers)]
            for i in range(self.num_layers):
                num_weights = 0
                if i == 0:  # input-to-hidden layer weights
                    num_weights = self.layers[0] * self.layers[1]
                    if self.bias:
                        num_weights = num_weights + self.layers[1]
                    for j in range(num_weights):
                        rand_range = 1.0 / np.sqrt(self.layers[0] + 1)
                        self.weights[0].append(rand.uniform(-rand_range, rand_range))
                elif i == self.r_layer:  # hidden-to-hidden layer weights
                    num_weights = self.layers[self.r_layer] * self.layers[self.r_layer]
                    for j in range(num_weights):
                        rand_range = 1.0/np.sqrt(self.layers[self.r_layer] + 1)
                        self.weights[-1].append(rand.uniform(-rand_range, rand_range))
                else:  # hidden-to-other and other-to-other layer weights
                    num_weights = self.layers[i - 1] * self.layers[i]
                    if self.bias and i > 0:  # bias only for hidden and output
                        num_weights = num_weights + self.layers[i]
                    for j in range(num_weights):
                        rand_range = 1.0 / np.sqrt(self.layers[i - 1] + 1)
                        self.weights[i - 1].append(rand.uniform(-rand_range, rand_range))
                if num_weights > self.max_weights:
                    self.max_weights = num_weights

    def sigmoid(self, x):
        if x > 100:
            return 0
        if x < -100:
            return 1

        return 1 / (1 + math.exp(-x))

    def relu(self, x):
        relu_const = 1
        if x > 0:
            return relu_const * x
        else:
            return 0

    def linear(self, x):
        linear_const = 1
        return linear_const * x

    def softmax(self, x=[]):
        sum_exp = 0.0
        for i in range(len(x)):
            sum_exp = sum_exp + np.exp(x[i])
        return [np.exp(x[i])/sum_exp for i in range(len(x))]

    def activation_function(self, val, layer):
        if self.activation[layer] == 0:
            return self.sigmoid(val)
        if self.activation[layer] == 1:
            return np.tanh(val)
        if self.activation[layer] == 2:
            return self.relu(val)
        if self.activation[layer] == 3:
            return self.linear(val)
        if self.activation[layer] > 3 or self.activation[layer] < 0:
            return self.sigmoid(val)

    def loss_function(self, target, predicted):
        if self.loss == 0:
            return target - predicted
        if self.loss == 1:
            return -target*np.log(predicted)
        if self.loss < 0 or self.loss > 1:
            return target - predicted

    # run a single input value through the RNN
    def run(self, inputs=[]):
        self.neurons = []
        self.neurons.append(inputs)
        self.sums = []
        self.sums.append([])

        for i in range(1, self.num_layers):  # go through all layers
            self.neurons.append([])
            self.sums.append([])
            for j in range(self.layers[i]):  # current layer neurons
                weighted_sum = 0
                for k in range(self.layers[i - 1]):  # previous layer neurons
                    weighted_sum = weighted_sum + \
                                   self.neurons[i - 1][k] * self.weights[i - 1][j * self.layers[i - 1] + k]
                if i == self.r_layer:  # hidden recurrent layer neurons
                    for k in range(self.layers[self.r_layer]):  # adding previous hidden values
                        weighted_sum = weighted_sum + self.hidden_prev[k] * self.weights[-1][j * self.layers[self.r_layer] + k]
                if self.bias:  # adding bias values
                    weighted_sum = weighted_sum + self.weights[i - 1][self.layers[i] * self.layers[i - 1] + j]
                self.sums[i].append(weighted_sum)
                if not(self.activation[i - 1] == 4):  # not softmax (softmax needs whole array)
                    self.neurons[i].append(self.activation_function(weighted_sum, i - 1))
            if self.activation[i - 1] == 4:  # softmax activation (softmax needs whole array)
                soft_out = self.softmax(self.sums[i])
                for val in soft_out:
                    self.neurons[i].append(val)
        self.hidden_prev = [self.neurons[self.r_layer][j] for j in range(len(self.neurons[self.r_layer]))]

        return self.neurons[-1]

    # run a time sequence through the RNN
    def run_sequence(self, input_set=[]):
        self.hidden_prev = [0 for _ in range(self.layers[1])]
        output_set = []

        for t in range(len(input_set)):
            output_set.append(self.run(input_set[t]))

        for t in range(len(output_set)):
            for i in range(len(output_set[t])):  # transform softmax output into unicode input
                if output_set[t][i] == np.max(output_set[t]):
                    output_set[t][i] = 1
                else:
                    output_set[t][i] = 0

        return output_set

    # run a time sequence through the RNN given only the starting value
    def run_start(self, length=10, inputs=[]):
        self.hidden_prev = [0 for _ in range(self.layers[1])]
        output_set = []
        output_set.append(self.run(inputs))
        for i in range(len(output_set[0])):  # transform softmax output into unicode input
            if output_set[0][i] == np.max(output_set[0]):
                output_set[0][i] = 1
            else:
                output_set[0][i] = 0

        for t in range(1, length):  # start on second iteration
            output_set.append(self.run(output_set[t - 1]))  # run RNN with previous outputs
            for i in range(len(output_set[t])):  # transform softmax output into unicode input
                if output_set[t][i] == np.max(output_set[t]):
                    output_set[t][i] = 1
                else:
                    output_set[t][i] = 0

        return output_set

    def unfold(self, steps):
        self.weights_unfolded = []
        for i in range(steps):  # add unfolded layers until recurrent layer
            self.weights_unfolded.append(self.weights[0])
            self.weights_unfolded.append(self.weights[-1])
        for j in range(self.r_layer, self.num_layers - 1):  # add one set of layers following the recurrent layer
            self.weights_unfolded.append(self.weights[j])

    def run_unfolded(self, steps, input_set=[]):
        self.sums_unfolded = []
        self.sums_unfolded.append([])
        self.neurons_unfolded = []
        self.neurons_unfolded.append(self.hidden_prev)

        for i in range(steps):  # run through all input and recurrent layers
            self.neurons_unfolded.append([])
            self.sums_unfolded.append([])
            for j in range(self.layers[self.r_layer]):  # run through all recurrent neurons
                weighted_sum = 0
                for k in range(self.layers[0]):  # adding input layer neurons
                    weighted_sum = weighted_sum + input_set[i][k] * self.weights[0][j * self.layers[0] + k]
                for k in range(self.layers[self.r_layer]):  # adding previous hidden values
                    weighted_sum = weighted_sum + self.neurons_unfolded[i][k] * \
                                   self.weights[-1][j * self.layers[self.r_layer] + k]
                if self.bias:  # adding bias values
                    weighted_sum = weighted_sum + self.weights[0][self.layers[1] * self.layers[0] + j]
                self.sums_unfolded[-1].append(weighted_sum)
                self.neurons_unfolded[-1].append(self.activation_function(weighted_sum, 0))
        # calculate output layer values for final hidden layer output
        for i in range(self.r_layer + 1, self.num_layers):
            self.neurons_unfolded.append([])
            self.sums_unfolded.append([])
            for j in range(self.layers[i]):
                weighted_sum = 0
                for k in range(self.layers[i - 1]):  # previous layer neurons
                    weighted_sum = weighted_sum + \
                                   self.neurons_unfolded[-2][k] * self.weights[i - 1][j * self.layers[i - 1] + k]
                if self.bias:  # adding bias values
                    weighted_sum = weighted_sum + self.weights[i - 1][self.layers[i] * self.layers[i - 1] + j]
                self.sums_unfolded[-1].append(weighted_sum)
                if not (self.activation[i - 1] == 4):  # not softmax (softmax needs whole array)
                    self.neurons_unfolded[-1].append(self.activation_function(weighted_sum, i - 1))
            if self.activation[i - 1] == 4:  # softmax activation (softmax needs whole array)
                soft_out = self.softmax(self.sums_unfolded[-1])
                for val in soft_out:
                    self.neurons_unfolded[-1].append(val)

        return self.neurons_unfolded[-1]

    def backpropagate(self, steps, predicted_outputs=[], step_outputs=[], delta_accumulate=[], step_inputs=[]):
        # first get error(s) at output
        self.delta_sums = []
        self.delta_sums.append([self.loss_function(step_outputs[i], predicted_outputs[i]) for i in range(self.layers[-1])])

        # iterate backwards starting at the outputs and ending just before the recurrent layer
        for layer in range(self.num_layers - self.r_layer - 1):
            self.delta_sums.insert(0, [0 for _ in range(self.layers[-1 - layer - 1])])
            # run through each neuron in current layer
            error_gradients = []
            if self.activation[-1 - layer] == 4:  # softmax activation if necessary
                sum = 0
                exps = []  # store exp values of all sums
                for x in range(self.layers[-1 - layer]):
                    exps.append(np.exp(self.sums_unfolded[-1 - layer][x]))
                    sum = sum + exps[-1]

                sum = np.power(sum, 2)  # square the sum

                for x in range(self.layers[-1 - layer]):
                    partial_sum = 0
                    for y in range(self.layers[-1 - layer]):  # sum all other terms
                        if not(y == x):
                            partial_sum = partial_sum + exps[y]
                    partial_sum = partial_sum * exps[x]
                    error_gradients.append(partial_sum/sum)

            for i in range(self.layers[-1 - layer]):
                # run through each neuron in previous layer
                for j in range(self.layers[-1 - layer - 1]):
                    # back-propagate error
                    self.delta_sums[0][j] = self.delta_sums[0][j] + self.delta_sums[1][i] * \
                                            self.weights_unfolded[-1 - layer][i * self.layers[-1 - layer - 1] + j]

                    error_gradient = 0
                    # calculate error gradient for current layer
                    if self.activation[-1 - layer] == 0:  # differentiate sigmoid(x) = f(x): f'(x) = f(x)[1 - f(x)]
                        error_gradient = self.neurons_unfolded[-1 - layer][i] * (1 - self.neurons_unfolded[-1 - layer][i])
                    if self.activation[-1 - layer] == 1: # differentiate tanh(x) = f(x): f'(x) = sech(x)^2 = 1/cosh(x)^2
                        error_gradient = 1.0/np.power(np.cosh(self.sums_unfolded[-1 - layer][i]), 2)
                    if self.activation[-1 - layer] == 2:  # differentiate relu(x) = 1 if sum > 0, otherwise 0
                        if self.sums_unfolded[-1 - layer][i] > 0:
                            error_gradient = 1
                    if self.activation[-1 - layer] == 3:  # differentiate x = x
                        error_gradient = 1
                    if self.activation[-1 - layer] == 4:  # differentiate softmax done earlier
                        error_gradient = error_gradients[i]

                    weight_update = self.lr * self.delta_sums[-1 - layer][i] * \
                                    error_gradient * self.neurons_unfolded[-1 - layer - 1][j]
                    # print "Weight update0:", self.lr, "*", self.delta_sums[-1 - layer][i], "*", \
                    #     error_gradient, "*", self.neurons_unfolded[-1 - layer - 1][j], "=", weight_update

                    delta_accumulate[-1 - layer - 1][i * self.layers[-1 - layer - 1] + j] = \
                        delta_accumulate[-1 - layer - 1][i * self.layers[-1 - layer - 1] + j] + weight_update

                if self.bias:
                    error_gradient = 0
                    # calculate error gradient for current layer
                    if self.activation[-1 - layer] == 0:  # differentiate sigmoid(x) = f(x): f'(x) = f(x)[1 - f(x)]
                        error_gradient = self.neurons_unfolded[-1 - layer][i] * (1 - self.neurons_unfolded[-1 - layer][i])
                    if self.activation[
                        -1 - layer] == 1:  # differentiate tanh(x) = f(x): f'(x) = sech(x)^2 = 1/cosh(x)^2
                        error_gradient = 1.0 / np.power(np.cosh(self.sums_unfolded[-1 - layer][i]), 2)
                    if self.activation[-1 - layer] == 2:  # differentiate relu(x) = 1 if sum > 0, otherwise 0
                        if self.sums_unfolded[-1 - layer][i] > 0:
                            error_gradient = 1
                    if self.activation[-1 - layer] == 3:  # differentiate x = x
                        error_gradient = 1
                    if self.activation[-1 - layer] == 4:  # differentiate softmax done earlier
                        error_gradient = error_gradients[i]

                    weight_update = self.lr * self.delta_sums[-1 - layer][i] * error_gradient
                    # print "Weight update1:", self.lr, "*", self.delta_sums[-1 - layer - 1][i], "*", \
                    #     error_gradient, "=", weight_update

                    delta_accumulate[-1 - layer - 1][self.layers[-1 - layer] * self.layers[-1 - layer - 1] + i] = \
                        delta_accumulate[-1 - layer - 1][self.layers[-1 - layer] * self.layers[-1 - layer - 1] + i] + \
                        weight_update

        # iterate backwards through the unfolded weights array, starting at the last recurrent layer
        for layer in range(steps, 0, -1):
            if layer > 1:  # zero delta sums for previous layer
                self.delta_sums.insert(0, [0 for _ in range(self.layers[self.r_layer])])
            # run through each neuron in current layer (recurrent layer)
            for i in range(self.layers[self.r_layer]):
                # run through each neuron in previous layer (recurrent layer)
                for j in range(self.layers[self.r_layer]):
                    if layer > 1:  # don't back-propagate into input layer
                        # back-propagate error to recurrent layers (only accessing recurrent layer weights)
                        self.delta_sums[0][j] = self.delta_sums[0][j] + self.delta_sums[1][i] * \
                        self.weights_unfolded[layer * 2 - 1][i * self.layers[self.r_layer] + j]

                    error_gradient = 0
                    # calculate error gradient for current layer
                    if self.activation[0] == 0:  # differentiate sigmoid(x) = f(x): f'(x) = f(x)[1 - f(x)]
                        error_gradient = self.neurons_unfolded[layer][i] * (1 - self.neurons_unfolded[layer][i])
                    if self.activation[0] == 1:  # differentiate tanh(x) = f(x): f'(x) = sech(x)^2 = 1/cosh(x)^2
                        error_gradient = 1.0 / np.power(np.cosh(self.sums_unfolded[layer][i]), 2)
                    if self.activation[0] == 2:  # differentiate relu(x) = 1 if sum > 0, otherwise 0
                        if self.sums_unfolded[layer][i] > 0:
                            error_gradient = 1
                    if self.activation[0] == 3:  # differentiate x = 1
                        error_gradient = 1

                    # weight update for recurrent neuron
                    weight_update = self.lr * self.delta_sums[0][i] * \
                                    error_gradient * self.neurons_unfolded[layer - 1][j]
                    # print "Weight update2:", self.lr, "*", self.delta_sums[layer - 1][i], "*", \
                    #     error_gradient, "*", self.neurons_unfolded[layer - 1][j], "=", weight_update

                    # store at -1, since recurrent weights are stored at -1
                    delta_accumulate[-1][i * self.layers[self.r_layer] + j] = \
                        delta_accumulate[-1][i * self.layers[self.r_layer] + j] + weight_update

                # run through each neuron in previous layer (input layer)
                for j in range(self.layers[0]):
                    error_gradient = 0
                    # calculate error gradient for current layer
                    if self.activation[0] == 0:  # differentiate sigmoid(x) = f(x): f'(x) = f(x)[1 - f(x)]
                        error_gradient = self.neurons_unfolded[layer][i] * (1 - self.neurons_unfolded[layer][i])
                    if self.activation[0] == 1:  # differentiate tanh(x) = f(x): f'(x) = sech(x)^2 = 1/cosh(x)^2
                        error_gradient = 1.0 / np.power(np.cosh(self.sums_unfolded[layer][i]), 2)
                    if self.activation[0] == 2:  # differentiate relu(x) = 1 if sum > 0, otherwise 0
                        if self.sums_unfolded[layer][i] > 0:
                            error_gradient = 1
                    if self.activation[0] == 3:  # differentiate x = 1
                        error_gradient = 1

                    # weight update for input neuron
                    weight_update = self.lr * self.delta_sums[0][i] * \
                                    error_gradient * step_inputs[layer - 1][j]
                    # print "Weight update3:", self.lr, "*", self.delta_sums[layer - 1][i], "*", \
                    #     error_gradient, "*", step_inputs[layer - 1][j], "=", weight_update

                    delta_accumulate[0][i * self.layers[0] + j] = \
                        delta_accumulate[0][i * self.layers[0] + j] + weight_update

                # bias neuron update
                if self.bias:
                    error_gradient = 0
                    # calculate error gradient for current layer
                    if self.activation[0] == 0:  # differentiate sigmoid(x) = f(x): f'(x) = f(x)[1 - f(x)]
                        error_gradient = self.neurons_unfolded[layer][i] * (1 - self.neurons_unfolded[layer][i])
                    if self.activation[0] == 1:  # differentiate tanh(x) = f(x): f'(x) = sech(x)^2 = 1/cosh(x)^2
                        error_gradient = 1.0 / np.power(np.cosh(self.sums_unfolded[layer][i]), 2)
                    if self.activation[0] == 2:  # differentiate relu(x) = 1 if sum > 0, otherwise 0
                        if self.sums_unfolded[layer][i] > 0:
                            error_gradient = 1
                    if self.activation[0] == 3:  # differentiate x = 1
                        error_gradient = 1

                    # weight update for recurrent neuron
                    weight_update = self.lr * self.delta_sums[0][i] * error_gradient
                    # print "Weight update4:", self.lr, "*", self.delta_sums[layer - 1][i], "*", \
                    #     error_gradient, "=", weight_update

                    delta_accumulate[0][self.layers[self.r_layer] * self.layers[0] + i] = \
                        delta_accumulate[0][self.layers[self.r_layer] * self.layers[0] + i] + weight_update

    def train_one(self, epochs=100, error=0.01, steps=1, data=[]):
        num_epochs = 0
        error_tot = 1
        self.hidden_prev = [0 for _ in range(self.layers[1])]
        if steps > len(data[0]):
            steps = len(data[0])

        while num_epochs < epochs and error_tot > error:  # run through data until trained or epoch finished
            error_tot = 0.0
            # unfold necessary layers
            self.unfold(steps)
            for t in range(len(data[0]) + 1 - steps):  # run through all the data in time steps
                # select data inputs
                step_inputs = data[0][t: t + steps]
                # run inputs through unfolded network
                predicted_outputs = self.run_unfolded(steps, step_inputs)
                step_outputs = data[1][t]  # only 1 data output for time t

                error_tot = error_tot + np.sum([np.power(self.loss_function(step_outputs[i], predicted_outputs[i]), 2)
                                    for i in range(len(step_outputs))])/float(len(step_outputs))

                # store cumulative weight updates
                delta_accumulate = [[0 for _ in range(len(self.weights[i]))] for i in range(self.num_layers)]

                # back-propagate error and store weight changes
                self.backpropagate(steps, predicted_outputs, step_outputs, delta_accumulate, step_inputs)
                # print "DA 0:", delta_accumulate[0]
                # print "DA 1:", delta_accumulate[1]
                # print "DA 2:", delta_accumulate[2]

                # update weights in folded network
                for i in range(len(delta_accumulate)):
                    for j in range(len(delta_accumulate[i])):
                        # if i <= steps * self.r_layer:
                        #     delta_accumulate[i][j] = delta_accumulate[i][j] / float(steps)
                        self.weights[i][j] = self.weights[i][j] + delta_accumulate[i][j]

                # get recurrent hidden inputs for next iteration using a folded run
                self.run(data[0][t])
            error_tot = error_tot/(len(data[0]) + 1 - steps)
            print "At Epoch:", num_epochs, "->      Current error is:", error_tot
            num_epochs = num_epochs + 1


start = timer()

# print rnn.run_sequence([[1, 0, 0], [0, 0, 1]])
# print rnn.run_start(length=5, inputs=[1, 0, 0])
# rnn.unfold(1)
# print rnn.run_unfolded(1, [[1, 0, 0]])
#
# rnn.unfold(2)
# print rnn.run_unfolded(2, [[1, 0, 0], [0, 1, 0]])

# rnn.unfold(1)
# rnn.run_unfolded(1, [[0, 0, 1, 0]])
# delta_accumulate = [[0 for _ in range(len(rnn.weights[i]))] for i in range(rnn.num_layers)]
# rnn.backpropagate(1, [1, 0, 0, 0], [0, 1, 0, 0], delta_accumulate, [[0, 0, 1, 0]])

# data = [[   # inputs
#     [0, 0, 1, 0, 0],   # 0
#     [0, 1, 0, 0, 0],   # 1
#     [1, 0, 0, 0, 0],   # 2
#     [0, 1, 0, 0, 0],   # 1
#     [0, 0, 1, 0, 0],   # 0
#     [0, 0, 0, 1, 0],   # -1
#     [0, 0, 0, 0, 1],   # -2
#     [0, 0, 0, 1, 0],   # -1
#     [0, 0, 1, 0, 0]    # 0
# ], [        # outputs
#     [0, 1, 0, 0, 0],  # 1
#     [1, 0, 0, 0, 0],  # 2
#     [0, 1, 0, 0, 0],  # 1
#     [0, 0, 1, 0, 0],  # 0
#     [0, 0, 0, 1, 0],  # -1
#     [0, 0, 0, 0, 1],  # -2
#     [0, 0, 0, 1, 0],  # -1
#     [0, 0, 1, 0, 0],  # 0
#     [0, 1, 0, 0, 0]   # 1
# ]]

data = [[
    [0, 0, 1, 0],
    [0, 0, 0, 1],
    [0, 1, 0, 0],
    [0, 1, 0, 0],
], [
    [0, 0, 0, 1],
    [0, 1, 0, 0],
    [0, 1, 0, 0],
    [1, 0, 0, 0]
]]

# count = 9
# while count > 0:
rnn = RNN(layers=[4, 4, 4], lr=0.1, activation=[1, 0])

rnn.train_one(data=data, error=0.007, epochs=1000)
# rnn.train_one(steps=2, data=data, error=0.01, epochs=1000)
# rnn.train_one(steps=3, data=data, error=0.01)
# rnn.train_one(steps=4, data=data, error=0.01)

# rnn.weights[0] = [0.2632778982740025, 1.2873720206851751, 1.7626432978124789, -3.0595028774892534, 0.15098307779804732,
#  1.1126095474854287, 0.38110171779164076, 1.9364004780687225, 0.22235335481093579, -1.8002217381550798,
#  -0.70558753999902091, 2.963382220443747, -2.2589462616850731, 0.59612435854378309, -0.35356446544534881,
#  0.5648778551910083, 0.17033704006778155, 0.5060839478807142, 0.25300547672626333, 0.32407602759647469,
#  6.0782465343454941, -1.0811725796870233, 1.1174273862804875, -1.1368003446516448, -4.9914125647680363,
#  0.73875113954700855, 1.0473265626731625, 0.38706194851792741, 1.4512352933257084, -0.024051087935752818]
# rnn.weights[1] = [1.2849544717182271, -0.82627784842497254, 1.9806972719590872, -1.3404860441159823, 0.063739576435029102,
#  0.12683126700871813, 0.65883610605310594, -1.5179039027101742, -1.154818724088198, 3.3767498133387361,
#  -1.5787200645487796, 0.0043726966620622008, 2.7960435372210006, -0.64773434184637213, 0.65394967554423489,
#  2.3756590192967009, -2.0716277249803334, -1.5805960003075494, -1.3864512411867511, -2.7885305512808598,
#  -2.9205075656527311, -0.52016340775199643, -2.5017437202256838, -1.1897163743027142, -0.17265447621757785,
#  -1.1325017470971213, -1.0679391962839133, -0.4218239593885344, -0.97411887795767649, -1.4519510365432908]
# rnn.weights[2] = [-1.6989305308659794, 0.92151681407801267, 0.5222166625078084, 1.2249475740581155, 0.91207565544622293,
#  0.94521030510371584, 0.27289993394574985, -0.11237519483934363, 1.1090120092036855, -0.32718115038747075,
#  0.69846462864219272, -4.1601471690468106, -1.6198760439773012, 0.22878426496839163, 1.202923138143533,
#  0.26516957184275108, 0.66363284709514114, -0.64157228008573675, 1.0090422843555509, -0.70820431085934366,
#  -3.1982733019630514, 0.92664594706516556, -1.1515511478851503, 0.089271475518160184, 2.0459073214622094]

# for val in rnn.weights:
#     print val

# print [len(rnn.weights[i]) for i in range(len(rnn.weights))]

print ""
print "Expected:", data[1]
print "Actual:", rnn.run_sequence(data[0])
print ""
print "Expected:", data[1]
out_temp = rnn.run_start(length=4, inputs=data[0][0])
print "Actual:", out_temp

# count = 0
# for i in range(len(out_temp)):
#     if not(out_temp[i] == data[1][i]):
#         count = count + 1
#
# print count

end = timer()

print "Time taken:", (end - start)


