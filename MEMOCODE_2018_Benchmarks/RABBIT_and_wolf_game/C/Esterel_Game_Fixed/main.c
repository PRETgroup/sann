#include "main.h"

int playgame();
void init();

int main()
{
    init();
    for(int i = 0; i < 1000; i++)
    {
        // printf("Tick: %d\n", i);
        runWolf1ANN(i);
    }
    printf("\n");

    return 0;
}