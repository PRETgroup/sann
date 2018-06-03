#include "ann_fixed.h"
#include "main.h"

int main(){
    srand(time(NULL));
    //train ANN A
    ANN_F floatXOR;
    ANN_F * XORF = &floatXOR;

    // ANN_F tempA;
    // ANN_F * A = &tempA;

    int num_layers = 3;
    int layers[3] = {2, 2, 1};
    int bias = 1;
    int activation[2] = {1, 1};

    // ann_init(AF, num_layers, layers, bias, activation);

    // ann_train_batch(AF, "trainA.txt", 1000, 0.001, 1);

    // ann_init_float(AF, A);

    ann_init_fixed(XORF, num_layers, layers, bias, activation);

    fix16_t trainData[4][4] = {
    {65536, 65536, -65536},
    {65536, -65536, 65536},
    {-65536, 65536, 65536},
    {-65536, -65536, -65536}};

    ann_train_online_fixed(XORF, 0, 4, trainData, 1000, 0.01, 1);

    fix16_t inputs[4][2] = {{65536, 65536}, {65536, -65536}, {-65536, 65536}, {-65536, -65536}};
    fix16_t output[1];

    int i;
    for(i = 0; i < 4; i++)
    {
        ann_run_fixed(inputs[i], output, XORF);
        printf("%d XOR %d = %f\n", fix16_to_int(inputs[i][0]), fix16_to_int(inputs[i][1]), fix16_to_float(output[0]));
        printf("%d XOR %d = %d\n", fix16_to_int(inputs[i][0]), fix16_to_int(inputs[i][1]), fix16_to_int(output[0]));
    }

    //ann_save_to_file_fixed(A, "ANN_A.net");

    // int i, j, num_weights;
    // INIT_ANN_CUSTOM_FIXED(A, num_layers, layers, A_weights, bias, activation, i, j, num_weights, A_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    return 0;
}