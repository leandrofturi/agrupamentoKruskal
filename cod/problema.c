#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bib/problema.h"


// Leitura de uma linha de tamanho arbitrário.
// https://www.gnu.org/software/libc/manual/html_node/Line-Input.html
static char *pegaLinha(FILE *arq) {
    size_t n = 0, r;
    char *buf = NULL;

    r = getline(&buf, &n, arq);
    if(r < 0) {
        return(NULL);
    }
    return(buf);
}

// Contar as ocorrências de um caracter específico em uma string.
static int count(char *s, char c) {
    int r = 0;
    for(; *s; s++)
        r += *s == c;
    return r;
}

tSet* leitura(char *path) {
    int m, M;
    char *sep = ",", 
         *linha, *token;
    FILE* arq;
    tSet *S = inicializa_set( );

    arq = fopen(path, "r");
    if(!arq || feof(arq)) {
        finaliza_set(S);
        return(NULL);
    }
    // Primeira linha. A partir dela é calculado o tamanho do ponto (M), para verificação posterior.
    linha = pegaLinha(arq);
    M = count(linha, *sep);
    // https://pubs.opengroup.org/onlinepubs/9699919799/functions/strtok.html
    token = strtok(linha, sep);
    char *rot = token; // Rótulo
    double x[M];
    token = strtok(NULL, sep); // Coordenadas
    for(m = 0; m < M; m++, token = strtok(NULL, sep))
        x[m] = strtod(token, NULL);
    push_set(S, novo_ponto(rot, x, M));
    free(linha);

    while(!feof(arq)) {
        linha = pegaLinha(arq);

        token = strtok(linha, sep); // Rótulo
        rot = token;
        token = strtok(NULL, sep); // Coordenadas
        for(m = 0; token != NULL; m++, token = strtok(NULL, sep))
            x[m] = strtod(token, NULL);

        if(m != M) { // Algum ponto possui corrdenadas a mais?
            fclose(arq);
            finaliza_set(S);
            return(NULL);
        }
        push_set(S, novo_ponto(rot, x, M)); // Inserção no conjunto de pontos
        free(linha);
    }
    fclose(arq);
    return(S);
}

tGrafo* pre_processamento(tSet *S) {
    int N = tamanho_set(S);
    int M = N*(N-1)/2;
    double w;
    char** rot = rotulos_set(S);
    tGrafo *G = inicializa_grafo(M, N, rot);
    free(rot);
    tSet *T = inicializa_set( ), // Auxiliar para não perder o S
         *U = inicializa_set( ); // Auxiliar nas operações de push e pop
    tPonto *a, *b;
    // Para cada rótulo i, pego os i+1 ... N rótulos e calculo a distância euclideana entre eles
    for(int i = 0; i < N; i++) {
        a = pop_set(S);
        for(int j = i+1; j < N; j++) {
            b = pop_set(S);
            w = norm2(x_ponto(a), x_ponto(b), M_ponto(a));
            addAresta_grafo(G, rot_ponto(a), rot_ponto(b), w);
            push_set(U, b); // Guardo o ponto para comparar com os demais
        }
        while(tamanho_set(U))
            push_set(S, pop_set(U)); // Retomo os pontos guardados
        push_set(T, a); // "Jogo Fora" o ponto i
    }
    finaliza_set(U);
    while(tamanho_set(T))
        push_set(S, pop_set(T));
    finaliza_set(T); // Retomo o conjunto original S

    ordenaAresta_grafo(G); // Ordeno as arestas pelos seus pesos
    return(G);
}

tQU* processamento(tGrafo *G, int k) {
    tGrafo *H = Kruskal_grafo(G);
    tQU *id = removeKArestas_grafo(H, k);
    finaliza_grafo(H);
    return(id);
}

int pos_processamento(tQU *id, tGrafo *G, char *path) {
    FILE *arq = fopen(path, "w");
    if(!arq)
        return(1);

    int N = vertices_grafo(G);
    int tmp[N];
    for(int i = 0; i < N; i++)
        tmp[i] = 1; // Para cada rótulo, uma flag que indique se ele já foi printado ou não

    for(int i = 0; i < N; i++) {
        if(tmp[i]) {
            fprintf(arq, "%s", rot_grafo(G, i));
            for(int j = i+1; j < N; j++) {
                if(conectados_QU(id, i, j)) {
                    fprintf(arq, ",%s", rot_grafo(G, j));
                    tmp[j] = 0;
                }
            }
            tmp[i] = 0;
            fprintf(arq, "\n");
        }
    }
    fclose(arq);
    return(0);
}