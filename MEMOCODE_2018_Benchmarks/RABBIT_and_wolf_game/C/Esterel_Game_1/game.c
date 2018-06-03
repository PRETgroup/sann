/*
 * game.c
 *
 *  Created on: Mar 12, 2018
 *      Author: keyan
 */

#include "game.h"

// initialize the animal structure with ANN and map data
void init_animal(Animal *animal, int score, int pos[], int symbol, int num_layers, int layers[num_layers], int bias, int activation, char * filename, int line)
{
	ann_init_file(animal->ann, num_layers, layers, bias, activation, filename, line);
	animal->score = score;
	animal->pos[0] = pos[0];
	animal->pos[1] = pos[1];
	animal->old_pos[0] = pos[0];
	animal->old_pos[1] = pos[1];
	animal->symbol = symbol;
}

// initialize the game structure
void init_game(Animal *wolf1, Animal *wolf2, Animal *rabbit, Game *game, int rounds, int score, int size, int turns, int num_exits, float move_thresh)
{
	srand(time(NULL));

	// int x = 0;
	// int y = 0;
	// int i = 0;
	// int j = 0;

	if(score == 0)
		game->max_score = rounds;
	else
		game->max_score = score;
	if(size < MAX_BLOCKS)
		game->size = size;
	else
		game->size = MAX_BLOCKS;
	game->max_rounds = rounds;
	game->round = 0;
	game->turns = 0;
	game->score[0] = -1;
	game->score[1] = -1;
	game->num_exits = num_exits;
	game->move_thresh = move_thresh;
	game->max_turns = turns;

	game->rabbit = rabbit;
	game->wolf1 = wolf1;
	game->wolf2 = wolf2;

// 	// first initialize game board rabbit exits
// 	int corners[4][2] = {{0, 0}, {0, game->size - 1}, {game->size - 1, 0}, {game->size - 1, game->size - 1}};
// 	int hole[2];
// 	int flag = 0;

// 	for(i = 0; i < game->num_exits; i++)
// 	{
// 		do
// 		{
// 			hole[0] = rand()%(game->size - 1);
// 			hole[1] = rand()%(game->size - 1);
// 			flag = 0;
// 			for(j = 0; j < 4; j++)
// 			{
// 				if(corners[j][0] == hole[0] && corners[j][1] == hole[1])
// 				{
// 					flag = 1;
// 					break;
// 				}
// 			}
// 		}
// 		while(flag);

// 		game->exits[i][0] = hole[0];
// 		game->exits[i][1] = hole[1];
// 	}

// //	for(i = 0; i < game->num_exits; i++)
// //	{
// //		printf("Game exit %d: [%d, %d]\n", i, game->exits[i][0], game->exits[i][1]);
// //	}

// 	// then initialize the animals on the board
// 	// wolf 1
// 	do
// 	{
// 		x = rand()%(game->size - 3) + 1; // don't generate on walls
// 		y = rand()%(game->size - 3) + 1; // don't generate on walls

// 		flag = 0;
// 		for(i = 0; i < game->num_exits; i++)
// 		{
// 			if(game->exits[i][0] == x && game->exits[i][1] == y)
// 				flag = 1;
// 		}
// 	}
// 	while(flag);
// 	game->wolf1->score = 0;
// 	game->wolf1->pos[0] = x;
// 	game->wolf1->pos[1] = y;
// 	game->wolf1->old_pos[0] = x;
// 	game->wolf1->old_pos[1] = y;

// 	// wolf 2
// 	do
// 	{
// 		x = rand()%(game->size - 3) + 1; // don't generate on walls
// 		y = rand()%(game->size - 3) + 1; // don't generate on walls

// 		flag = 0;
// 		for(i = 0; i < game->num_exits; i++)
// 		{
// 			if((game->exits[i][0] == x && game->exits[i][1] == y) || (x == wolf1->pos[0] && y == wolf1->pos[1]))
// 				flag = 1;
// 		}
// 	}
// 	while(flag);
// 	game->wolf2->score = 0;
// 	game->wolf2->pos[0] = x;
// 	game->wolf2->pos[1] = y;
// 	game->wolf2->old_pos[0] = x;
// 	game->wolf2->old_pos[1] = y;

// 	// rabbit
// 	do
// 	{
// 		x = rand()%(game->size - 3) + 1; // don't generate on walls
// 		y = rand()%(game->size - 3) + 1; // don't generate on walls

// 		flag = 0;
// 		for(i = 0; i < game->num_exits; i++)
// 		{
// 			if((game->exits[i][0] == x && game->exits[i][1] == y) || (x == game->wolf1->pos[0] && y == game->wolf1->pos[1]) || (x == game->wolf2->pos[0] && y == game->wolf2->pos[1]))
// 				flag = 1;
// 		}
// 	}
// 	while(flag);
// 	game->rabbit->score = 0;
// 	game->rabbit->pos[0] = x;
// 	game->rabbit->pos[1] = y;
// 	game->rabbit->old_pos[0] = x;
// 	game->rabbit->old_pos[1] = y;

// 	// update game state with exits and animals
// 	update_game(game);

	int new_state[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 0, 0, 0, 0, 4, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 2, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 5, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 3, 0, 0, 0, 0, 0, 1},
    {1, 0, 2, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int exit_count = 0;
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			game->state[i][j] = new_state[i][j];
			if(new_state[i][j] == 3)
			{
				game->wolf1->pos[0] = i;
				game->wolf1->pos[1] = j;
				game->wolf1->old_pos[0] = i;
				game->wolf1->old_pos[1] = j;
			}
			if(new_state[i][j] == 4)
			{
				game->wolf2->pos[0] = i;
				game->wolf2->pos[1] = j;
				game->wolf2->old_pos[0] = i;
				game->wolf2->old_pos[1] = j;
			}
			if(new_state[i][j] == 5)
			{
				game->rabbit->pos[0] = i;
				game->rabbit->pos[1] = j;
				game->rabbit->old_pos[0] = i;
				game->rabbit->old_pos[1] = j;
			}
			if(new_state[i][j] == 2)
			{
				game->exits[exit_count][0] = i;
				game->exits[exit_count][1] = j;
				exit_count++;
			}
		}
	}

	print_game(game);

	game->rabbit->score = 0;
	game->wolf1->score = 0;
	game->wolf2->score = 0;
}

