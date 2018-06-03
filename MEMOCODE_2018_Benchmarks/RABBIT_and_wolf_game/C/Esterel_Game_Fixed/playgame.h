/*
 * playgame.h
 *
 *  Created on: Mar 12, 2018
 *      Author: keyan
 */

#ifndef PLAYGAME_H_
#define PLAYGAME_H_

#include "game.h"
#include "main.h"

#define P 2
#define SIZE 10

void runWolf1ANN(int index);

void init();

void rabbit_decide();
void wolf1_decide();
void wolf2_decide();

// animal move functions
void rabbit_move();
void wolf1_move();
void wolf2_move();

int check_score();

#endif /* PLAYGAME_H_ */

