//#include "ann_fixed.h"
// #include "ann_weights.h"
#include "main.h"

// Declaration of Esterel functions
void aibro_I_A ();
void aibro_I_B ();
void aibro_I_front1 (int);
void aibro_I_front2 (int);
void aibro_I_front3 (int);
void aibro_I_side1 (int);
void aibro_I_side2 (int);
void aibro_I_side3 (int);
void aibro_I_side4 (int);
int aibro();

// Esterel output implementation
void aibro_O_outA1(int out)
{
    // printf("First A output: %f\n", fix16_to_float((fix16_t)out));
}
void aibro_O_outA2(int out)
{
    // printf("Second A output: %f\n", fix16_to_float((fix16_t)out));
}
void aibro_O_outA3(int out)
{
    // printf("Third A output: %f\n", fix16_to_float((fix16_t)out));
}

void aibro_O_outB1(int out)
{
    // printf("First B output: %f\n", fix16_to_float((fix16_t)out));
}
void aibro_O_outB2(int out)
{
    // printf("Second B output: %f\n", fix16_to_float((fix16_t)out));
}

void aibro_O_outC(int out)
{
    char actions[4][10] = {{"FORWARD"}, {"RIGHT"}, {"LEFT"}, {"STOP"} };
    // printf("Action is: %s\n", actions[out]);
}

int main()
{
    int i;
    for(i = 0; i < 20; i++)
    {
        // printf("Tick: %d\n", i);
        // if(i == 2)
        // {
        //     aibro_I_B ();  
        //     // printf("Inputs B\n");
        //     aibro_I_side1(65536);
        //     aibro_I_side2(-65536);
        //     aibro_I_side3(-65536);
        //     aibro_I_side4(-65536);
        // }
        // if(i == 3)
        // {
        //     aibro_I_A ();
        //     // printf("Inputs A\n");
        //     aibro_I_front1(65536);
        //     aibro_I_front2(65536);
        //     aibro_I_front3(65536);
        // }
        // if(i == 8)
        // {
        //     aibro_I_A ();
        //     // printf("Inputs A\n");
        //     aibro_I_front1(-65536);
        //     aibro_I_front2(-65536);
        //     aibro_I_front3(-65536);
        // }
        // if(i == 9)
        // {
        //     aibro_I_B ();
        //     // printf("Inputs B\n");
        //     aibro_I_side1(-65536);
        //     aibro_I_side2(65536);
        //     aibro_I_side3(-65536);
        //     aibro_I_side4(65536);
        // }
        // if(i == 14)
        // {
        //     aibro_I_A ();
        //     aibro_I_B ();
        //     // printf("Inputs A\n");
        //     // printf("Inputs B\n");
        //     aibro_I_front1(-65536);
        //     aibro_I_front2(65536);
        //     aibro_I_front3(-65536);
        //     aibro_I_side1(-65536);
        //     aibro_I_side2(-65536);
        //     aibro_I_side3(65536);
        //     aibro_I_side4(65536);
        // }
        aibro();
    }

    return 0;
}