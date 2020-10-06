#pragma once

#include "euclides.h"
#include "grafo.h"
#include "QU.h"

// Problema proposto:
// Algoritmo para encontrar o agrupamento de espaço máximo.


// Leitura do arquivode entrada.
tSet* leitura(char* arquivo);

// Pré processamento: cálculo das distâncias entre os pontos e construção do Grafo completo.
tGrafo* pre_processamento(tSet *S);

// Processamento: Algoritmo de Kruskal aplicado ao problema.
tQU* processamento(tGrafo *G, int k);

// Pós processamento: Escrita em um arquivo de saída das componentes conexas formadas.
int pos_processamento(tQU *id, tGrafo *G, char *path);
