// #include "ann_fixed.h"
// #include "ann_weights.h"
#include "main.h"

// Declaration of Esterel "aibro.c" input functions
void aibro_I_start();
void aibro_I_A();
void aibro_I_B();
void aibro_I_R();
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
    printf("Best course of action: %s\n", actions[out]);
}

int main(){
    init();
    // main loop to run the Esterel implementation
    for(int i = 0; i < 10; i++)
    {
        printf("Tick %d -> START\n", i);
        if(i == 1)
        {
            aibro_I_start();
        }
        else
        {
            if(i == 2)
            {
                printf("Calling signal R\n");
                aibro_I_R();
            }
            if(i == 4)
            {
                printf("Calling signal A\n");
                aibro_I_A();
                aibro_I_front1(-1);
                aibro_I_front2(1);
                aibro_I_front3(-1);
            }
            if(i == 5)
            {
                printf("Calling signal B\n");
                aibro_I_B();
                aibro_I_side1(-1);
                aibro_I_side2(-1);
                aibro_I_side3(1);
                aibro_I_side4(1);
            }
            if(i == 6)
            {
                printf("Calling signal R\n");
                aibro_I_R();
            }
            if(i == 8)
            {
                aibro_I_front1(-1);
                aibro_I_front2(-1);
                aibro_I_front3(-1);
                aibro_I_side1(-1);
                aibro_I_side2(-1);
                aibro_I_side3(-1);
                aibro_I_side4(-1);
                printf("Calling signal A\n");
                aibro_I_A();
                printf("Calling signal B\n");
                aibro_I_B();
            }
        }
        aibro();
        printf("Tick %d -> END\n\n", i);
    }

    //train ANN A
    // ANN floatA;
    // ANN * AF = &floatA;

    // ANN_F tempA;
    // ANN_F * A = &tempA;

    // int num_layers = 3;
    // int layers[3] = {3, 3, 3};
    // int bias = 1;
    // int activation[2] = {1, 1};

    // ann_init(AF, num_layers, layers, bias, activation);

    // ann_train_batch(AF, "trainA.txt", 1000, 0.001, 1);

    // ann_init_float(AF, A);

    // ann_init_fixed(A, num_layers, layers, bias, activation);

    // fix16_t trainData[8][10] = {{-65536, -65536, -65536, -65536, -65536, -65536},{-65536, -65536, 65536, -65536, -65536, -65536},{-65536, 65536, -65536, -65536, 65536, 65536},{-65536, 65536, 65536, -65536, 65536, -65536},{65536, -65536, -65536, -65536, -65536, -65536},{65536, -65536, 65536, -65536, -65536, -65536},{65536, 65536, -65536, -65536, -65536, 65536},{65536, 65536, 65536, 65536, 65536, 65536}};

    // ann_train_online_fixed(A, 8, trainData, 1000, 0.01, 1);

    // //ann_save_to_file_fixed(A, "ANN_A.net");

    // // int i, j, num_weights;
    // // INIT_ANN_CUSTOM_FIXED(A, num_layers, layers, A_weights, bias, activation, i, j, num_weights, A_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)


    // fix16_t inputs[3];
    // fix16_t outputs[3];
    // int i, j, k;
    // for(i = 0; i < 2; i++)
    // {
    //     for(j = 0; j < 2; j++)
    //     {
    //         for(k = 0; k < 2; k++)
    //         {
    //             inputs[0] = fix16_from_int(i > 0 ? 1 : -1);
    //             inputs[1] = fix16_from_int(j > 0 ? 1 : -1);
    //             inputs[2] = fix16_from_int(k > 0 ? 1 : -1);

    //             ann_run_fixed(inputs, outputs, A);

    //             printf("[%d %d %d] -> [%f %f %f]\n", fix16_to_int(inputs[0]), fix16_to_int(inputs[1]), fix16_to_int(inputs[2]), 
    //             fix16_to_float(outputs[0]), fix16_to_float(outputs[1]), fix16_to_float(outputs[2]));
    //         }   
    //     }
    // }

    //ann_print_fixed(A, inputs, 1);


    // training data for ANNs
    // printf("fix16_t trainData[8][10] = {{%d, %d, %d, %d, %d, %d},", 
    // fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //000
    // printf("{%d, %d, %d, %d, %d, %d},", 
    // fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //001
    // printf("{%d, %d, %d, %d, %d, %d},", 
    // fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(1)); //010
    // printf("{%d, %d, %d, %d, %d, %d},", 
    // fix16_from_int(-1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1)); //011
    // printf("{%d, %d, %d, %d, %d, %d},",  
    // fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //100
    // printf("{%d, %d, %d, %d, %d, %d},", 
    // fix16_from_int(1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //101
    // printf("{%d, %d, %d, %d, %d, %d},", 
    // fix16_from_int(1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(1)); //110
    // printf("{%d, %d, %d, %d, %d, %d}}\n", 
    // fix16_from_int(1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(1)); //111
    // printf("\n");
    // printf("%d %d %d %d %d %d\n", 
    // fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //000
    // printf("%d %d %d %d %d %d\n", 
    // fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //001
    // printf("%d %d %d %d %d %d\n", 
    // fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(1)); //010
    // printf("%d %d %d %d %d %d\n", 
    // fix16_from_int(-1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1)); //011
    // printf("%d %d %d %d %d %d\n",  
    // fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //100
    // printf("%d %d %d %d %d %d\n", 
    // fix16_from_int(1), fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)); //101
    // printf("%d %d %d %d %d %d\n", 
    // fix16_from_int(1), fix16_from_int(1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(1)); //110
    // printf("%d %d %d %d %d %d\n", 
    // fix16_from_int(1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(1), fix16_from_int(1)); //111
    // printf("\n");


    // train ANN B
    // int i, j, k, l, num_weights;
    // ANN floatB;
    // ANN * BF = &floatB;

    // ANN_F tempB;
    // ANN_F * B = &tempB;

    // int num_layers = 3;
    // int layers[3] = {4, 3, 2};
    // int bias = 1;
    // int activation[2] = {1, 1};

    // ann_init(BF, num_layers, layers, bias, activation);

    // ann_train_batch(BF, "trainB.txt", 1000, 0.001, 1);

    // ann_init_float(BF, B);

    // ann_save_to_file_fixed(B, "ANN_B.net");

    // INIT_ANN_CUSTOM_FIXED(B, num_layers, layers, B_weights, bias, activation, i, j, num_weights, B_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)


    // fix16_t inputs[4];
    // fix16_t outputs[2];
    // for(i = 0; i < 2; i++)
    // {
    //     for(j = 0; j < 2; j++)
    //     {
    //         for(k = 0; k < 2; k++)
    //         {
    //             for(l = 0; l < 2; l++)
    //             {
    //                 inputs[0] = fix16_from_int(i > 0 ? 1 : -1);
    //                 inputs[1] = fix16_from_int(j > 0 ? 1 : -1);
    //                 inputs[2] = fix16_from_int(k > 0 ? 1 : -1);
    //                 inputs[3] = fix16_from_int(l > 0 ? 1 : -1);

    //                 ann_run_fixed(inputs, outputs, B);

    //                 printf("[%d %d %d %d] -> [%f %f]\n", fix16_to_int(inputs[0]), fix16_to_int(inputs[1]), fix16_to_int(inputs[2]), fix16_to_int(inputs[3]),
    //                 fix16_to_float(outputs[0]), fix16_to_float(outputs[1]));
    //             }
    //         }   
    //     }
    // }

    // for(i = 0; i < 2; i++)
    // {
    //     for(j = 0; j < 2; j++)
    //     {
    //         for(k = 0; k < 2; k++)
    //         {
    //             for(l = 0; l < 2; l++)
    //             {
    //                 if(i == 0 && j == 0 && k == 0 && l == 0)
    //                     printf("%d %d %d %d %d %d\n", -1, -1, -1, -1, -1, -1);
    //                 else if(i == 0 && j == 0)
    //                     printf("%d %d %d %d %d %d\n", -1, -1, k > 0 ? 1 : -1, l > 0 ? 1 : -1, -1, 1);
    //                 else if(k == 0 && l == 0)
    //                     printf("%d %d %d %d %d %d\n", i > 0 ? 1 : -1, j > 0 ? 1 : -1, -1, -1, 1, -1);
    //                 else 
    //                     printf("%d %d %d %d %d %d\n", i > 0 ? 1 : -1, j > 0 ? 1 : -1, k > 0 ? 1 : -1, l > 0 ? 1 : -1, 1, 1);
    //             }
    //         }
    //     }
    // }


    // train ANN c

    // int i, j, k, l, m, num_weights;
    // ANN floatC;
    // ANN * CF = &floatC;

    // ANN_F tempC;
    // ANN_F * C = &tempC; 

    // int num_layers = 3;
    // int layers[3] = {5, 4, 2};
    // int bias = 1;
    // int activation[2] = {1, 1};

    // ann_init(CF, num_layers, layers, bias, activation);

    // ann_train_batch(CF, "trainC.txt", 1000, 0.001, 1);

    // ann_init_float(CF, C);

    // ann_save_to_file_fixed(C, "ANN_C.net");

    // INIT_ANN_CUSTOM_FIXED(C, num_layers, layers, C_weights, bias, activation, i, j, num_weights, C_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    // fix16_t inputs[5];
    // fix16_t outputs[2];
    // for(i = 0; i < 2; i++)
    // {
    //     for(j = 0; j < 2; j++)
    //     {
    //         for(k = 0; k < 2; k++)
    //         {
    //             for(l = 0; l < 2; l++)
    //             {
    //                 for(m = 0; m < 2; m++)
    //                 {
    //                     inputs[0] = fix16_from_int(i > 0 ? 1 : -1);
    //                     inputs[1] = fix16_from_int(j > 0 ? 1 : -1);
    //                     inputs[2] = fix16_from_int(k > 0 ? 1 : -1);
    //                     inputs[3] = fix16_from_int(l > 0 ? 1 : -1);
    //                     inputs[4] = fix16_from_int(m > 0 ? 1 : -1);

    //                     ann_run_fixed(inputs, outputs, C);

    //                     printf("[%d %d %d %d %d] -> [%f %f]\n", fix16_to_int(inputs[0]), fix16_to_int(inputs[1]), fix16_to_int(inputs[2]), 
    //                     fix16_to_int(inputs[3]), fix16_to_int(inputs[4]), fix16_to_float(outputs[0]), fix16_to_float(outputs[1]));
    //                 }
    //             }
    //         }   
    //     }
    // }

    // INIT_ANN_CUSTOM_FIXED(B, num_layers, layers, B_weights, bias, activation, i, j, num_weights, B_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    // for(i = 0; i < 2; i++)
    // {
    //     for(j = 0; j < 2; j++)
    //     {
    //         for(k = 0; k < 2; k++)
    //         {
    //             for(l = 0; l < 2; l++)
    //             {
    //                 for(m = 0; m < 2; m++)
    //                 {
    //                     printf("%d %d %d %d %d ", i > 0 ? 1 : -1, j > 0 ? 1 : -1, k > 0 ? 1 : -1, l > 0 ? 1 : -1, m > 0 ? 1 : -1);
    //                     if(i == 0 && j == 0 && k == 0)
    //                         printf("%d %d\n", -1, -1);
    //                     else if(i == 0 && j == 0)
    //                         if(m == 1)
    //                             printf("%d %d\n", 1, 1);
    //                         else 
    //                             printf("%d %d\n", -1, 1);
    //                     else if(i == 0 && k == 0)
    //                         if(l == 1)
    //                             printf("%d %d\n", 1, 1);
    //                         else 
    //                             printf("%d %d\n", 1, -1);
    //                     else if(i == 0)
    //                         if(m == 0)
    //                             printf("%d %d\n", -1, 1);
    //                         else if(l == 0)
    //                             printf("%d %d\n", 1, -1);
    //                         else 
    //                             printf("%d %d\n", 1, 1);
    //                     else 
    //                         printf("%d %d\n", 1, 1);
    //                 }
    //             }
    //         }
    //     }
    // }

    // int i, j, k, l, m, num_weights;
    // fix16_t weighted_sum = 0;

    // ANN_F tempA;
    // ANN_F * A = &tempA;
    // ANN_F tempB;
    // ANN_F * B = &tempB;
    // ANN_F tempC;
    // ANN_F * C = &tempC;

    // int layersA[3] = {3, 3, 3};
    // int layersB[3] = {4, 3, 2};
    // int layersC[3] = {5, 4, 2};

    // int num_layers = 3;
    // int bias = 1;
    // int activation[2] = {1, 1};

    // INIT_ANN_CUSTOM_FIXED(A, num_layers, layersA, A_weights, bias, activation, i, j, num_weights, A_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    // INIT_ANN_CUSTOM_FIXED(B, num_layers, layersB, B_weights, bias, activation, i, j, num_weights, B_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    // INIT_ANN_CUSTOM_FIXED(C, num_layers, layersC, C_weights, bias, activation, i, j, num_weights, C_LAYER1, MAX_LAYERS, MAX_LAYERS_LESS1)

    // fix16_t inputsA[3] = {fix16_from_int(-1), fix16_from_int(1), fix16_from_int(-1)};
    // fix16_t inputsB[4] = {fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1), fix16_from_int(-1)};

    // fix16_t outputsA[3];
    // fix16_t outputsB[2];
    // fix16_t outputsC[2];

    // RUN_ANN_FIXED(inputsA, outputsA, A, i, j, k, weighted_sum, 3, 2)
    // RUN_ANN_FIXED(inputsB, outputsB, B, i, j, k, weighted_sum, 4, 2)

    // fix16_t inputsC[5] = {outputsA[0], outputsA[1], outputsA[2], outputsB[0], outputsB[1]};

    // RUN_ANN_FIXED(inputsC, outputsC, C, i, j, k, weighted_sum, 5, 2)

    // printf("A out: [%f %f %f]\n", fix16_to_float(outputsA[0]), fix16_to_float(outputsA[1]), fix16_to_float(outputsA[2]));
    // printf("B out: [%f %f]\n", fix16_to_float(outputsB[0]), fix16_to_float(outputsB[1]));
    // printf("C out: [%f %f]\n", fix16_to_float(outputsC[0]), fix16_to_float(outputsC[1]));

    // printf("Decision: ");
    // if(outputsC[0] > 0 && outputsC[1] > 0)
    //     printf("STOP\n");
    // else if(outputsC[1] > 0)
    //     printf("TURN RIGHT\n");
    // else if(outputsC[0] > 0)
    //     printf("TURN LEFT\n");
    // else
    //     printf("CONTINUE STRAIGHT\n");

    return 0;
}