#include <stdio.h>
#include <stdlib.h>

//nó de dados para a fila
struct node{
    int info;
    int pri; //quanto menor o valor, maior a prioridade
    struct node* prox;
};
typedef struct node NODE;

//estrutura da fila

struct fila{
    NODE *inicio;
    NODE *final;
};
typedef struct fila FILA;

/*////////////
// FUNÇÃO: criaFila
// PARAM: Nenhum
// RETORNO: Ponteiro para a fila criada
// RESUMO: Cria uma nova fila vazia e retorna uma ponteiro para ela
//////////////*/
FILA* criaFila(){
    FILA* fila = (FILA*) malloc(sizeof(FILA));
    fila->inicio = NULL;
    fila->final = NULL;
    //puts("Fila criada com sucesso!");
    return fila;    
}

/*////////////
// FUNÇÃO: vazia
// PARAM: FILA* - ponteiro pra fila que queremos verificar
// RETORNO: int
// RESUMO: testa  retorna (1) se a fila estiver vazia ou (0) caso contrário
//////////////*/
int vazia(FILA* fila){
    if(fila->inicio)
        return 0;
    else{ 
        //puts("A fila está vazia");        
        return 1;
    }        
}

/*/////////////////////
// FUNÇÃO: enqueue
// PARAM: FILA* (ponteiro para a fila), int (valor a ser emfileirado);
// RETORNO: void
// RESUMO: insere novo elemento no final da fila 
//////////////////////*/
void enqueuePri(FILA* fila, int valor, int prioridade){
    NODE* novo = (NODE*) malloc(sizeof(NODE));
    novo->info = valor;
    novo->pri = prioridade;
    if(!vazia(fila)){
        NODE* aux = fila->inicio;
        NODE* ant = NULL;
        if(novo->pri < fila->inicio->pri){ 
            novo->prox = fila->inicio;
            fila->inicio = novo;
        }else{
            while(aux && novo->pri >= aux->pri){
                ant = aux;
                aux = aux->prox;                            
            }
            ant->prox = novo;
            novo->prox = aux;
            if(novo->prox == NULL)
                fila->final = novo;
        }
    }else{
        fila->final = novo;
        fila->inicio = novo;
    }
    //printf("Elemento %d inserido ao fim da fila\n",valor);
}

void enqueue(FILA* fila, int valor){
    NODE* novo = (NODE*) malloc(sizeof(NODE));
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

/*/////////////////////
// FUNÇÃO: dequeue
// PARAM: FILA* - ponteiro para a fila que iremos remover um elemento do início
// RETORNO: (int) - Valor do elemento removido
// RESUMO: remove um elemento do início da fila retornando seu valor
//////////////////////*/
int dequeue(FILA* fila){
    int valor;
    if(!vazia(fila)){
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

/*/////////////////////
// FUNÇÃO: first
// PARAM: FILA* - ponteiro para a fila que iremos consultar o primeiro elemento
// RETORNO: (int) - Valor do elemento consultado
// RESUMO: retorna o valor do elemento do início da fila
//////////////////////*/
int first(FILA* fila){
    if(!vazia(fila))
        return fila->inicio->info;
}

void editFirst(FILA *fila, int valor){
    if(!vazia(fila))
        fila->inicio->info = valor;
}

/*/////////////////////
// FUNÇÃO: destroiFila
// PARAM: FILA* - ponteiro para a fila que iremos esvaziar
// RETORNO: void
// RESUMO: destrói todo conteúdo da fila
//////////////////////*/
void destroiFila(FILA *fila){
    while(!vazia(fila)){
        dequeue(fila);
    }
}

void removePares(FILA* fila){
    FILA* aux = criaFila();
    //esvazio fila, encho aux    
    while(!vazia(fila)){
        if(first(fila)%2!=0) //se for ímpar
            enqueue(aux,dequeue(fila)); //enfileiro na fila aux    
        else
            dequeue(fila); //desprezo
    }
    //pronto, agora esvazio aux e repreencho a fila
    while(!vazia(aux)){
        enqueue(fila,dequeue(aux));
    }
    free(aux);
}

void removeImpares(FILA* fila){
    FILA* aux = criaFila();
    //esvazio fila, encho aux    
    while(!vazia(fila)){
        if(first(fila)%2==0) //se for ímpar
            enqueue(aux,dequeue(fila)); //enfileiro na fila aux    
        else
            dequeue(fila); //desprezo
    }
    //pronto, agora esvazio aux e repreencho a fila
    while(!vazia(aux)){
        enqueue(fila,dequeue(aux));
    }
    free(aux);
}

void imprimeFila(FILA* fila){
    FILA* aux = criaFila();
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











