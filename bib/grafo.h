#pragma once

#include <stdbool.h>

typedef struct tGrafo tGrafo;


// Inicialização
tGrafo* inicializa_tGrafo(int M, int N, char **rotulos);

// Finalização
void finaliza_tGrafo(tGrafo *G);

// Existe uma aresta entre p e q?
bool existeAresta_tGrafo(tGrafo *G, char *p, char *q);

// Existe o vértice p?
bool existeVertice_tGrafo(tGrafo *G, char *p);

// Adiciona uma conexao entre p e q, de peso w
void addAresta_tGrafo(tGrafo *G, char *p, char *q, double w);

// Imprime o grafo
void imprime_tGrafo(tGrafo *G);

// Algoritmo de Kruskal
tGrafo* Kruskal_tGrafo(tGrafo *G);
