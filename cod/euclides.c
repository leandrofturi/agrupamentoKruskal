#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "../bib/euclides.h"

struct Euclides
{
    
    char* pontoA;
    char* pontoB;
    double distancia;

};


double disEuclides(double *a, double *b, int M) {
    double d = 0;
    for(int i = 0; i < M; i++)
        d += (a[i] - b[i])*(a[i] - b[i]);
    d = sqrt(d);
    return(d);
}


Euclides** matrizDistancia(Fila* f, int index)//calcula em um vetor as distancias euclidianas
{

    int n = tamanhoFila(f);
    n = (n*(n - 1) / 2);
    Euclides** matriz = (Euclides**)malloc(n*sizeof(Euclides*));//cria o vetor de distancias
    for(int i=0; i<n; i++){

        matriz[i] = (Euclides*)malloc(sizeof(Euclides));

    }
    n=0;

    Fila* aux = criaFila();
    TFila* retirado, *multiplicado; //retirado é a quele que vai ser multiplicado por todos da fila e multiplicado é aquele a ser multiplicado pelo retirado

    while(!filaVazia(f))//sao utilizadas duas filas para fazer os calculos
    {

        retirado = retira(f);//retira o ponto que serah usado para calcular as distancia com os demais pontos na fila

        int m = tamanhoFila(f);//calcula quantos pontos restam na fila

        for(int i=0; i<m; i++)
        {

            multiplicado = retira(f);//retira da fila o ponto a ter a distancia em relacao ao ponto 'retirado' calculado

            matriz[n] ->pontoA = (char*)malloc((strlen(getRotulo(retirado))+1)*sizeof(char));
            matriz[n] ->pontoB = (char*)malloc((strlen(getRotulo(multiplicado))+1)*sizeof(char));

            strcpy(matriz[n] ->pontoA, getRotulo(retirado));
            strcpy(matriz[n] ->pontoB, getRotulo(multiplicado));

            matriz[n] ->distancia = disEuclides(getCoordenadas(retirado), getCoordenadas(multiplicado), index);

            insere(f, multiplicado);// insere o ponto usado de volta a fila para que ele possa ser usado nas proximas passagens

            n++;//atualiza a posicao do vetor

        }

        //printf("inserindo no aux ->%s\n",getRotulo(retirado));
        insere(aux, retirado);//coloca numa fila auxiliar os pontos que ja tiveram as distancias calculadas

    }

    while(!filaVazia(aux))
    {

        insere(f, retira(aux));//devolve os pontos para a fila original

    }

    free(aux); 

return matriz;
}

Euclides* liberaEuclides(Euclides* eu)
{

    free(eu ->pontoA);
    free(eu ->pontoB);
    free(eu);

return eu;
}

Euclides** liberaMatriz(Euclides** matriz, int n)
{

    for(int i=0; i<n; i++)
    {

        matriz[i] = liberaEuclides(matriz[i]);

    }
    free(matriz);

return matriz;
}