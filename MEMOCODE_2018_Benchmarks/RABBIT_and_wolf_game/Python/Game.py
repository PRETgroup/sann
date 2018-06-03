import numpy as np
import random as rand
from ANN import ANN
import matplotlib.pyplot as plt
from timeit import default_timer as timer
import os
import time


import os


def cls():
    os.system('cls' if os.name == 'nt' else 'clear')


class Animal:
    def __init__(self, pos=[0, 0], score=0, num_layers=3, bias=1, activation=0, layers=[20, 16, 4], symbol=u'\u0041'):
        self.pos = pos
        self.old_pos = pos
        self.score = score
        if not(num_layers == len(layers)) and len(layers) > 2:
            num_layers = len(layers)
        self.ann = ANN(num_layers, bias, activation, layers)
        self.symbol = symbol
        self.status = 0  # 0 for moving or 1 for paused (stunned)
        self.scored = False

    def move(self, inputs=[]):
        if self.status == 1:
            self.status = 0
            return self.ann.run(inputs)  # stunning disabled
            # return [0 for _ in range(self.ann.layers[self.ann.num_layers - 1])]  # stunning enabled
        return self.ann.run(inputs)


class Game:
    def __init__(self, size=20, score=0, rounds=20, turns=20, num_exits=3, move_thresh=0.1):
        self.file = None
        self.size = size
        if score == 0:
            self.max_score = rounds
        else:
            self.max_score = score
        self.max_rounds = rounds
        self.max_turns = turns
        self.num_exits = num_exits
        self.score = [-1, -1]
        self.round = 0
        self.turns = 0
        self.state = []
        self.exits = [[0, 0] for _ in range(self.num_exits)]
        self.move_thresh = move_thresh  # animals will not move if value < 0.1
        self.custom_state = [[0 for _ in range(self.size)] for _ in range(self.size)]
        self.is_custom_state = False

        # initialise board
        self.wolf1 = None
        self.wolf2 = None
        self.rabbit = None
        self.set_animals([20, 30, 8], [20, 30, 8], [20, 24, 4])
        # [20, 35, 8] [20, 35, 8] [20, 30, 4]
        # [20, 25, 8] [20, 25, 8] [20, 20, 4]
        # [20, 20, 8] [20, 20, 8] [20, 16, 4]
        # [20, 50, 8] [20, 50, 8] [20, 40, 4]
        # [20, 40, 8] [20, 40, 8] [20, 30, 4]
        # [20, 30, 8] [20, 30, 8] [20, 24, 4]

        self.reset()  # wipe board and position animals

    def set_animals(self, w1_layers, w2_layers, r_layers):
        self.wolf1 = Animal(num_layers=len(w1_layers), layers=w1_layers, symbol=u'\u25b2')  # ANN initialised in animal __init__
        self.wolf2 = Animal(num_layers=len(w2_layers), layers=w2_layers, symbol=u'\u25bc')
        self.rabbit = Animal(num_layers=len(r_layers), layers=r_layers, symbol=u'\u25cf')

    def set_state(self, state=[]):
        self.is_custom_state = True
        self.exits = []
        if len(state) == 0:
            state = self.custom_state
        for i in range(len(state)):
            for j in range((len(state))):
                self.state[i][j] = state[i][j]
                self.custom_state[i][j] = state[i][j]
                if self.state[i][j] == 2:
                    self.exits.append([i, j])
                if self.state[i][j] == 3:
                    self.wolf1.pos = [i, j]
                    self.wolf1.old_pos = [i, j]
                if self.state[i][j] == 4:
                    self.wolf2.pos = [i, j]
                    self.wolf2.old_pos = [i, j]
                if self.state[i][j] == 5:
                    self.rabbit.pos = [i, j]
                    self.rabbit.old_pos = [i, j]

    def import_from_file(self, filename="attempt.txt", epoch=0, debug=False):
        self.file = open(filename, 'r')
        # if debug:
        #     lines = self.file.readlines()[0:3]
        #     print "ANN structures:", lines[0], lines[1], lines[2]
        # each epoch takes up 9 lines - 2 lines per ANN (3 total) for 2 layers each
        num_lines = self.wolf1.ann.num_layers + self.wolf2.ann.num_layers + self.rabbit.ann.num_layers - 3

        # skip first 3 lines
        lines = self.file.readlines()[num_lines * epoch + 3: num_lines * epoch + num_lines + 3]

        # skip first 3 line
        for i in range(len(lines)):
            lines[i] = lines[i].split()
            lines[i] = [float(weight) for weight in lines[i]]

        for i in range(self.rabbit.ann.num_layers - 1):
            self.rabbit.ann.weights[i] = lines[i]
            self.wolf1.ann.weights[i] = lines[i + self.rabbit.ann.num_layers - 1]
            self.wolf2.ann.weights[i] = lines[i + self.rabbit.ann.num_layers + self.wolf1.ann.num_layers - 2]

    def print_console(self):
        for y in range(self.size):
            for x in range(self.size):
                if self.state[x][self.size - 1 - y] == 0:
                    print u'\u25a1',
                elif self.state[x][self.size - 1 - y] == 1:
                    print u'\u25a0',
                elif self.state[x][self.size - 1 - y] == 2:
                    print u'\u25ce',
                elif self.state[x][self.size - 1 - y] == 3:
                    print self.wolf1.symbol,
                elif self.state[x][self.size - 1 - y] == 4:
                    print self.wolf2.symbol,
                elif self.state[x][self.size - 1 - y] == 5:
                    print self.rabbit.symbol,
                elif self.state[x][self.size - 1 - y] == 6:
                    print u'\u25b3',
                elif self.state[x][self.size - 1 - y] == 7:
                    print u'\u25bd',
                elif self.state[x][self.size - 1 - y] == 8:
                    print u'\u25cb',
            print '\n'

    def dist(self, pos1, pos2):
        dist = np.sqrt((pos1[0] - pos2[0]) ** 2 + (pos1[1] - pos2[1]) ** 2)
        return 1.0/dist

    def angle(self, pos1, pos2):
        if pos1[0] == pos2[0]:
            if pos1[1] > pos2[1]:
                angle = 270.0
            else:
                angle = 90.0
        else:
            m = float(pos1[1] - pos2[1])/float(pos1[0] - pos2[0])
            angle = np.arctan(m)*180/np.pi
            if pos1[0] > pos2[0]:
                angle = angle + 180
            if -90 < angle < 0:
                angle = angle + 360

        # print "Angle from", pos1, "to", pos2, "is", angle

        return angle/360  # return angle as percentage of 360 (scaled between 1 and 0)

    def get_inputs(self, pos):
        # print "Getting inputs for postion", pos
        inputs = [0 for _ in range(8*2 + 4)]
        animals = [[0, 0], [0, 0], [0, 0]]
        animal = 0
        # first add direction and distance of other animals
        for x in range(self.size):
            for y in range(self.size):
                if [x, y] == pos:
                    animal = self.state[x][y]
                if not([x, y] == pos) and (self.state[x][y] == 3):  # adding wolf 1 to vision
                    animals[0][0] = self.dist(pos, [x, y])
                    animals[0][1] = self.angle(pos, [x, y])
                if not([x, y] == pos) and (self.state[x][y] == 4):  # adding wolf 2 to vision
                    animals[1][0] = self.dist(pos, [x, y])
                    animals[1][1] = self.angle(pos, [x, y])
                if not([x, y] == pos) and (self.state[x][y] == 5):  # adding wolf rabbit to vision
                    animals[2][0] = self.dist(pos, [x, y])
                    animals[2][1] = self.angle(pos, [x, y])
        # add animals to inputs
        if animal == 3:
            inputs[0:2] = animals[1]
            inputs[2:4] = animals[2]
        if animal == 4:
            inputs[0:2] = animals[0]
            inputs[2:4] = animals[2]
        if animal == 5:
            inputs[0:2] = animals[0]
            inputs[2:4] = animals[1]

        for angle in range(8):
            # scan 8 directions for inputs
            found_obs = False
            found_exit = False
            end = False
            x = pos[0]
            y = pos[1]
            length = 0

            x_mod = 0
            if 2 < angle < 6:
                x_mod = -1
            if angle < 2 or angle == 7:
                x_mod = 1
            y_mod = 0
            if 0 < angle < 4:
                y_mod = 1
            if angle > 4:
                y_mod = -1

            while not(found_obs and found_exit) and not end:  # look until something found
                x = x + x_mod
                y = y + y_mod
                length = length + np.sqrt(x_mod**2 + y_mod**2)

                if x < 0 or y < 0 or x > self.size - 1 or y > self.size - 1:  # outside game boundary
                    break
                if x == 0 or y == 0 or x == self.size - 1 or y == self.size - 1:  # found game boundary
                    end = True

                if self.state[x][y] == 1:  # obstacle found
                    found_obs = True
                    inputs[4 + angle * 2] = 1.0 / length
                if self.state[x][y] == 2:  # exit found
                    found_exit = True
                    inputs[4 + angle * 2 + 1] = 1.0 / length

            if not found_obs:
                inputs[4 + angle * 2] = 0
            if not found_exit:
                inputs[4 + angle * 2 + 1] = 0

        # print "Inputs are:", inputs
        return inputs

    def take_turn(self, turn):
        # rabbit first
        # test win condition
        if turn == 0:
            inputs = self.get_inputs(self.rabbit.pos)
            move = self.rabbit.move(inputs)
            # print "Rabbit ANN output:", move
            high = self.move_thresh
            pos = -1
            for i in range(4):  # find largest movement value
                if move[i] > high:
                    high = move[i]
                    pos = i
            if pos == -1:
                return [self.rabbit.pos[0], self.rabbit.pos[1]]
            if pos == 0:
                return [self.rabbit.pos[0] + 1, self.rabbit.pos[1]]
            if pos == 1:
                return [self.rabbit.pos[0], self.rabbit.pos[1] + 1]
            if pos == 2:
                return [self.rabbit.pos[0] - 1, self.rabbit.pos[1]]
            if pos == 3:
                return [self.rabbit.pos[0], self.rabbit.pos[1] - 1]

        # then wolf
        # calculate win condition
        if turn == 1:
            inputs = self.get_inputs(self.wolf1.pos)
            move = self.wolf1.move(inputs)
            # print "Wolf 1 output:", move
            high = self.move_thresh
            pos = -1
            for i in range(8):  # find largest movement value
                if move[i] > high:
                    high = move[i]
                    pos = i
            if pos == -1:
                return [self.wolf1.pos[0], self.wolf1.pos[1]]
            if pos == 0:
                return [self.wolf1.pos[0] + 1, self.wolf1.pos[1]]  # 0
            if pos == 1:
                return [self.wolf1.pos[0] + 1, self.wolf1.pos[1] + 1]  # 45
            if pos == 2:
                return [self.wolf1.pos[0], self.wolf1.pos[1] + 1]  # 90
            if pos == 3:
                return [self.wolf1.pos[0] - 1, self.wolf1.pos[1] + 1]  # 135
            if pos == 4:
                return [self.wolf1.pos[0] - 1, self.wolf1.pos[1]]  # 180
            if pos == 5:
                return [self.wolf1.pos[0] - 1, self.wolf1.pos[1] - 1]  # 225
            if pos == 6:
                return [self.wolf1.pos[0], self.wolf1.pos[1] - 1]  # 270
            if pos == 7:
                return [self.wolf1.pos[0] + 1, self.wolf1.pos[1] - 1]  # 315

        # then final wolf
        # calculate win condition
        if turn == 2:
            inputs = self.get_inputs(self.wolf2.pos)
            move = self.wolf2.move(inputs)
            high = self.move_thresh
            pos = -1
            for i in range(8):  # find largest movement value
                if move[i] > high:
                    high = move[i]
                    pos = i
            if pos == -1:
                return [self.wolf2.pos[0], self.wolf2.pos[1]]
            if pos == 0:
                return [self.wolf2.pos[0] + 1, self.wolf2.pos[1]]  # 0
            if pos == 1:
                return [self.wolf2.pos[0] + 1, self.wolf2.pos[1] + 1]  # 45
            if pos == 2:
                return [self.wolf2.pos[0], self.wolf2.pos[1] + 1]  # 90
            if pos == 3:
                return [self.wolf2.pos[0] - 1, self.wolf2.pos[1] + 1]  # 135
            if pos == 4:
                return [self.wolf2.pos[0] - 1, self.wolf2.pos[1]]  # 180
            if pos == 5:
                return [self.wolf2.pos[0] - 1, self.wolf2.pos[1] - 1]  # 225
            if pos == 6:
                return [self.wolf2.pos[0], self.wolf2.pos[1] - 1]  # 270
            if pos == 7:
                return [self.wolf2.pos[0] + 1, self.wolf2.pos[1] - 1]  # 315

    # checks pos for val, if found, returns true
    def check_pos(self, pos, val):
        if self.state[pos[0]][pos[1]] == val:
            return True
        else:
            return False

    def take_turns(self):
        new_pos = []
        # rabbit turn
        new_pos.append(self.take_turn(0))

        # wolf1 turn
        new_pos.append(self.take_turn(1))

        # wolf2 turn
        new_pos.append(self.take_turn(2))

        return new_pos

    def move_rabbit(self, new_pos):
        if new_pos[0] <= 0 or new_pos[0] >= self.size - 1 or new_pos[1] <= 0 or new_pos[1] >= self.size - 1:
            if not self.check_pos(new_pos, 2):
                if new_pos[0] < 0 or new_pos[0] > self.size - 1 or new_pos[1] < 0 or new_pos[1] > self.size - 1:
                    print "Rabbit trying to move out of bounds:", new_pos, "from", self.rabbit.pos
                self.rabbit.old_pos = self.rabbit.pos
                self.update()
                return [0, 0]
        # test win conditions
        if not (new_pos == self.rabbit.pos):
            if self.check_pos(new_pos, 2):  # check for rabbit on exit
                self.rabbit.score = self.rabbit.score + 1
                self.rabbit.old_pos = self.rabbit.pos
                self.rabbit.pos = new_pos
                self.update()
                return [0, 1]  # return +2 score for rabbit and +0 for wolves
            elif self.check_pos(new_pos, 3):  # check if rabbit on wolf1 -> rabbit loses score
                self.rabbit.score = self.rabbit.score - 1
                self.rabbit.old_pos = self.rabbit.pos
                self.rabbit.pos = new_pos
                self.update()
                return [0, -1]
            elif self.check_pos(new_pos, 4):  # check if rabbit on wolf2
                self.rabbit.score = self.rabbit.score - 1
                self.rabbit.old_pos = self.rabbit.pos
                self.rabbit.pos = new_pos
                self.update()
                return [0, -1]
            elif self.check_pos(new_pos, 1):  # check if rabbit hit obstacle
                # self.rabbit.status = 1  # stun rabbit
                self.rabbit.old_pos = self.rabbit.pos
                self.update()
            else:  # otherwise move to empty space
                self.rabbit.old_pos = self.rabbit.pos
                self.rabbit.pos = new_pos
                self.update()

        return [0, 0]

    def move_wolf1(self, new_pos):
        if new_pos[0] <= 0 or new_pos[0] >= self.size - 1 or new_pos[1] <= 0 or new_pos[1] >= self.size - 1:
            if new_pos[0] < 0 or new_pos[0] > self.size - 1 or new_pos[1] < 0 or new_pos[1] > self.size - 1:
                print "Wolf 1 trying to move out of bounds:", new_pos, "from", self.wolf1.pos
            self.wolf1.old_pos = self.wolf1.pos
            self.update()
            return [0, 0]
        # test win conditions
        if not(new_pos == self.wolf1.pos):
            if self.check_pos(new_pos, 5):  # check if wolf1 on rabbit
                self.wolf1.score = self.wolf1.score + 1
                self.wolf1.old_pos = self.wolf1.pos
                self.wolf1.pos = new_pos
                self.update()
                return [1, 0]
            elif self.check_pos(new_pos, 1) or self.check_pos(new_pos, 4):  # check if wolf1 hit obstacle or other wolf
                self.wolf1.status = 1  # stun wolf
                self.wolf1.old_pos = self.wolf1.pos
                self.update()
            elif self.check_pos(new_pos, 2):  # check if wolf1 hit rabbit hole
                # self.wolf1.status = 1  # stun wolf and remove score
                # self.wolf1.score = self.wolf1.score - 1
                self.wolf1.old_pos = self.wolf1.pos
                self.update()
            else:  # otherwise move to empty space
                self.wolf1.old_pos = self.wolf1.pos
                self.wolf1.pos = new_pos
                self.update()

        return [0, 0]

    def move_wolf2(self, new_pos):
        if new_pos[0] <= 0 or new_pos[0] >= self.size - 1 or new_pos[1] <= 0 or new_pos[1] >= self.size - 1:
            if new_pos[0] < 0 or new_pos[0] > self.size - 1 or new_pos[1] < 0 or new_pos[1] > self.size - 1:
                print "Wolf 2 trying to move out of bounds:", new_pos, "from", self.wolf2.pos
            self.wolf2.old_pos = self.wolf2.pos
            self.update()
            return [0, 0]
        # test win conditions
        if not(new_pos == self.wolf2.pos):
            if self.check_pos(new_pos, 5):  # check if wolf2 on rabbit
                self.wolf2.score = self.wolf2.score + 1
                self.wolf2.old_pos = self.wolf2.pos
                self.wolf2.pos = new_pos
                self.update()
                return [1, 0]
            elif self.check_pos(new_pos, 1) or self.check_pos(new_pos, 3):  # check if wolf2 hit obstacle or other wolf
                self.wolf2.status = 1  # stun wolf
                self.wolf2.old_pos = self.wolf2.pos
                self.update()
            elif self.check_pos(new_pos, 2):  # check if wolf2 hit rabbit hole
                # self.wolf2.status = 1  # stun wolf and remove score
                # self.wolf2.score = self.wolf2.score - 1
                self.wolf2.old_pos = self.wolf2.pos
                self.update()
            else:  # otherwise move to empty space
                self.wolf2.old_pos = self.wolf2.pos
                self.wolf2.pos = new_pos
                self.update()

        return [0, 0]

    def run_turns(self, new_pos1, new_pos2, new_pos3, pause=False):
        score_mod = self.move_rabbit(new_pos1)
        if not(score_mod == [0, 0]):
            return score_mod

        if pause:
            self.print_console()
            time.sleep(1)

        score_mod = self.move_wolf1(new_pos2)
        if not (score_mod == [0, 0]):
            return score_mod

        if pause:
            self.print_console()
            time.sleep(1)

        score_mod = self.move_wolf2(new_pos3)
        if not (score_mod == [0, 0]):
            return score_mod

        if pause:
            self.print_console()
            time.sleep(1)

        return [0, 0]

    def update(self):
        for x in range(self.size):
            for y in range(self.size):
                if [x, y] in self.exits:
                    self.state[x][y] = 2
                elif x == 0 or x == (self.size - 1) or y == 0 or y == (self.size - 1):
                    self.state[x][y] = 1
                elif [x, y] == self.wolf1.pos:
                    self.state[x][y] = 3
                elif [x, y] == self.wolf2.pos:
                    self.state[x][y] = 4
                elif [x, y] == self.rabbit.pos:
                    self.state[x][y] = 5
                elif [x, y] == self.wolf1.old_pos:
                    self.state[x][y] = 6
                elif [x, y] == self.wolf2.old_pos:
                    self.state[x][y] = 7
                elif [x, y] == self.rabbit.old_pos:
                    self.state[x][y] = 8
                else:
                    self.state[x][y] = 0

    def reset(self):
        # create x exits
        self.exits = [[0, 0] for _ in range(self.num_exits)]
        corners = [[0, 0], [0, self.size - 1], [self.size - 1, 0], [self.size - 1, self.size - 1]]
        for i in range(self.num_exits):
            # num = rand.randint(0, 3)
            # hole = rand.randint(1, (self.size - 2))
            # if num == 0:
            #     hole = [hole, 0]
            # elif num == 1:
            #     hole = [hole, (self.size - 1)]
            # elif num == 2:
            #     hole = [0, hole]
            # elif num == 3:
            #     hole = [(self.size - 1), hole]

            hole = [rand.randint(0, self.size - 1), rand.randint(0, self.size - 1)]
            # prevent duplicate exits
            while hole in self.exits or hole in corners:
                # hole = rand.randint(1, (self.size - 2))
                # if num == 0:
                #     hole = [hole, 0]
                # elif num == 1:
                #     hole = [hole, (self.size - 1)]
                # elif num == 2:
                #     hole = [0, hole]
                # elif num == 3:
                #     hole = [(self.size - 1), hole]

                hole = [rand.randint(0, self.size - 1), rand.randint(0, self.size - 1)]
            self.exits[i] = hole

        # determine random positions for all animals
        x = rand.randint(1, self.size - 2)
        y = rand.randint(1, self.size - 2)
        while [x, y] in self.exits:
            x = rand.randint(1, self.size - 2)
        self.wolf1.pos = [x, y]  # ANN initialised in animal __init__

        x = rand.randint(1, self.size - 2)
        y = rand.randint(1, self.size - 2)
        while [x, y] == self.wolf1.pos or [x, y] in self.exits:
            x = rand.randint(1, self.size - 2)
        self.wolf2.pos = [x, y]

        x = rand.randint(1, self.size - 2)
        y = rand.randint(1, self.size - 2)
        while [x, y] == self.wolf1.pos or [x, y] == self.wolf2.pos or [x, y] in self.exits:
            y = rand.randint(1, self.size - 2)
        self.rabbit.pos = [x, y]
        self.rabbit.scored = False

        # zero the game board and add walls and exits
        self.state = []
        for x in range(self.size):
            self.state.append([0 for _ in range(self.size)])

        if self.is_custom_state:
            self.set_state([])
        else:
            self.update()

        return self.state

    def evaluate_file(self, generations, filename="attempt.txt", top_gens=10, debug=False, output_name = 'scoring'):
        wolves = []
        rabbits = []
        print "Evaluating file", filename
        for i in range(generations):
            print "-> In generation:", i
            self.import_from_file(filename, i, debug)
            self.start()
            wolves.append([self.score[0], i])
            rabbits.append([self.score[1], i])
        sorted_wolves = sorted(wolves, key=lambda w: w[0], reverse=True)
        sorted_rabbits = sorted(rabbits, key=lambda r: r[0], reverse=True)

        print "Top", top_gens,"wolf generations:", sorted_wolves[0:top_gens]
        print "Top", top_gens, "rabbit generations:", sorted_rabbits[0:top_gens]
        print "All wolf generations:", wolves
        print "All rabbit generations:", rabbits

        plt.figure()
        x = np.arange(0, generations)
        line1, = plt.plot(x, [wolf[0] for wolf in wolves], label="Wolves")
        line2, = plt.plot(x, [rabbit[0] for rabbit in rabbits], label="Rabbit")
        plt.xlabel("Generation")
        plt.ylabel("Score")
        plt.legend(handles=[line1, line2])
        fname = filename[0: len(filename) - 4] + '_' + output_name + '.png'
        plt.savefig(fname)
        # plt.show()

    def start(self, pause=False):
        self.score = [0, 0]
        self.rabbit.score = 0
        self.wolf1.score = 0
        self.wolf2.score = 0
        self.round = 0
        self.reset()
        if pause:
            self.print_console()
        while self.round < self.max_rounds and self.max_score not in self.score:
            self.round = self.round + 1
            self.turns = 0  # whole set of animal turns
            score = [0, 0]
            while self.turns < self.max_turns and score == [0, 0]:
                new_pos = self.take_turns()
                score = self.run_turns(new_pos[0], new_pos[1], new_pos[2], pause)
                self.turns = self.turns + 1
                if pause:
                    self.print_console()
                    time.sleep(1)
            self.score = np.add(score, self.score)
            self.reset()
            if pause:
                print "\n<=============== Round over =================>"
                print "Rabbit scored", score[1], "points!"
                print "Wolves scored", score[0], "points!"
                # if score == [1, 0]:
                #     print "Wolves scored!"
                # if score == [0, 1]:
                #     print "Rabbit scored!"
                # if score == [0, -1]:
                #     print "Rabbit penalised..."
                # if score == [0, 0]:
                #     print "Nobody scored..."
                print "Round number:", self.round
                print "Score for this round:", score
                print "Turns taken:", self.turns
                print "Total score:", self.score
                time.sleep(2)
        if pause:
            print "Wolves won", self.score[0], "rounds!"
            print "Rabbits won", self.score[1], "rounds!"


