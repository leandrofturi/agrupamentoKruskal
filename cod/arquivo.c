#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../bib/arquivo.h"
#include"../bib/fila.h"

void leitura(char* arquivo, Fila* fila)
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
    
        size_t len= 100; // valor arbitrário
        char *linha=malloc(len);    

        getline(&linha, &len, arq);

        int m=0;
        for(int i=0; i<strlen(linha); i++)
        {

            if(linha[i] == ',')
            {

                m++;

            }

        }
        double coordenadas[m];

        char* token;
        token = strtok(linha, ",");
        char rotulo[strlen(token)+1];
        strcpy(rotulo,token);
        char* aux;
        printf( "%s\n", token);

        for(int i=0; i<m; i++) 
        {
        
            token = strtok(NULL, ",");
            printf( "%s\n", token);
            coordenadas[i] = strtod(token, &aux);

        }

        TFila* ponto = criaTFila(rotulo, coordenadas, m);
        insere(fila, ponto);

        free(linha);

    }

    fclose(arq);

return;
}