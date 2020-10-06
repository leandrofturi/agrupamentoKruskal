#pragma once

// Estrutura de pontos (double) em coordenadas Euclideanas.
// Cada ponto possui um rótulo e as respectivas coordenadadas de RM.
typedef struct tPonto tPonto;
// Estrutura de um conjunto de pontos, implementada como uma pilha.
typedef struct tSet tSet;


// Inicialização.
tSet* inicializa_set( );

// Finalização.
void finaliza_set(tSet *S);

// Insere (push) um ponto no conjunto.
void push_set(tSet *S, tPonto *p);

// Remove (pop) um ponto do conjunto.
tPonto* pop_set(tSet *S);

// Quantidade de pontos no conjunto.
int tamanho_set(tSet *S);

// Rótulos contidos no conjunto de pontos.
char** rotulos_set(tSet *S);

// Imprime o conjunto.
void imprime_set(tSet *S);

// Cria um novo ponto, fazendo uma cópia de cada elemento.
tPonto* novo_ponto(char *rot, double *x, int M);

// Finalização.
void finaliza_ponto(tPonto *p);

// Rótulo de um ponto.
char* rot_ponto(tPonto *p);

// Coordenadas de um ponto.
double* x_ponto(tPonto *p);

// Cardinalidade do conjunto ao qual o ponto está inserido.
int M_ponto(tPonto *p);

// Distância Euclideana
double norm2(double *a, double *b, int N);
