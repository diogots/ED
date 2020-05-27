#include <stdio.h>
#include <stdlib.h>

//nó de dados para a fila
struct nodeC{
    char info;
    struct nodeC* prox;
};
typedef struct nodeC NODEC;

//estrutura da fila

struct filaC{
    NODEC *inicio;
    NODEC *final;
};
typedef struct filac FILAC;

/*////////////
// FUNÇÃO: criaFila
// PARAM: Nenhum
// RETORNO: Ponteiro para a fila criada
// RESUMO: Cria uma nova fila vazia e retorna uma ponteiro para ela
//////////////*/
FILAC* criaFila(){
    FILAC* fila = (FILAC*) malloc(sizeof(FILAC));
    fila->inicio = NULL;
    fila->final = NULL;
    //puts("Fila criada com sucesso!");
    return fila;
}

/*////////////
// FUNÇÃO: vazia
// PARAM: FILAC* - ponteiro pra fila que queremos verificar
// RETORNO: char
// RESUMO: testa  retorna (1) se a fila estiver vazia ou (0) caso contrário
//////////////*/
int vazia(FILAC* fila){
    if(fila->inicio)
        return 0;
    else{
        //puts("A fila está vazia");
        return 1;
    }
}

/*/////////////////////
// FUNÇÃO: enqueue
// PARAM: FILAC* (ponteiro para a fila), int (valor a ser emfileirado);
// RETORNO: void
// RESUMO: insere novo elemento no final da fila
//////////////////////*/
void enqueue(FILAC* fila, char valor){
    NODEC* novo = (NODEC*) malloc(sizeof(NODEC));
    novo->info = valor;
    novo->prox = NULL; //novo inserido na última posição
    if(!vazia(fila)){
        (fila->final)->prox = novo;
        fila->final = novo;
    }else{
        fila->final = novo;
        fila->inicio = novo;
    }
    //printf("Elemento %d inserido ao fim da fila\n",valor);
}

char dequeue(FILAC* fila){
    char valor;
    if(!vazia(fila)){
        NODEC* aux = fila->inicio; // nó a ser desenfileirado
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

char first(FILAC* fila){
    if(!vazia(fila))
        return fila->inicio->info;
}

void destroiFila(FILAC *fila){
    while(!vazia(fila)){
        dequeue(fila);
    }
}


void imprimeFila(FILAC* fila){
    FILAC* aux = criaFila();
    //esvazio fila, encho aux
    printf("fila:");
    while(!vazia(fila)){
        printf("%d -> ",first(fila));
        enqueue(aux,dequeue(fila)); //enfileiro na fila aux
    }
    //pronto, agora esvazio aux e repreencho a fila
    while(!vazia(aux)){
        enqueue(fila,dequeue(aux));
    }
    puts("||");
    free(aux);
}
#ifndef FILAC_H_INCLUDED
#define FILAC_H_INCLUDED



#endif // FILAC_H_INCLUDED
