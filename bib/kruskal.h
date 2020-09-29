#pragma once


#include "arvore.h"

// Distância Euclideana
float norm2(float *a, float *b, int M);

float** matriz_pesos(char *adjs);

tArvore* kruskal();