// update changed positions on game state
void update_game(Game *game)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;

	for(i = 0; i < game->size; i++)
	{
		for(j = 0; j < game->size; j++)
		{
			flag = 0;
			for(k = 0; k < game->num_exits; k++)
			{
				if(game->exits[k][0] == i && game->exits[k][1] == j)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				game->state[i][j] = 2;
			else if(i == 0 || j == 0 || i == game->size - 1 || j == game->size - 1)
				game->state[i][j] = 1;
			else if(i == game->wolf1->pos[0] && j == game->wolf1->pos[1])
				game->state[i][j] = 3;
			else if(i == game->wolf2->pos[0] && j == game->wolf2->pos[1])
				game->state[i][j] = 4;
			else if(i == game->rabbit->pos[0] && j == game->rabbit->pos[1])
				game->state[i][j] = 5;
			else if(i == game->wolf1->old_pos[0] && j == game->wolf1->old_pos[1])
				game->state[i][j] = 6;
			else if(i == game->wolf2->old_pos[0] && j == game->wolf2->old_pos[1])
				game->state[i][j] = 7;
			else if(i == game->rabbit->old_pos[0] && j == game->rabbit->old_pos[1])
				game->state[i][j] = 8;
			else
				game->state[i][j] = 0;
		}
	}
}

