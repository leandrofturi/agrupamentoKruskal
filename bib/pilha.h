

typedef struct TPilha TPilha;

typedef struct Pilha Pilha;

Pilha* criaPilha();

TPilha* criaTPilha(char rotulo, float x, float y);

int pilhaVazia(Pilha *p);

int tamanhoPilha(Pilha *p);

void imprimePilha(Pilha *p);

void push(Pilha *p, TPilha *ponto);

TPilha* pop(Pilha *p);

Pilha* liberaPilha(Pilha* p);