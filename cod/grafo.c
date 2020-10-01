#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../bib/QU.h"
#include "../bib/grafo.h"

typedef struct tAresta {
    int u, v;
    double w;
    struct tAresta *prox;
} tAresta;

typedef struct tGrafo {
    int N, M;
    tAresta *arestas;
    char **rotulos;
} tGrafo;


static int pos(tGrafo *G, char *p) {
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

tGrafo* inicializa_tGrafo(int N, char **rotulos) {
    tGrafo *G = (tGrafo*) malloc(sizeof(tGrafo));
    G->rotulos = (char**) malloc(N*sizeof(char*));
    for(int i = 0; i < N; i++)
        G->rotulos[i] = rotulos[i];
    
    G->N = N;
    G->arestas = NULL;
    G->M = 0;
    return(G);
}

void finaliza_tGrafo(tGrafo *G) {  
    tAresta *atual = G->arestas, *prox;
    while(atual) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(G->rotulos);
    free(G);
}

bool existeAresta_tGrafo(tGrafo *G, char *p, char *q) {
    tAresta *atual = G->arestas;
    int P = pos(G, p), Q = pos(G, q);
    while(atual) {
        if((atual->u == P && atual->v == Q) || 
           (atual->u == Q && atual->v == P))
            return(true);
        atual = atual->prox;
    }
    return(false);
}

bool existeVertice_tGrafo(tGrafo *G, char *p) {
    for(int i = 0; i < G->N; i++)
        if(strcmp(G->rotulos[i], p) == 0)
            return(true);
    return(false);
}

void addAresta_tGrafo(tGrafo *G, char *p, char *q, double w) {
    if(existeAresta_tGrafo(G, p, q)) {
        printf("ATENCAO! Aresta ja existente!\n");
        return;
    }
    if(!existeVertice_tGrafo(G, p) || !existeVertice_tGrafo(G, q)) {
        printf("ATENCAO! Vertice inexistente!\n");
        return;
    }
    if(G->M > (G->N*(G->N-1)/2)) {
        printf("ATENCAO! Maximo de arestas atingido!\n");
        return;
    }

    tAresta **atual = &(G->arestas);
    while((*atual) && (*atual)->w <= w)
        atual = &(*atual)->prox;

    tAresta *nova = (tAresta*) malloc(sizeof(tAresta));
    nova->u = pos(G, p);
    nova->v = pos(G, q);
    nova->w = w;
    nova->prox = *atual;
    *atual = nova;
    G->M++;
}

void imprime_tGrafo(tGrafo *G) {
    tAresta *atual = G->arestas;
    printf("\n");
    for(int i = 0; i < G->M; i++) {
        printf("(%s, %s) %.2lf\n", rot(G, atual->u), rot(G, atual->v), atual->w);
        atual = atual->prox;
    }
    printf("\n");
}

tGrafo* Kruskal_tGrafo(tGrafo *G) {
    int **id = inicializa_QU(G->N);
    tGrafo *H = inicializa_tGrafo(G->N, G->rotulos);
    
    tAresta *atual = G->arestas;
    while(atual) {
        if(!conectados_QU(id, atual->u, atual->v)) {
            addAresta_tGrafo(H, rot(G, atual->u), rot(G, atual->v), atual->w);
            une_QU(id, atual->u, atual->v);
        }
        atual = atual->prox;
    }
    finaliza_QU(id);
    return(H);
}
