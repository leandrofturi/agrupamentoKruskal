#include<stdio.h>
#include<stdlib.h>
#include"../bib/arquivo.h"
#include"../bib/pilha.h"

void leitura(char* arquivo, Pilha* pilha)
{

    FILE* arq;

    arq = fopen(arquivo, "r");

    if (arq == NULL)
    {

        printf("Problemas na abertura do arquivo\n");

    return;
    }

    while (!feof(arq))
    {
    
        char rotulo=' ';
        float x=0.0, y=0.0;

        fscanf(arq,"%c,%f,%f\n",&rotulo,&x,&y);

        TPilha* ponto = criaTPilha(rotulo, x, y);
        push(pilha, ponto);

    }

    fclose(arq);

return;
}