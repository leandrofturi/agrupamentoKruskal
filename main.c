#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bib/problema.h"


int main(int argc, char *argv[]) {

    char *path_in = argv[1];
    int k = atoi(argv[2])-1;
    char *path_out = argv[3];

    tSet *S = leitura(path_in);
    tGrafo *G = pre_processamento(S);
    tQU *id = processamento(G, k);
    pos_processamento(id, G, path_out);

    finaliza_set(S);
    finaliza_grafo(G);
    finaliza_QU(id);

    return(0);
}