// print game state to console
void print_game(Game *game)
{
	setlocale(LC_ALL, "");

	int i = 0;
	int j = 0;

//	for(j = 0; j < game->size; j++)
//	{
//		for(i = 0; i < game->size; i++)
//		{
//			printf("%d", game->state[i][game->size - 1 -j]);
//		}
//		printf("\n");
//	}

	for(j = 0; j < game->size; j++)
	{
		for(i = 0; i < game->size; i++)
		{
			switch(game->state[i][game->size - 1 -j])
			{
			case 0:
				printf("%lc  ", (wint_t)(9633));
				break;
			case 1:
				printf("%lc  ", (wint_t)(9632));
				break;
			case 2:
				printf("%lc  ", (wint_t)(9678));
				break;
			case 3:
				printf("%lc  ", (wint_t)(game->wolf1->symbol));
				break;
			case 4:
				printf("%lc  ", (wint_t)(game->wolf2->symbol));
				break;
			case 5:
				printf("%lc  ", (wint_t)(game->rabbit->symbol));
				break;
			case 6:
				printf("%lc  ", (wint_t)(9651));
				break;
			case 7:
				printf("%lc  ", (wint_t)(9661));
				break;
			case 8:
				printf("%lc  ", (wint_t)(9675));
				break;
			default:
				printf("%lc  ", (wint_t)(8265));
				break;
			}
		}
		printf("\n");
	}
}

// find the inputs of an animal depending on its location
void get_inputs(Game *game, float pos[], float inputs[20])
{
	int i = 0;
	int j = 0;

	// printf("Getting inputs for position: [%f, %f]\n", pos[0], pos[1]);

	float animals[3][2] = {{0, 0}, {0, 0}, {0, 0}};
	int animal_type = 0;
	float temp_pos[2] = {0, 0};

	for(i = 0; i < game->size; i++)
	{
		for(j = 0; j < game->size; j++)
		{
			// test if any animal is found on this point
			if(pos[0] == i && pos[1] == j)
			{
				animal_type = game->state[i][j];
			}
			else if(game->state[i][j] == 3)
			{
				temp_pos[0] = i;
				temp_pos[1] = j;
				animals[0][0] = dist(pos, temp_pos);
				animals[0][1] = angle(pos, temp_pos);
			}
			else if(game->state[i][j] == 4)
			{
				temp_pos[0] = i;
				temp_pos[1] = j;
				animals[1][0] = dist(pos, temp_pos);
				animals[1][1] = angle(pos, temp_pos);
			}
			else if(game->state[i][j] == 5)
			{
				temp_pos[0] = i;
				temp_pos[1] = j;
				animals[2][0] = dist(pos, temp_pos);
				animals[2][1] = angle(pos, temp_pos);
			}
		}
	}
	// add correct animals to inputs
	if(animal_type == 3)  // wolf 1
	{
		inputs[0] = animals[1][0];
		inputs[1] = animals[1][1];
		inputs[2] = animals[2][0];
		inputs[3] = animals[2][1];
	}
	if(animal_type == 4) // wolf 2
	{
		inputs[0] = animals[0][0];
		inputs[1] = animals[0][1];
		inputs[2] = animals[2][0];
		inputs[3] = animals[2][1];
	}
	if(animal_type == 5)  // rabbit
	{
		inputs[0] = animals[0][0];
		inputs[1] = animals[0][1];
		inputs[2] = animals[1][0];
		inputs[3] = animals[1][1];
	}

	// scan 8 directions for inputs
	for(i = 0; i < 8; i++)
	{
		int found_obs = 0;
		int found_exit = 0;
		int end = 0;
		int x = pos[0];
		int y = pos[1];
		float length = 0;

		int x_mod = 0;
		if(2 < i && i < 6)
			x_mod = -1;
		if(i < 2 || i == 7)
			x_mod = 1;
		int y_mod = 0;
		if(0 < i && i < 4)
			y_mod = 1;
		if(i > 4)
			y_mod = -1;

		while(!(found_obs && found_exit) && !end)
		{
			x += x_mod;
			y += y_mod;
			length += sqrt(pow(x_mod, 2) + pow(y_mod, 2));

            if(x < 0 || y < 0 || x > game->size - 1 || y > game->size - 1)  // outside game boundary
                break;
            if(x == 0 || y == 0 || x == game->size - 1 || y == game->size - 1)  // found game boundary
                end = 1;

            if(game->state[x][y] == 1)  // obstacle found
			{
                found_obs = 1;
                inputs[4 + i * 2] = 1.0 / length;
			}
            if(game->state[x][y] == 2)  // exit found
			{
                found_exit = 1;
                inputs[4 + i * 2 + 1] = 1.0 / length;
			}
		}
        if(!found_obs)
            inputs[4 + i * 2] = 0;
        if(!found_exit)
            inputs[4 + i * 2 + 1] = 0;
	}

	// printf("Inputs are: [");
	// for(int i = 0; i < 20; i++)
	// {
	// 	printf("%f ", inputs[i]);
	// }
	// printf("]\n");
}

