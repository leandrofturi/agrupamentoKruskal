#include <math.h>
#include "../bib/euclides.h"

struct Euclides
{
    
    char pontoA;
    char pontoB;
    double distancia;

};


double norm2(double *a, double *b, int M) {
    double d = 0;
    for(int i = 0; i < M; i++)
        d += (a[i] - b[i])*(a[i] - b[i]);
    d = sqrt(d);
    return(d);
}


/*Euclides* matrizDistancia(Fila f)
{

}*/