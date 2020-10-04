#pragma once

#include"fila.h"

typedef struct Euclides Euclides;


// Distância Euclideana
double norm2(double *a, double *b, int M);

Euclides* matrizDistancia(Fila* f);