// returns the position the rabbit decided to move to
void rabbit_turn(Game *game, float new_pos[2])
{
	float inputs[20] = {0};
	float outputs[4] = {0};

	get_inputs(game, game->rabbit->pos, inputs);  // get rabbit inputs
	ann_run(inputs, outputs, game->rabbit->ann);  // run rabbit ann

	// find rabbits new position
	int index = -1;
	float high = game->move_thresh;
	int i = 0;

	for(i = 0; i < 4; i++)
	{
		if(outputs[i] >= high)
		{
			high = outputs[i];
			index = i;
		}
	}

	if(index == -1)
	{
		new_pos[0] = game->rabbit->pos[0];
		new_pos[1] = game->rabbit->pos[1];
	}
	if(index == 0)
	{
		new_pos[0] = game->rabbit->pos[0] + 1;
		new_pos[1] = game->rabbit->pos[1];
	}
	if(index == 1)
	{
		new_pos[0] = game->rabbit->pos[0];
		new_pos[1] = game->rabbit->pos[1] + 1;
	}
	if(index == 2)
	{
		new_pos[0] = game->rabbit->pos[0] - 1;
		new_pos[1] = game->rabbit->pos[1];
	}
	if(index == 3)
	{
		new_pos[0] = game->rabbit->pos[0];
		new_pos[1] = game->rabbit->pos[1] - 1;
	}
}

// return the wolf1 position to move to
void wolf1_turn(Game *game, float new_pos[2])
{
	float inputs[20] = {0};
	float outputs[8] = {0};

	get_inputs(game, game->wolf1->pos, inputs);  // get wolf1 inputs
	ann_run(inputs, outputs, game->wolf1->ann);  // run wolf1 ann

	// find wolf1 new position
	int index = -1;
	float high = game->move_thresh;
	int i = 0;

	for(i = 0; i < 8; i++)
	{
		if(outputs[i] >= high)
		{
			high = outputs[i];
			index = i;
		}
	}

	if(index == -1)
	{
		new_pos[0] = game->wolf1->pos[0];
		new_pos[1] = game->wolf1->pos[1];
	}
	if(index == 0)
	{
		new_pos[0] = game->wolf1->pos[0] + 1;
		new_pos[1] = game->wolf1->pos[1];
	}
	if(index == 1)
	{
		new_pos[0] = game->wolf1->pos[0] + 1;
		new_pos[1] = game->wolf1->pos[1] + 1;
	}
	if(index == 2)
	{
		new_pos[0] = game->wolf1->pos[0];
		new_pos[1] = game->wolf1->pos[1] + 1;
	}
	if(index == 3)
	{
		new_pos[0] = game->wolf1->pos[0] - 1;
		new_pos[1] = game->wolf1->pos[1] + 1;
	}
	if(index == 4)
	{
		new_pos[0] = game->wolf1->pos[0] - 1;
		new_pos[1] = game->wolf1->pos[1];
	}
	if(index == 5)
	{
		new_pos[0] = game->wolf1->pos[0] - 1;
		new_pos[1] = game->wolf1->pos[1] - 1;
	}
	if(index == 6)
	{
		new_pos[0] = game->wolf1->pos[0];
		new_pos[1] = game->wolf1->pos[1] - 1;
	}
	if(index == 7)
	{
		new_pos[0] = game->wolf1->pos[0] + 1;
		new_pos[1] = game->wolf1->pos[1] - 1;
	}
}

