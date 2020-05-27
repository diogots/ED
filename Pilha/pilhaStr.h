typedef struct node NODE;
typedef struct pilha PILHA;
PILHA* criaPilha();
int vazia(PILHA* pilha);
void push(PILHA* pilha, int valor);
char* pop(PILHA* pilha);
char* top(PILHA* pilha);

