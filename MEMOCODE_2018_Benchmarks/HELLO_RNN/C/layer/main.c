// #include "ann_fixed.h"
// #include "ann_weights.h"
#include "main.h"

// Declaration of Esterel "aibro.c" input functions
void hello_I_bit1(int input);
void hello_I_bit2(int input);
void hello_I_bit3(int input);
void hello_I_bit4(int input);

int hello();

// Esterel output implementation
char letters[4] = {'O', 'L', 'H', 'E'};
int last_out;
void hello_O_letter(int out)
{
    last_out = out;
    // printf("Output out is: %c\n", letters[out]);
}

int main(){
    init();
    // main loop to run the Esterel implementation
    for(int i = 0; i < 20; i++)
    {
        // printf("Tick %d -> START\n", i);
        if(i == 2)
        {
            hello_I_bit1(0);
            hello_I_bit2(0); 
            hello_I_bit3(1);
            hello_I_bit4(0);
        }
        if(i == 5)
        {
            int bits[4] = {0, 0, 0, 0};
            bits[last_out] = 1;
            hello_I_bit1(bits[0]);
            hello_I_bit2(bits[0]); 
            hello_I_bit3(bits[0]);
            hello_I_bit4(bits[0]);
        }
        if(i == 8)
        {
            int bits[4] = {0, 0, 0, 0};
            bits[last_out] = 1;
            hello_I_bit1(bits[0]);
            hello_I_bit2(bits[0]); 
            hello_I_bit3(bits[0]);
            hello_I_bit4(bits[0]);
        }
        if(i == 11)
        {
            int bits[4] = {0, 0, 0, 0};
            bits[last_out] = 1;
            hello_I_bit1(bits[0]);
            hello_I_bit2(bits[0]); 
            hello_I_bit3(bits[0]);
            hello_I_bit4(bits[0]);
        }
        hello();
        // printf("Tick %d -> END\n\n", i);
    }

    return 0;
}