// return the wolf2 position to move to
void wolf2_turn(Game *game, float new_pos[2])
{
	float inputs[20] = {0};
	float outputs[8] = {0};

	get_inputs(game, game->wolf2->pos, inputs);  // get wolf2 inputs
	ann_run(inputs, outputs, game->wolf2->ann);  // run wolf2 ann

	// find wolf2 new position
	int index = -1;
	float high = game->move_thresh;
	int i = 0;

	for(i = 0; i < 8; i++)
	{
		if(outputs[i] >= high)
		{
			high = outputs[i];
			index = i;
		}
	}

	if(index == -1)
	{
		new_pos[0] = game->wolf2->pos[0];
		new_pos[1] = game->wolf2->pos[1];
	}
	if(index == 0)
	{
		new_pos[0] = game->wolf2->pos[0] + 1;
		new_pos[1] = game->wolf2->pos[1];
	}
	if(index == 1)
	{
		new_pos[0] = game->wolf2->pos[0] + 1;
		new_pos[1] = game->wolf2->pos[1] + 1;
	}
	if(index == 2)
	{
		new_pos[0] = game->wolf2->pos[0];
		new_pos[1] = game->wolf2->pos[1] + 1;
	}
	if(index == 3)
	{
		new_pos[0] = game->wolf2->pos[0] - 1;
		new_pos[1] = game->wolf2->pos[1] + 1;
	}
	if(index == 4)
	{
		new_pos[0] = game->wolf2->pos[0] - 1;
		new_pos[1] = game->wolf2->pos[1];
	}
	if(index == 5)
	{
		new_pos[0] = game->wolf2->pos[0] - 1;
		new_pos[1] = game->wolf2->pos[1] - 1;
	}
	if(index == 6)
	{
		new_pos[0] = game->wolf2->pos[0];
		new_pos[1] = game->wolf2->pos[1] - 1;
	}
	if(index == 7)
	{
		new_pos[0] = game->wolf2->pos[0] + 1;
		new_pos[1] = game->wolf2->pos[1] - 1;
	}
}

// update game state with rabbit move and check victory conditions
void run_rabbit(Game *game, float new_pos[2], float score[2])
{
	score[0] = 0;
	score[1] = 0;

	if(!(new_pos[0] == game->rabbit->pos[0] && new_pos[1] == game->rabbit->pos[1]))
	{
		if(check_pos(game, new_pos, 2))  // check for exit
		{
			game->rabbit->score += 1;
			game->rabbit->old_pos[0] = game->rabbit->pos[0];
			game->rabbit->old_pos[1] = game->rabbit->pos[1];
			game->rabbit->pos[0] = new_pos[0];
			game->rabbit->pos[1] = new_pos[1];
			score[1] +=1 ;
		}
		if(check_pos(game, new_pos, 3) || check_pos(game, new_pos, 4))  // check for wolf1
		{
			game->rabbit->score -= 1;
			game->rabbit->old_pos[0] = game->rabbit->pos[0];
			game->rabbit->old_pos[1] = game->rabbit->pos[1];
			game->rabbit->pos[0] = new_pos[0];
			game->rabbit->pos[1] = new_pos[1];
			score[1] -=1 ;
		}
		if(check_pos(game, new_pos, 1))  // check for obstacle
		{
			game->rabbit->old_pos[0] = game->rabbit->pos[0];
			game->rabbit->old_pos[1] = game->rabbit->pos[1];
		}
		if(check_pos(game, new_pos, 0))  // check for empty space
		{
			game->rabbit->old_pos[0] = game->rabbit->pos[0];
			game->rabbit->old_pos[1] = game->rabbit->pos[1];
			game->rabbit->pos[0] = new_pos[0];
			game->rabbit->pos[1] = new_pos[1];
		}
	}
}

