#include "av.h"
#include <string.h>

int top;
char filename[100];
network *net;
int *indexes;
char **names;
image im;
image r;
char *input;
network orig;
clock_t timeE;
int i;

void initE()
{
    printf("Loading the CNN data\n");
    top = 0;
    char *datacfg = "cfg/imagenet1k.data";
    char *cfgfile = "cfg/darknet.cfg";
    char *weightfile = "darknet.weights";

    net = load_network(cfgfile, weightfile, 0);
    set_batch_network(net, 1);
    srand(2222222);

    list *options = read_data_cfg(datacfg);

    char *name_list = option_find_str(options, "names", 0);
    if(!name_list) name_list = option_find_str(options, "labels", "data/labels.list");
    if(top == 0) top = option_find_int(options, "top", 1);

    i = 0;
    names = get_labels(name_list);
    indexes = calloc(top, sizeof(int));
    char buff[256];
    input = buff;
    strncpy(input, filename, 256);
    im = load_image_color(input, 0, 0);
    r = letterbox_image(im, net->w, net->h);
    //image r = resize_min(im, 320);
    //printf("%d %d\n", r.w, r.h);
    //resize_network(net, r.w, r.h);
    //printf("%d %d\n", r.w, r.h);
    timeE=clock();
    

    // set up network for forward propagation
    orig = *net;
    net->input = r.data;
    net->truth = 0;
    net->train = 0;
    net->delta = 0;

    i = 0;
}

void finishE()
{
    calc_network_cost(net);
    float *predictions = net->output;
    *net = orig;
    if(net->hierarchy) hierarchy_predictions(predictions, net->outputs, net->hierarchy, 1, 1);
    top_k(predictions, net->outputs, top, indexes);
    fprintf(stderr, "%s: Predicted in %f seconds.\n", input, sec(clock()-timeE));
    for(i = 0; i < top; ++i){
        int index = indexes[i];
        //if(net->hierarchy) printf("%d, %s: %f, parent: %s \n",index, names[index], predictions[index], (net->hierarchy->parent[index] >= 0) ? names[net->hierarchy->parent[index]] : "Root");
        //else printf("%s: %f\n",names[index], predictions[index]);
        printf("%5.2f%%: %s\n", predictions[index]*100, names[index]);
    }
    if(r.data != im.data) free_image(r);
    free_image(im);
}

void sendImg(char * arg)
{
    strcpy(filename, arg);
}

void runCNN()
{
    // for(i = 0; i < net->n; ++i){
    net->index = i;
    layer l = net->layers[i];
    if(l.delta){
        fill_cpu(l.outputs * l.batch, 0, l.delta, 1);
    }
    l.forward(l, *net);
    net->input = l.output;
    if(l.truth) {
        net->truth = l.output;
    }
    // }
    i++;
}