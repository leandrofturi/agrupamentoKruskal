#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../bib/euclides.h"

struct tPonto {
    char *rot;
    double *x;
    int M;
    tPonto *prox;
};

struct tSet {
    tPonto *pontos;
    int N;
};


tSet* inicializa_set( ) {
    tSet *S = (tSet*) malloc(sizeof(tSet));
    S->pontos = NULL;
    S->N = 0;
    return(S);
}

void finaliza_set(tSet *S) {
    while(S->N)
        finaliza_ponto(pop_set(S));
    free(S);
}

// Operações de custo constante.
void push_set(tSet *S, tPonto *p) {
    p->prox = S->pontos;
    S->pontos = p;
    S->N++;
}

tPonto* pop_set(tSet *S) {
    tPonto *p = S->pontos;
    S->pontos = S->pontos->prox;
    S->N--;
    return(p);
}

int tamanho_set(tSet *S) {
    return(S->N);
}

char** rotulos_set(tSet *S) {
    char **rot = (char**) malloc(sizeof(char*)*S->N);
    tPonto *tmp = S->pontos;
    for(int i = 0; i < S->N; i++) {
        rot[i] = tmp->rot;
        tmp = tmp->prox;
    }
    return(rot);
}

void imprime_set(tSet *S) {
    if(!S)
        return;

    tPonto *p = S->pontos;
    for(int i = 0; i < S->N && p; i++) {
        printf("%s", p->rot);
        printf(" ( ");
        for(int j = 0; j < p->M; j++)
            printf("%.2lf ", p->x[j]);
        printf(")\n");
        p = p->prox;
    }
    printf("\n");
}

tPonto* novo_ponto(char *rot, double *x, int M) {
    tPonto *p = (tPonto*) malloc(sizeof(tPonto));
    p->rot = (char*) malloc((strlen(rot)+1)*sizeof(char));
    strcpy(p->rot, rot);
    p->x = (double*) malloc(sizeof(double)*M);
    for(int i = 0; i < M; i++)
        p->x[i] = x[i];
    p->M = M;
    return(p);
}

void finaliza_ponto(tPonto *p) {
    free(p->rot);
    free(p->x);
    free(p);
}

char* rot_ponto(tPonto *p) {
    return(p->rot);
}

double* x_ponto(tPonto *p) {
    return(p->x);
}

int M_ponto(tPonto *p) {
    return(p->M);
}

double norm2(double *a, double *b, int N) {
    double d = 0;
    for(int i = 0; i < N; i++)
        d += (a[i] - b[i])*(a[i] - b[i]);
    d = sqrt(d);
    return(d);
}
