#include <stdlib.h>
#include <stdio.h>
#include "../bib/arvore.h"

typedef struct tNo {
    int dado;
    struct tNo *esq, *dir;
} tNo;

typedef struct tArvore {
    tNo *raiz;
    int nNos;
} tArvore;

#define MAX(a, b) a > b ? a : b


tArvore *cria_arvore( ) {
    tArvore *A = (tArvore*) malloc(sizeof(tArvore));
    A->raiz = NULL;
    A->nNos = 0;
    return(A);
}

static void rec_deleta(tNo **raiz) {
    if(raiz == NULL)
        return;
    if(*raiz == NULL)
        return;

    rec_deleta(&(*raiz)->esq);
    rec_deleta(&(*raiz)->dir);
    free(*raiz);
}

void deleta_arvore(tArvore *A) {
    rec_deleta(&A->raiz);
    free(A);
}

static int rec_insere(tNo **raiz, int dado) {
    if(raiz == NULL)
        return(0);
    if(*raiz == NULL) {
        *raiz = (tNo*) malloc(sizeof(tNo));
        (*raiz)->dado = dado;
        (*raiz)->dir = (*raiz)->esq = NULL;
        return(1);
    }

    if((*raiz)->dado > dado)
        return(rec_insere(&(*raiz)->esq, dado));
    else if((*raiz)->dado < dado)
        return(rec_insere(&(*raiz)->dir, dado));
    else
        return(0);
}

void insere_arvore(tArvore *A, float dado) {
    if(rec_insere(&A->raiz, dado));
        A->nNos++;
}

int tamanho_arvore(tArvore *A) {
    return(A->nNos);
}

static void rec_imprime(tNo *raiz) {
    if(raiz == NULL)
        return;
    
    printf("%d ", raiz->dado);
    rec_imprime(raiz->esq);
    rec_imprime(raiz->dir);
}

void imprime_arvore(tArvore *A) {
    rec_imprime(A->raiz);
}

static int rec_altura(tNo *raiz) {
    if(raiz == NULL)
        return(-1);
    return(MAX(1 + rec_altura(raiz->esq), 1 + rec_altura(raiz->dir)));
}

int altura_arvore(tArvore *A) {
    return(rec_altura(A->raiz));
}

static void rec_preordem(tNo *raiz, void (*visit)(int)) {
    if(raiz == NULL)
        return;

    visit(raiz->dado);
    rec_preordem(raiz->esq, visit);
    rec_preordem(raiz->dir, visit);
}

static void rec_inordem(tNo *raiz, void (*visit)(int)) {
    if(raiz == NULL)
        return;

    rec_inordem(raiz->esq, visit);
    visit(raiz->dado);
    rec_inordem(raiz->dir, visit);
}

static void rec_posordem(tNo *raiz, void (*visit)(int)) {
    if(raiz == NULL)
        return;

    rec_posordem(raiz->esq, visit);
    rec_posordem(raiz->dir, visit);
    visit(raiz->dado);
}

void preordem_arvore(tArvore *A, void (*visit)(int)) {
    if(A->raiz == NULL)
        return;

    rec_preordem(A->raiz, visit);
}

void inordem_arvore(tArvore *A, void (*visit)(int)) {
    if(A->raiz == NULL)
        return;

    rec_inordem(A->raiz, visit);
}

void posordem_arvore(tArvore *A, void (*visit)(int)) {
    if(A->raiz == NULL)
        return;

    rec_posordem(A->raiz, visit);
}
