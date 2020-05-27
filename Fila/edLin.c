#include <stdio.h>
#include <stdlib.h>
#include "TADs.c"

FILA* criaFila(){
    FILA* fila = (FILA*) malloc(sizeof(FILA));
    fila->inicio = NULL;
    fila->final = NULL;
    //puts("Fila criada com sucesso!");
    return fila;    
}

int vaziaF(FILA* fila){
    if(fila->inicio)
        return 0;
    else{ 
        //puts("A fila está vazia");        
        return 1;
    }        
}

void enqueue(FILA* fila, int valor){
    NODE* novo = (NODE*) malloc(sizeof(NODE));
    novo->info = valor;
    novo->prox = NULL; //novo inserido na última posição
    if(!vaziaF(fila)){
        (fila->final)->prox = novo;
        fila->final = novo;
    }else{
        fila->final = novo;
        fila->inicio = novo;
    }
    //printf("Elemento %d inserido ao fim da fila\n",valor);
}

int dequeue(FILA* fila){
    int valor;
    if(!vaziaF(fila)){
        NODE* aux = fila->inicio; // nó a ser desenfileirado
        valor = aux->info; //recupera a informação do nó
        //atualiza o início e final da fila        
        if(fila->inicio != fila->final)
            fila->inicio = (fila->inicio)->prox;
        else{
            fila->inicio = NULL;
            fila->final = NULL;
        }
        free(aux); //libera o nó 
    }
    return valor; //retorna a informação
}


int first(FILA* fila){
    if(!vaziaF(fila))
        return fila->inicio->info;
}


void destroiFila(FILA *fila){
    while(!vaziaF(fila)){
        dequeue(fila);
    }
}


PILHA* criaPilha(){
    PILHA* p;
    p = (PILHA*) malloc(sizeof(PILHA)); //aloco o espaço da estrutura na memória
    p->topo = NULL; //pilha inicia vazia
    //puts("Pilha criada com sucesso!");
    return p;
}


int vaziaP(PILHA* pilha){
    if(pilha->topo)
        return 0;
    else{
        //puts("A pilha está vazia!");
        return 1;
    }
}


void push(PILHA* pilha, int valor){
    NODE* novo = (NODE*) malloc(sizeof(NODE));
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    //printErr(pilha);
}


int pop(PILHA* pilha){
    NODE* aux = pilha->topo;
    int valor;
    if(!vaziaP(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        free(aux);
    }
    //printErr(pilha);
    return valor;
}


int top(PILHA* pilha){
    if(!vaziaP(pilha))
        return ((pilha->topo)->info);
}


void destroiPilha(PILHA* pilha){
    while(!vaziaP(pilha))
        pop(pilha);
}

void printFila(FILA* fila){
    FILA* aux = criaFila();
    //esvazio fila, encho aux    
    printf("fila:");    
    while(!vaziaF(fila)){
        printf("%d -> ",first(fila));          
        enqueue(aux,dequeue(fila)); //enfileiro na fila aux    
    }
    //pronto, agora esvazio aux e repreencho a fila
    while(!vaziaF(aux)){
        enqueue(fila,dequeue(aux));
    }
    puts("||");
    free(aux);
}

void printPilha(PILHA* pilha){
    if(!vaziaP(pilha)){
        PILHA* aux = criaPilha();
        printf("pilha:");
        while(!vaziaP(pilha)){ //enquanto não esvaziei minha pilha principal
            printf(" %d ->",top(pilha));
            push(aux,pop(pilha)); //empilho na auxiliar o conteúdo que desempilhei da principal
        }
        printf(" |X| \n");
        while(!vaziaP(aux))
            push(pilha,pop(aux));
    }
}
