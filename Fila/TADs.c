struct node{
    int info;
    struct node* prox;
};
typedef struct node NODE;

//estrutura da fila

struct fila{
    NODE *inicio;
    NODE *final;
};
typedef struct fila FILA;

struct pilha{
    NODE *topo;
};
typedef struct pilha PILHA;
