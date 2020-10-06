#include <stdlib.h>
#include <stdio.h>
#include "../bib/QU.h"

struct tQU {
    int id;
    int sz;
};


tQU* inicializa_QU(int N) {
    tQU *id = (tQU*) malloc(sizeof(tQU)*N);
    for(int i = 0; i < N; i++) {
        id[i].id = i;
        id[i].sz = 1;
    }
    return(id);
}

void finaliza_QU(tQU *id) {
    free(id);
}

void une_QU(tQU *id, int p, int q) {
    if(id[p].sz < id[q].sz) {
        id[procura_QU(id, p)].id = id[procura_QU(id, q)].id;
        id[id[procura_QU(id, p)].id].sz++;
    }
    else {
        id[procura_QU(id, q)].id = id[procura_QU(id, p)].id;
        id[id[procura_QU(id, q)].id].sz++;
    }
}

int procura_QU(tQU *id, int p) {
    while(p != id[p].id) p = id[p].id;
    return p;
}

bool conectados_QU(tQU *id, int p, int q) {
    return(procura_QU(id, p) == procura_QU(id, q));
}

void componentes_QU(tQU *id, int N) {
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