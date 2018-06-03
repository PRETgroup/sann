// #include "ann_fixed.h"
// #include "ann_weights.h"
#include "main.h"

// Declaration of Esterel "aibro.c" input functions
void aibro_I_start();
void aibro_I_A();
void aibro_I_B();
void aibro_I_front1(int input);
void aibro_I_front2(int input);
void aibro_I_front3(int input);
void aibro_I_side1(int input);
void aibro_I_side2(int input);
void aibro_I_side3(int input);
void aibro_I_side4(int input);

int aibro();

// Esterel output implementation
void aibro_O_O(int out)
{
    char actions[4][8] = {{"FORWARD"}, {"RIGHT"}, {"LEFT"}, {"STOP"}};
    // printf("Best course of action: %s\n", actions[out]);
}

int main(){
    // init();
    // main loop to run the Esterel implementation
    int i;
#pragma loopbound min 0 max 200
    for(i = 0; i < 200; i++)
    {
        // printf("Tick %d -> START\n", i);
        // if(i == 1)
        // {
        //     aibro_I_start();
        // }
        // else
        // {
        //     int count  = 1;
        //     if(i == 195)
        //     {
        //         printf("Calling signal A\n");
        //         aibro_I_A();
        //         aibro_I_front1(-1);
        //         aibro_I_front2(1);
        //         aibro_I_front3(-1);
        //     }
        //     if(i == 196)
        //     {
        //         printf("Calling signal B\n");
        //         aibro_I_B();
        //         aibro_I_side1(-1);
        //         aibro_I_side2(-1);
        //         aibro_I_side3(1);
        //         aibro_I_side4(1);
        //     }
        //     if(i == 197)
        //     {
        //         aibro_I_front1(-1);
        //         aibro_I_front2(-1);
        //         aibro_I_front3(-1);

        //         aibro_I_side1(-1);
        //         aibro_I_side2(-1);
        //         aibro_I_side3(-1);
        //         aibro_I_side4(-1);
        //     }
        //     if(i == 199)
        //     {
        //         printf("Calling signal A\n");
        //         aibro_I_A();
        //         printf("Calling signal B\n");
        //         aibro_I_B();
        //     }
        // }
        aibro();
        // printf("Tick %d -> END\n\n", i);
    }
    return 0;
}