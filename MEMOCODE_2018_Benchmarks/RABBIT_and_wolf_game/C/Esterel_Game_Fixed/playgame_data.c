#include "playgame.h"
// #include "game.c"
// #include "ann.c"

#define FIXED_ONE 65536

// initialization
Game p_game;
Animal p_wolf1;
Animal p_wolf2;
Animal p_rabbit;
ANN_F w1_ann;
ANN_F w2_ann;
ANN_F r_ann;

Game *this_game = &p_game;
Animal *this_wolf1 = &p_wolf1;
Animal *this_wolf2 = &p_wolf2;
Animal *this_rabbit = &p_rabbit;

int r_pos[2];
int w1_pos[2];
int w2_pos[2];

int r_newpos[2];
int w1_newpos[2];
int w2_newpos[2];

int score[2];

void runWolf1ANN(int index)
{
	testWolfANN(index, this_wolf1->ann);
}

// init function
void init()
{
	// printf("<====== Initializing system ======>\n");

	this_wolf1->ann = &w1_ann;
	this_wolf2->ann = &w2_ann;
	this_rabbit->ann = &r_ann;

	int pos[2] = {0, 0};
	int num_layers = 3;
	int bias = 1;
	int activation[2] = {0, 0};
	int w_layers[3] = {20, 30, 8};
	int r_layers[3] = {20, 24, 4};
	init_animal(this_rabbit, 0, pos, 9679, num_layers, r_layers, bias, activation, 0);
	init_animal(this_wolf1, 0, pos, 9650, num_layers, w_layers, bias, activation, 1);
	init_animal(this_wolf2, 0, pos, 9660, num_layers, w_layers, bias, activation, 2);

	int rounds = 1;
	int score = 0;
	int size = 10;
	int turns = 10;
	int num_exits = 3;
	fix16_t move_thresh = fix16_from_float(0.1);
	init_game(this_wolf1, this_wolf2, this_rabbit, this_game, rounds, score, size, turns, num_exits, move_thresh);
}

void rabbit_decide()
{
	// printf("\nRabbit is deciding its move\n");
	rabbit_turn(this_game, r_newpos);
}
void wolf1_decide()
{
	// printf("Wolf 1 is deciding its move\n");
	wolf1_turn(this_game, w1_newpos);
}
void wolf2_decide()
{
	// printf("Wolf 2 is deciding its move\n");
	wolf2_turn(this_game, w2_newpos);
}

// animal move functions
void rabbit_move()
{
	// printf("Moving rabbit\n");
	run_rabbit(this_game, r_newpos, score);
	update_game(this_game);
	// print_game(this_game);
}
void wolf1_move()
{
	// printf("Moving wolf 1\n");
	run_wolf1(this_game, w1_newpos, score);
	update_game(this_game);
	// print_game(this_game);
}
void wolf2_move()
{
	// printf("Moving wolf 2\n");
	run_wolf2(this_game, w2_newpos, score);
	update_game(this_game);
	// print_game(this_game);
}

int check_score()
{
	// printf("Checking for end game conditions\n");
	if(score[0] != 0 || score[1] != 0)
	{
		// if(score[0] == 1)
		// 	printf("Wolves scored!\n");
		// if(score[1] == 1)
		// 	printf("Rabbit scored!\n");
		// if(score[1] == -1)
		// 	printf("Rabbit was penalized\n");
		return 1;
	}
	// printf("No one scored...\n");
	return 0;
}















