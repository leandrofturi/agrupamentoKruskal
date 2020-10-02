#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../bib/QU.h"
#include "../bib/grafo.h"

typedef struct tAresta {
    int u, v;
    double w;
} tAresta;

typedef struct tGrafo {
    int N, M;
    tAresta *arestas;
    char **rotulos;
} tGrafo;


static int key(tGrafo *G, char *p) {
    for(int i = 0; i < G->N; i++)
        if(strcmp(G->rotulos[i], p) == 0)
            return(i);
    return(-1);
}

static char* rot(tGrafo *G, int p) {
    if(p >= G->N || p < 0)
        return(NULL);
    return(G->rotulos[p]);
}

// https://stackoverflow.com/questions/43099269/qsort-function-in-c-used-to-compare-an-array-of-strings
static int cmpstr(const void *a, const void *b) {
   return strcmp(*(const char **) a, *(const char **) b);
}

tGrafo* inicializa_tGrafo(int M, int N, char **rotulos) {
    tGrafo *G = (tGrafo*) malloc(sizeof(tGrafo));
    G->arestas = (tAresta*) malloc(M*sizeof(tAresta));
    G->rotulos = (char**) malloc(N*sizeof(char*));
    for(int i = 0; i < N; i++) {
        G->rotulos[i] = (char*) malloc(sizeof(rotulos[i]));
        strcpy(G->rotulos[i], rotulos[i]);
    }
    qsort(G->rotulos, N, sizeof(char*), cmpstr);
    G->M = 0;
    G->N = N;
    return(G);
}

void finaliza_tGrafo(tGrafo *G) {
    free(G->arestas);
    for(int i = 0; i < G->N; i++)
        free(G->rotulos[i]);
    free(G->rotulos);
    free(G);
}

void addAresta_tGrafo(tGrafo *G, char *p, char *q, double w) {
    G->arestas[G->M].u = key(G, p);
    G->arestas[G->M].v = key(G, q);
    G->arestas[G->M].w = w;
    G->M++;
}

void imprime_tGrafo(tGrafo *G) {
    printf("\n");
    for(int i = 0; i < G->M; i++)
        printf("(%s, %s) %.2lf\n", rot(G, G->arestas[i].u), rot(G, G->arestas[i].v), G->arestas[i].w);
    printf("\n");
}

tGrafo* Kruskal_tGrafo(tGrafo *G) {
    int **id = inicializa_QU(G->N);
    tGrafo *H = inicializa_tGrafo(G->N-1, G->N, G->rotulos);
    
    for(int i = 0; i < G->M; i++) {
        if(!conectados_QU(id, G->arestas[i].u, G->arestas[i].v)) {
            addAresta_tGrafo(H, rot(G, G->arestas[i].u), rot(G, G->arestas[i].v), G->arestas[i].w);
            une_QU(id, G->arestas[i].u, G->arestas[i].v);
        }
    }
    finaliza_QU(id);
    return(H);
}
