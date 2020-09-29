#pragma once

typedef struct tArvore tArvore;


// Inicialização e finalização.
tArvore *cria_arvore( );
void deleta_arvore(tArvore *A);

// Inserção de elementos.
void insere_arvore(tArvore *A, float dado);

// Propriedades.
int tamanho_arvore(tArvore *A);
int altura_arvore(tArvore *A);

// Caminhamento recursivo.
void preordem_arvore(tArvore *A, void (*visit)(int));
void inordem_arvore(tArvore *A, void (*visit)(int));
void posordem_arvore(tArvore *A, void (*visit)(int));
