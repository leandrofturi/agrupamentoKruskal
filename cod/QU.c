#include <stdlib.h>
#include <stdio.h>
#include "../bib/QU.h"


int** inicializa_QU(int N) {
    int **id = (int**) malloc(2*sizeof(int*));
    id[0] = (int*) malloc(N*sizeof(int));
    id[1] = (int*) malloc(N*sizeof(int));
    for(int i = 0; i < N; i++) {
        id[0][i] = i;
        id[1][i] = 1;
    }
    return(id);
}

void finaliza_QU(int **id) {
    free(id[0]);
    free(id[1]);
    free(id);
}

void une_QU(int **id, int p, int q) {
    if(id[1][p] < id[1][q]) {
        id[0][procura_QU(id, p)] = id[0][procura_QU(id, q)];
        id[1][id[0][procura_QU(id, p)]]++;
    }
    else {
        id[0][procura_QU(id, q)] = id[0][procura_QU(id, p)];
        id[1][id[0][procura_QU(id, q)]]++;
    }
}

int procura_QU(int **id, int p) {
    while(p != id[0][p]) p = id[0][p];
    return p;
}

bool conectados_QU(int **id, int p, int q) {
    return(procura_QU(id, p) == procura_QU(id, q));
}

void componentes_QU(int **id, int N) {
    int tmp[N];
    for(int i = 0; i < N; i++) tmp[i] = 1;

    printf("\n");
    for(int i = 0; i < N; i++) {
        if(tmp[i]) {
            printf("%d ", i);
            for(int j = i+1; j < N; j++) {
                if(conectados_QU(id, i, j)) {
                    printf("%d ", j);
                    tmp[j] = 0;
                }
            }
            tmp[i] = 0;
            printf("\n");
        }
    }
}