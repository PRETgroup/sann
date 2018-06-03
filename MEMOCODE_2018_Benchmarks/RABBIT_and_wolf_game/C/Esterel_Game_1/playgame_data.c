#include "playgame.h"
// #include "game.c"
// #include "ann.c"

// initialization
Game p_game;
Animal p_wolf1;
Animal p_wolf2;
Animal p_rabbit;
ANN w1_ann;
ANN w2_ann;
ANN r_ann;

Game *this_game = &p_game;
Animal *this_wolf1 = &p_wolf1;
Animal *this_wolf2 = &p_wolf2;
Animal *this_rabbit = &p_rabbit;

float r_pos[2];
float w1_pos[2];
float w2_pos[2];

float r_newpos[2];
float w1_newpos[2];
float w2_newpos[2];

float score[2];

// init function
void init()
{
	printf("<====== Initializing system ======>\n");

	this_wolf1->ann = &w1_ann;
	this_wolf2->ann = &w2_ann;
	this_rabbit->ann = &r_ann;

	int pos[2] = {0, 0};
	int num_layers = 3;
	int bias = 1;
	int activation = 0;
	int w_layers[3] = {20, 30, 8};
	int r_layers[3] = {20, 24, 4};
	char * filename = "Attempt_2_100_50.txt";
	int line = 0;
	int r_line = line * (num_layers - 1) * 3;
	init_animal(this_rabbit, 0, pos, 9679, num_layers, r_layers, bias, activation, filename, r_line);
	init_animal(this_wolf1, 0, pos, 9650, num_layers, w_layers, bias, activation, filename, (r_line + num_layers - 1));
	init_animal(this_wolf2, 0, pos, 9660, num_layers, w_layers, bias, activation, filename, (r_line + 2 * (num_layers - 1)));

	// float r_inputs[20] = {0.35355339059327373, 0.875, 0.24253562503633297, 0.46101043481131532, 0.25, 0, 0.17677669529663687, 0, 0.25, 0, 0.17677669529663687, 0.23570226039551581, 0.20000000000000001, 0, 0.1414213562373095, 0.17677669529663687, 0.20000000000000001, 0, 0.17677669529663687, 0.23570226039551581};
	// ann_print(this_rabbit->ann, r_inputs, 0);
	// for(int i = 0; i < 20*24+24; i++)
	// {
	// 	printf("%f, ", this_rabbit->ann->weights[0][i]);
	// }
	// printf("\n");

	int rounds = 1;
	int score = 0;
	int size = 10;
	int turns = 10;
	int num_exits = 3;
	float move_thresh = 0.1;
	init_game(this_wolf1, this_wolf2, this_rabbit, this_game, rounds, score, size, turns, num_exits, move_thresh);
}

void rabbit_decide()
{
	printf("\nRabbit is deciding its move\n");
	rabbit_turn(this_game, r_newpos);
}
void wolf1_decide()
{
	printf("Wolf 1 is deciding its move\n");
	wolf1_turn(this_game, w1_newpos);
}
void wolf2_decide()
{
	printf("Wolf 2 is deciding its move\n");
	wolf2_turn(this_game, w2_newpos);
}

// animal move functions
void rabbit_move()
{
	printf("Moving rabbit\n");
	run_rabbit(this_game, r_newpos, score);
	update_game(this_game);
	print_game(this_game);
}
void wolf1_move()
{
	printf("Moving wolf 1\n");
	run_wolf1(this_game, w1_newpos, score);
	update_game(this_game);
	print_game(this_game);
}
void wolf2_move()
{
	printf("Moving wolf 2\n");
	run_wolf2(this_game, w2_newpos, score);
	update_game(this_game);
	print_game(this_game);
}

int check_score()
{
	printf("Checking for end game conditions\n");
	if(score[0] != 0 || score[1] != 0)
	{
		if(score[0] == 1)
			printf("Wolves scored!\n");
		if(score[1] == 1)
			printf("Rabbit scored!\n");
		if(score[1] == -1)
			printf("Rabbit was penalized\n");
		return 1;
	}
	printf("No one scored...\n");
	return 0;
}















