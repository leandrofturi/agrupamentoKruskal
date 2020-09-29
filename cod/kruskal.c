#include <math.h>
#include "../bib/kruskal.h"
#include "../bib/arvore.h"

//static int M, N;


float norm2(float *a, float *b, int M) {
    float d = 0;
    for(int i = 0; i < M ; i++)
        d += (a[i] - b[i])*(a[i] - b[i]);
    d = sqrt(d);
    return(d);
}


