typedef struct node NODE;
typedef struct fila FILA;
FILA* criaFila();
int vazia(FILA* fila);
void enqueue(FILA* fila, int valor);
int dequeue(FILA* fila);
int first(FILA* fila);
void destroiFila(FILA *fila);
void imprimeFila(FILA* fila);











