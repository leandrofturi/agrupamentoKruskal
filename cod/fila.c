#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../bib/fila.h"

struct TFila //tipo interno da fila. Esta struct contém as informacoes presentes em um ponto
{

    char* rotulo;
    double* coordenadas;
    struct TFila *prox;

};

struct Fila //tipo fila, contém o topo da fila
{

    struct TFila* primeiro;
    struct TFila* ultimo;

};

Fila* criaFila(){

    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo ->primeiro = NULL;
    novo ->ultimo = NULL;

return novo;
}

TFila* criaTFila(char* rotulo, double* coordenadas, int m)
{

    TFila* novo = (TFila*)malloc(sizeof(TFila));
    novo ->rotulo = (char*)malloc((strlen(rotulo)+1)*sizeof(char));
    novo ->coordenadas = (double*)malloc(m*sizeof(double));
    novo ->prox = NULL;
    strcpy(novo ->rotulo, rotulo);

    for(int i=0; i<m; i++)
    {

        novo ->coordenadas[i] = coordenadas[i];
    
    }

return novo;
}

int filaVazia(Fila *p)
{

return p ->primeiro == NULL;
}

int tamanhoFila(Fila *p)
{

    TFila *aux = p ->primeiro;
    int tam = 0;

    while(aux!= NULL)
    {

        tam++;
        aux = aux ->prox;

    }

return tam;
}

void imprimeFila(Fila *p) //funcao apenas para questoes de implementacao
{
    TFila *aux = p ->primeiro;
    printf("Fila: \"");
    while(aux != NULL)
    {
        printf("%s, ",aux ->rotulo);
        printf("%.2f, ",aux ->coordenadas[0]);
        printf("%.2f\n",aux ->coordenadas[1]);
        aux = aux->prox;
    }
    printf("\"\n");

return;
}

void insere(Fila *f, TFila *ponto)
{
    
    if (filaVazia(f))
    {

        f->primeiro = ponto;

    }else{

        f->ultimo->prox = ponto;

    }

    f->ultimo = ponto;

return;
}

TFila* retira(Fila *f)
{
    TFila* pop;

    if (filaVazia(f))
    {

    return NULL;
    }

    pop = f ->primeiro;
    f ->primeiro = pop ->prox;
    pop ->prox = NULL;

    if(f ->primeiro == NULL)
    {

        f ->ultimo = NULL;

    }

return pop;

}

Fila* liberaFila(Fila* f)
{

    if(filaVazia(f))
    {

    return NULL;
    }

    TFila* aux = f ->primeiro;

    while(aux ->prox != NULL)
    {

        TFila* r = aux;
        aux = aux ->prox;
        free(r ->coordenadas);
        free(r ->rotulo);
        free(r);

    }
    free(aux ->coordenadas);
    free(aux ->rotulo);
    free(aux);
    free(f);

return f;
}