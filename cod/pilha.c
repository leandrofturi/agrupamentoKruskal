#include<stdio.h>
#include<stdlib.h>
#include"../bib/pilha.h"

struct TPilha //tipo interno da pilha. Esta struct contém as informacoes presentes em um ponto
{

    char rotulo;
    float x;
    float y;
    struct TPilha *prox;

};

struct Pilha //tipo pilha, contém o topo da pilha
{

    struct TPilha *topo;

};

Pilha* criaPilha(){

    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo ->topo = NULL;

return novo;
}

TPilha* criaTPilha(char rotulo, float x, float y)
{

    TPilha* novo = (TPilha*)malloc(sizeof(TPilha));
    novo ->prox = NULL;
    novo ->rotulo = rotulo;
    novo ->x = x;
    novo ->y = y;

return novo;
}

int pilhaVazia(Pilha *p)
{

return p ->topo == NULL;
}

int tamanhoPilha(Pilha *p)
{

    TPilha *aux = p ->topo;
    int tam = 0;

    while(aux!= NULL)
    {

        tam++;
        aux = aux ->prox;

    }

return tam;
}

void imprimePilha(Pilha *p) //funcao apenas para questoes de implementacao
{
    TPilha *aux = p ->topo;
    printf("Pilha: \"");
    while(aux != NULL)
    {
        printf("%c, ",aux ->rotulo);
        printf("%.2f, ",aux ->x);
        printf("%.2f\n",aux ->y);
        aux = aux->prox;
    }
    printf("\"\n");

return;
}

void push(Pilha *p, TPilha *ponto)
{
    
    ponto ->prox = p->topo;
    p->topo = ponto;

return;
}

TPilha* pop(Pilha *p)
{
    TPilha* pop;

    if (pilhaVazia(p))
    {

    return NULL;
    }else
    {

        pop = p->topo;
        p->topo = pop->prox;
        pop ->prox = NULL;

    return pop;
    }

}

Pilha* liberaPilha(Pilha* p)
{

    if(pilhaVazia(p))
    {

    return NULL;
    }

    TPilha* aux = p ->topo;

    while(aux ->prox != NULL)
    {

        TPilha* f = aux;
        aux = aux ->prox;
        free(f);

    }
    free(aux);
    free(p);

return p;
}