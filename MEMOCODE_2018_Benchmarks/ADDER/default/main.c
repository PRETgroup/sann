#include "main.h"
#include "ann_fixed.h"

int adder();
void adder_I_num1(int);
void adder_I_num2(int);
void adder_I_add();

void init();

int main()
{
    init();
    int i;
    for(i = 0; i < 10; i++)
    {
        if(i == 2)
        {
            adder_I_add();
            adder_I_num1(10000);
            adder_I_num2(20000);
        }
        if(i == 6)
        {
            adder_I_num1(30000);
            adder_I_num2(-5000);
        }
        if(i == 8)
        {
            adder_I_add();
        }
        adder();
    }

    return 0;
}

void adder_O_sum(int sum)
{
    // printf("Answer: %d\n", sum);
}