// update game state with wolf1 move and check victory conditions
void run_wolf1(Game *game, float new_pos[2], float score[2])
{
	score[0] = 0;
	score[1] = 0;

	if(!(new_pos[0] == game->wolf1->pos[0] && new_pos[1] == game->wolf1->pos[1]))
	{
		if(check_pos(game, new_pos, 5))  // check for rabbit
		{
			game->wolf1->score += 1;
			game->wolf1->old_pos[0] = game->wolf1->pos[0];
			game->wolf1->old_pos[1] = game->wolf1->pos[1];
			game->wolf1->pos[0] = new_pos[0];
			game->wolf1->pos[1] = new_pos[1];
			score[0] +=1 ;
		}
		if(check_pos(game, new_pos, 4) || check_pos(game, new_pos, 1) || check_pos(game, new_pos, 2))  // check for obstacle, rabbit hole or other wolf
		{
			game->wolf1->old_pos[0] = game->wolf1->pos[0];
			game->wolf1->old_pos[1] = game->wolf1->pos[1];
		}
		if(check_pos(game, new_pos, 0))  // check for empty space
		{
			game->wolf1->old_pos[0] = game->wolf1->pos[0];
			game->wolf1->old_pos[1] = game->wolf1->pos[1];
			game->wolf1->pos[0] = new_pos[0];
			game->wolf1->pos[1] = new_pos[1];
		}
	}
}

// update game state with wolf2 move and check victory conditions
void run_wolf2(Game *game, float new_pos[2], float score[2])
{
	score[0] = 0;
	score[1] = 0;

	if(!(new_pos[0] == game->wolf2->pos[0] && new_pos[1] == game->wolf2->pos[1]))
	{
		if(check_pos(game, new_pos, 5))  // check for rabbit
		{
			game->wolf2->score += 1;
			game->wolf2->old_pos[0] = game->wolf2->pos[0];
			game->wolf2->old_pos[1] = game->wolf2->pos[1];
			game->wolf2->pos[0] = new_pos[0];
			game->wolf2->pos[1] = new_pos[1];
			score[0] +=1 ;
		}
		if(check_pos(game, new_pos, 3) || check_pos(game, new_pos, 1) || check_pos(game, new_pos, 2))  // check for obstacle, rabbit hole or other wolf
		{
			game->wolf2->old_pos[0] = game->wolf2->pos[0];
			game->wolf2->old_pos[1] = game->wolf2->pos[1];
		}
		if(check_pos(game, new_pos, 0))  // check for empty space
		{
			game->wolf2->old_pos[0] = game->wolf2->pos[0];
			game->wolf2->old_pos[1] = game->wolf2->pos[1];
			game->wolf2->pos[0] = new_pos[0];
			game->wolf2->pos[1] = new_pos[1];
		}
	}
}

// checks the position in the game state for a certain numerical value
int check_pos(Game *game, float pos[2], int val)
{
	if(game->state[(int)(pos[0])][(int)(pos[1])] == val)
		return 1;
	return 0;
}

// return the distance between 2 points
float dist(float p1[], float p2[])
{
	float d = sqrt(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2));
	return 1/d;
}

// return the angle between two points
float angle(float p1[], float p2[])
{
	float angle = 0.0;
	float m = 0.0;

    if(p1[0] == p2[0])
    {
        if(p1[1] > p2[1])
            angle = 270.0;
        else
            angle = 90.0;
    }
    else
    {
        m = (float)(p1[1] - p2[1])/(float)(p1[0] - p2[0]);
        angle = atan(m)*180.0/PI;
        if(p1[0] > p2[0])
            angle += 180.0;
        if(-90 < angle && angle < 0)
            angle += 360.0;
    }

    return angle/360.0;
}















