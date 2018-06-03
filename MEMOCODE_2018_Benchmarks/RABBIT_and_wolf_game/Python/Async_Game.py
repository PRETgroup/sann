import numpy as np
import Queue
from threading import Thread
import time
from timeit import default_timer as timer
import Game as game

move_queue = Queue.Queue()
score_queue = Queue.Queue()


class AGame(game.Game):
    def rabbit_turn(self):
        new_pos = self.take_turn(0)
        move_queue.put([0, new_pos])

    def wolf1_turn(self):
        new_pos = self.take_turn(1)
        move_queue.put([1, new_pos])

    def wolf2_turn(self):
        new_pos = self.take_turn(2)
        move_queue.put([2, new_pos])

    def rabbit_move(self, new_pos):
        score = self.move_rabbit(new_pos)
        score_queue.put(score)

    def wolf1_move(self, new_pos):
        score = self.move_wolf1(new_pos)
        score_queue.put(score)

    def wolf2_move(self, new_pos):
        score = self.move_wolf2(new_pos)
        score_queue.put(score)

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
                # get new positions
                r_thread = Thread(target=self.rabbit_turn)
                w1_thread = Thread(target=self.wolf1_turn)
                w2_thread = Thread(target=self.wolf2_turn)
                r_thread.start()  # start the thread
                w1_thread.start()
                w2_thread.start()
                r_thread.join()  # wait for it to finish
                w1_thread.join()
                w2_thread.join()

                # move animals and update game state
                while not move_queue.empty():
                    move = move_queue.get()
                    if move[0] == 0:  # rabbit
                        r_thread = Thread(target=self.rabbit_move, args=[move[1]])
                    if move[0] == 1:  # wolf 1
                        w1_thread = Thread(target=self.wolf1_move, args=[move[1]])
                    if move[0] == 2:  # wolf 2
                        w2_thread = Thread(target=self.wolf2_move, args=[move[1]])
                r_thread.start()  # start the thread
                w1_thread.start()
                w2_thread.start()
                r_thread.join()  # wait for it to finish
                w1_thread.join()
                w2_thread.join()

                # update score
                scores = [[0, 0], [1, 0], [0, 1], [0, -1]]
                while not score_queue.empty():
                    if score not in scores:
                        print "Score out of bounds:", score
                    new_score = score_queue.get()
                    score = [score[0] + new_score[0], score[1] + new_score[1]]

                self.turns = self.turns + 1
                if pause:
                    self.print_console()
                    time.sleep(1)
            self.score = np.add(score, self.score)
            self.reset()
            # print "Round score:", score
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
        print "Final score:", self.score
        if pause:
            print "Wolves won", self.score[0], "rounds!"
            print "Rabbits won", self.score[1], "rounds!"


