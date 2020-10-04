#pragma once

#include"fila.h"

typedef struct Euclides Euclides;


// Distância Euclideana
double disEuclides(double *a, double *b, int M);

Euclides** matrizDistancia(Fila* f, int index);

Euclides* liberaEuclides(Euclides* eu);

Euclides** liberaMatriz(Euclides** matriz, int n);