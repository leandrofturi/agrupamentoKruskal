#pragma once

// Quick Union + Weighted + Path Compression.
#include <stdbool.h>

typedef struct tQU tQU;


// Inicializa estrutura com N objetos numerados de 0 a N-1.
// #1 linha correspondendo as componentes, #2 linha correspondendo ao peso de cada componente.
tQU* inicializa_QU(int N);

// Finaliza.
void finaliza_QU(tQU *id);

// Adiciona uma conexao entre p e q.
void une_QU(tQU *id, int p, int q);

// Retorna o identificador do componente de p (entre 0 a N-1).
int procura_QU(tQU *id, int p);

// Os objetos p e q estao no mesmo componente?
bool conectados_QU(tQU *id, int p, int q);

// Componentes formadas.
void componentes_QU(tQU *id, int N);