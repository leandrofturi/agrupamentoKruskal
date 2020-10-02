#include <stdio.h>
#include <stdlib.h>
#include "bib/grafo.h"
#include "bib/tratamento.h"
#include "bib/QU.h"


int main(int argc, char *argv[]) {
    int N = 7;
    char *rotulos[7] = {"0","1","2","3","4","5","6"};
    tGrafo *G = inicializa_tGrafo(11, N, rotulos);
    addAresta_tGrafo(G, "0", "1", 7);
    addAresta_tGrafo(G, "0", "3", 5);
    addAresta_tGrafo(G, "1", "3", 9);
    addAresta_tGrafo(G, "1", "2", 8);
    addAresta_tGrafo(G, "1", "4", 7);
    addAresta_tGrafo(G, "2", "4", 5);
    addAresta_tGrafo(G, "3", "4", 15);
    addAresta_tGrafo(G, "3", "5", 6);
    addAresta_tGrafo(G, "4", "5", 8);
    addAresta_tGrafo(G, "4", "6", 9);
    addAresta_tGrafo(G, "5", "6", 11);
    imprime_tGrafo(G);

    tGrafo *H = Kruskal_tGrafo(G);
    imprime_tGrafo(H);
    finaliza_tGrafo(H);
    finaliza_tGrafo(G);
    return(0);
}