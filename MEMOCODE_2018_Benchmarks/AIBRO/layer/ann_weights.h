
// Weights per layer
#define A_LAYER1    12
#define A_LAYER2    12

#define B_LAYER1    15
#define B_LAYER2    8

#define C_LAYER1    24
#define C_LAYER2    10

// Neurons per layer
#define A_NEURONS1  3
#define A_NEURONS2  3
#define A_NEURONS3  3

#define B_NEURONS1  4
#define B_NEURONS2  3
#define B_NEURONS3  2

#define C_NEURONS1  5
#define C_NEURONS2  4
#define C_NEURONS3  2

// Weight array declarations
fix16_t A_weights[2][A_LAYER1] = {{72796, -167044, -102358, -73407, -149804, 86195, -97406, -42439, -42153, 80573, 60748, 98356},
{-81805, -18131, -118765, -148142, -30916, 24672, -31510, -153603, -33026, -78855, -19661, -7254}};

fix16_t B_weights[2][B_LAYER1] = {{91847, 91815, 14605, 13587, -2914, -2876, 101020, 101476, 63846, 63934, -6962, -4020, 88023, 89521, 57526},
{122427, -20464, 46438, 24924, 138115, -23710, 16358, 13746}};

fix16_t C_weights[2][C_LAYER1] = {{152678, -54703, 116307, 3261, 41025, -59556, 60233, -52324, -116607, 42960, 142483, 136027, -49904, 7697, -13360, -38906, -3902, 95952, 3163, -107486, 50778, -183827, 74461, -139334},
{131163, 4783, 132667, -115150, 127079, -146405, 125317, 56381, 27721, 43101}};