typedef struct node NODE;
typedef struct pilha PILHA;
PILHA* criaPilha();
int vazia(PILHA* pilha);
void push(PILHA* pilha, int valor);
int pop(PILHA* pilha);
int top(PILHA* pilha);
void destroiPilha(PILHA* pilha);
void printErr(PILHA* pilha);
void printPilha(PILHA* pilha);

