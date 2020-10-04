

typedef struct TFila TFila;

typedef struct Fila Fila;

Fila* criaFila();

TFila* criaTFila(char* rotulo, double* coordenadas, int m);

int filaVazia(Fila *p);

int tamanhoFila(Fila *p);

void imprimeFila(Fila *p);

void insere(Fila *p, TFila *ponto);

TFila* retira(Fila *p);

Fila* liberaFila(Fila* p);