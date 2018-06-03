#include "main.h"
#include "inputs.h"

int ev();
void ev_I_price(float);
void ev_I_demand(float);
void init();

int main(){
    init();

    int i;
    for(i = 0; i < 100; i++)
    {
        if(i > 0 && i%3 == 0)
        {
            // printf("Tick: %d\n", i/3);
            ev_I_price(priceInput[i/3]);
            ev_I_demand(demandInput[i/3]);
            // printf("End tick\n");
        }
        ev();
    }

    return 0;
}

void ev_O_watts(float watts){
    // printf("Watts out: %f\n", watts);
}

