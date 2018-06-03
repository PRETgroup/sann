/*
 * game.h
 *
 *  Created on: Mar 12, 2018
 *      Author: keyan
 */

#ifndef GAME_H_
#define GAME_H_

// includes
#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ann.h"

// definitions
#define MAX_BLOCKS 10
#define MAX_EXITS 10
#define PI 3.14159265358979323846

// animal struct, identical for wolf and rabbit
typedef struct{
	float old_pos[2];
	float pos[2];
	int score;
	ANN *ann;
	int symbol;
}Animal;

// game state struct
typedef struct{
	int state[MAX_BLOCKS][MAX_BLOCKS];
	int exits[MAX_EXITS][2];
	int size;
	// 0 - empty
	// 1 - obstacle
	// 2 - rabbit exit
	// 3 - wolf1
	// 4 - wolf2
	// 5 - rabbit
	int score[2]; // score between wolves and rabbit
	int round;
	int turns; // wolf1, wolf2 or rabbit
	int max_rounds;
	int num_exits;
	int max_score;
	int max_turns;
	float move_thresh;
	Animal *rabbit;
	Animal *wolf1;
	Animal *wolf2;
}Game;

// animal functions
void init_animal(Animal *animal, int score, int pos[], int symbol, int num_layers, int layers[num_layers], int bias, int activation, char * filename, int line);

// game initialization
void init_game(Animal *wolf1, Animal *wolf2, Animal *rabbit, Game *game, int rounds, int score, int size, int turns, int num_exits, float move_thresh);
void update_game(Game *game);
void print_game(Game *game);
void start_game(Game *game);
void get_inputs(Game *game, float pos[], float inputs[20]);

// game running
void rabbit_turn(Game *game, float new_pos[2]);
void wolf1_turn(Game *game, float new_pos[2]);
void wolf2_turn(Game *game, float new_pos[2]);
void run_rabbit(Game *game, float new_pos[2], float score[2]);
void run_wolf1(Game *game, float new_pos[2], float score[2]);
void run_wolf2(Game *game, float new_pos[2], float score[2]);

// helper functions
int check_pos(Game *game, float pos[2], int val);
float dist(float p1[], float p2[]);
float angle(float p1[], float p2[]);

#endif /* GAME_H_ */
























