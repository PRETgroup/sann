
#define LAYER1    20
#define LAYER3    20
#define LAYER2    16  // recurrent layer

#define NEURONS1  4
#define NEURONS2  4
#define NEURONS3  4

#define MAX_HIDDEN 4

int neurons[3] = {NEURONS1, NEURONS2, NEURONS3};
 
fix16_t weights[3][LAYER1] = {
{4709, 53928, -45382, -24944, -15499, 9374, -78140, 89213, -16422, -28190, -12925, -44432, -1546, -104395, 122211, -29744, -51769, 10450, -89296, 7318}, 
{34809, -40838, 26408, -46757, 9274, 113993, 9284, -46910, 80598, -8150, 49484, 6723, 91, -82717, 32532, 109922, -39353, -14925, -74091, -28196},
{37271, 5477, 10908, -53030, -45151, 132700, 25389, 145652, 33798, -16320, 23214, 19946, 40971, -19835, 40789, -41482}
};