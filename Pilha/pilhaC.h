typedef struct nodeC NODEC;
typedef struct pilhaC PILHAC;
PILHAC* criaPilha();
int vazia(PILHAC* pilha);
void push(PILHAC* pilha, char valor);
char pop(PILHAC* pilha);
char top(PILHAC* pilha);
void destroiPilha(PILHAC* pilha);
void printPilha(PILHAC* pilha);
