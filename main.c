#include <stdio.h>
#include <stdlib.h>
#include "bib/kruskal.h"
#include "bib/QU.h"


int main(int argc, char *argv[]) {
    int p, q, N = atoi(argv[1]), M = atoi(argv[2]);
    int** id = inicializa_QU(N);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &p, &q);
        if(!conectados_QU(id, p, q))
            une_QU(id, p, q);
    }
    componentes_QU(id, N);
    finaliza_QU(id);
    return(0);
}