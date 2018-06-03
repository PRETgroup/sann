/*
 * adder.h
 *
 *  Created on: Feb 26, 2018
 *      Author: keyan
 */

#ifndef AIBRO_H_
#define AIBRO_H_

#include <stdio.h>
#include <time.h>
#include "rnn_fixed.h"
#include "main.h"

void init();

void runLetterLayer1(int input1, int input2, int input3, int input4); 
void runLetterLayer2();

int getLetter();

#endif /* ADDER_H_ */
