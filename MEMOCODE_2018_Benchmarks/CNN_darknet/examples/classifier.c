#include "darknet.h"

#include <sys/time.h>
#include <assert.h>

void predict_classifier(char *datacfg, char *cfgfile, char *weightfile, char *filename, int top)
{
printf("======= Starting prediction process =======\n\n");
    network *net = load_network(cfgfile, weightfile, 0);
    set_batch_network(net, 1);
    srand(2222222);

    list *options = read_data_cfg(datacfg);

    char *name_list = option_find_str(options, "names", 0);
    if(!name_list) name_list = option_find_str(options, "labels", "data/labels.list");
    if(top == 0) top = option_find_int(options, "top", 1);

    int i = 0;
    char **names = get_labels(name_list);
    clock_t time;
    int *indexes = calloc(top, sizeof(int));
    char buff[256];
    char *input = buff;
    if(filename){
        strncpy(input, filename, 256);
    }
    image im = load_image_color(input, 0, 0);
    image r = letterbox_image(im, net->w, net->h);
    //image r = resize_min(im, 320);
    //printf("%d %d\n", r.w, r.h);
    //resize_network(net, r.w, r.h);
    //printf("%d %d\n", r.w, r.h);

    float *X = r.data;
    time=clock();
    float *predictions = network_predict(net, X);
    if(net->hierarchy) hierarchy_predictions(predictions, net->outputs, net->hierarchy, 1, 1);
    top_k(predictions, net->outputs, top, indexes);
    fprintf(stderr, "%s: Predicted in %f seconds.\n", input, sec(clock()-time));
    for(i = 0; i < top; ++i){
        int index = indexes[i];
        //if(net->hierarchy) printf("%d, %s: %f, parent: %s \n",index, names[index], predictions[index], (net->hierarchy->parent[index] >= 0) ? names[net->hierarchy->parent[index]] : "Root");
        //else printf("%s: %f\n",names[index], predictions[index]);
        printf("%5.2f%%: %s\n", predictions[index]*100, names[index]);
    }
    if(r.data != im.data) free_image(r);
    free_image(im);
printf("\n======= Ending prediction process =======\n");
}

void run_classifier(int argc, char **argv)
{
    int top = find_int_arg(argc, argv, "-t", 0);
    char *data = "cfg/imagenet1k.data";
    char *cfg = "cfg/darknet.cfg";
    char *weights = "darknet.weights";
    char *filename = argv[1];
    predict_classifier(data, cfg, weights, filename, top);
}


