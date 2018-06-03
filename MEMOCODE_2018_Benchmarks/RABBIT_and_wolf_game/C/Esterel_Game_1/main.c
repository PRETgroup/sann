#include "main.h"

void playgame_I_start();
int playgame();

int main()
{
    for(int i = 0; i < 21; i++)
    {
        printf("Tick: %d\n", i);
        if(i == 1)
        {
            playgame_I_start();
        }
        playgame();
    }

    return 0;
}