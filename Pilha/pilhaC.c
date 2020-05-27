#include <stdio.h>
#include <stdlib.h>

struct nodeC{
    char info;
    struct nodeC *prox;
};
typedef struct nodeC NODEC; //declaração do tipo NODE

///////////////////////////////
/* Estrutura de pilha: 
/  Contém um campo com um ponteiro para o topo da pilha
*/
//////////////////////////////
struct pilhaC{
    NODEC* topo;
};
typedef struct pilhaC PILHAC;

PILHAC* criaPilha(){
    PILHAC* p;
    p = (PILHAC*) malloc(sizeof(PILHAC)); //aloco o espaço da estrutura na memória
    p->topo = NULL; //pilha inicia vazia
    //puts("Pilha criada com sucesso!");
    return p;
}

int vazia(PILHAC* pilha){
    if(pilha->topo)
        return 0;
    else{
        //puts("A pilha está vazia!");
        return 1;
    }
}

void push(PILHAC* pilha, char valor){
    NODEC* novo = (NODEC*) malloc(sizeof(NODEC));
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    //printErr(pilha);
}
char pop(PILHAC* pilha){
    NODEC* aux = pilha->topo;
    char valor;
    if(!vazia(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        free(aux);
    }
    //printErr(pilha);
    return valor;
}
char top(PILHAC* pilha){
    if(!vazia(pilha))
        return ((pilha->topo)->info);
}
void destroiPilha(PILHAC* pilha){
    while(!vazia(pilha))
        pop(pilha);
}

void printPilha(PILHAC* pilha){
    if(!vazia(pilha)){
        PILHAC* aux = criaPilha();
        printf("topo:");
        while(!vazia(pilha)){ //enquanto não esvaziei minha pilha principal
            printf(" %c ",top(pilha));
            push(aux,pop(pilha)); //empilho na auxiliar o conteúdo que desempilhei da principal
        }
        printf("\n");
        while(!vazia(aux))
            push(pilha,pop(aux));
    }
}

