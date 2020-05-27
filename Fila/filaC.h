typedef struct node NODE;
typedef struct fila FILA;
FILA* criaFila();
int vazia(FILA* fila);
void enqueue(FILA* fila, char valor);
char dequeue(FILA* fila);
char first(FILA* fila);
void destroiFila(FILA *fila);
void printFila(FILA *fila);











