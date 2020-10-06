#pragma once

#include "QU.h"
#include <stdbool.h>

// Estrutura de um grafo ponderado contendo M arestas, N nós e cada nó correspondendo a um rótulo.
// Nesta estrutura os nós são mapeados para um inteiro (key).
typedef struct tGrafo tGrafo;


// Inicialização.
tGrafo* inicializa_grafo(int M, int N, char **rotulos);

// Finalização.
void finaliza_grafo(tGrafo *G);

// Retorna a chave (inteiro) referente a um rótulo.
int key_grafo(tGrafo *G, char *p);

// Retorna o rótulo referente a um inteiro.
char* rot_grafo(tGrafo *G, int p);

// Existe uma aresta entre p e q?
bool existeAresta_grafo(tGrafo *G, char *p, char *q);

// Existe o vértice p?
bool existeVertice_grafo(tGrafo *G, char *p);

// Adiciona uma conexao entre p e q, de peso w.
void addAresta_grafo(tGrafo *G, char *p, char *q, double w);

// Ordena as arestas em ordem crescente pelos pesos.
void ordenaAresta_grafo(tGrafo *G);

// Imprime o grafo.
void imprime_grafo(tGrafo *G);

// Quantidade de vértices do Grafo.
int vertices_grafo(tGrafo *G);

// Algoritmo de Kruskal.
tGrafo* Kruskal_grafo(tGrafo *G);

// Remove as k arestas mais pesadas de um Grafo já ordenado, retornando as componentes conexas.
tQU* removeKArestas_grafo(tGrafo *G, int k);
