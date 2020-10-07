#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
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


// Funções de acesso rápido.
// https://stackoverflow.com/questions/43099269/qsort-function-in-c-used-to-compare-an-array-of-strings
static int cmpstr(const void *a, const void *b) {
   return strcmp(*(const char **) a, *(const char **) b);
}

static int key(tGrafo *G, char *p) {
    char **tmp = (char**) bsearch(&p, G->rotulos, G->N, sizeof(char*), cmpstr);
    // https://stackoverflow.com/questions/26805461/why-do-i-get-cast-from-pointer-to-integer-of-different-size-error
    // https://stackoverflow.com/questions/20571043/is-there-a-way-of-finding-position-of-element-when-searching-a-char-array-with-b
    return((int) ((intptr_t) tmp - (intptr_t) G->rotulos) / sizeof(char**));
}

static char* rot(tGrafo *G, int p) {
    return(G->rotulos[p]);
}

// Cópia dos elementos
tGrafo* inicializa_grafo(int M, int N, char **rotulos) {
    tGrafo *G = (tGrafo*) malloc(sizeof(tGrafo));
    G->arestas = (tAresta*) malloc(M*sizeof(tAresta));
    G->rotulos = (char**) malloc(N*sizeof(char*));
    for(int i = 0; i < N; i++) {
        G->rotulos[i] = (char*) malloc((strlen(rotulos[i])+1)*sizeof(char*));
        strcpy(G->rotulos[i], rotulos[i]);
    }
    // Rótulos ordenados, para que o mapeamento seja mais rápido.
    qsort(G->rotulos, N, sizeof(char*), cmpstr);
    G->M = 0;
    G->N = N;
    return(G);
}

void finaliza_grafo(tGrafo *G) {
    free(G->arestas);
    for(int i = 0; i < G->N; i++)
        free(G->rotulos[i]);
    free(G->rotulos);
    free(G);
}

int key_grafo(tGrafo *G, char *p) {
    return(key(G, p));
}

char* rot_grafo(tGrafo *G, int p) {
    return(rot(G, p));
}

// Note que a inserção é limitada a M arestas.
void addAresta_grafo(tGrafo *G, char *p, char *q, double w) {
    G->arestas[G->M].u = key(G, p);
    G->arestas[G->M].v = key(G, q);
    G->arestas[G->M].w = w;
    G->M++;
}

static int compareAresta(const void *a, const void *b) {
  return(((tAresta*) a)->w - ((tAresta*) b)->w);
}

// http://www.cplusplus.com/reference/cstdlib/qsort/
void ordenaAresta_grafo(tGrafo *G) {
    qsort(G->arestas, G->M, sizeof(tAresta), compareAresta);
}

void imprime_grafo(tGrafo *G) {
    printf("\n");
    for(int i = 0; i < G->M; i++)
        printf("(%s, %s) %.2lf\n", rot(G, G->arestas[i].u), rot(G, G->arestas[i].v), G->arestas[i].w);
    printf("\n");
}

int vertices_grafo(tGrafo *G) {
    return(G->N);
}

// Algoritmo de Kruskal
// https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
tGrafo* Kruskal_grafo(tGrafo *G) {
    tQU *id = inicializa_QU(G->N);
    tGrafo *H = inicializa_grafo(G->N-1, G->N, G->rotulos);
    
    for(int i = 0; i < G->M; i++) {
        if(!conectados_QU(id, G->arestas[i].u, G->arestas[i].v)) {
            addAresta_grafo(H, rot(G, G->arestas[i].u), rot(G, G->arestas[i].v), G->arestas[i].w);
            une_QU(id, G->arestas[i].u, G->arestas[i].v);
        }
    }
    finaliza_QU(id);
    return(H);
}

tQU* removeKArestas_grafo(tGrafo *G, int k) {
    tQU *id = inicializa_QU(G->N);
    for(int i = 0; i < G->M-k; i++)
        une_QU(id, G->arestas[i].u, G->arestas[i].v);
    return(id);
}
