#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////
/* Estrutura nó de pilha: 
/  Contém um campo de informação (chave) do tipo inteiro para efeitos didáticos
/  e também contém um ponteiro para o próximo nó de informação    
*/
//////////////////////////////
struct node{
    char info[100];
    struct node *prox;
};
typedef struct node NODE; //declaração do tipo NODE

///////////////////////////////
/* Estrutura de pilha: 
/  Contém um campo com um ponteiro para o topo da pilha
*/
//////////////////////////////
struct pilha{
    NODE* topo;
};
typedef struct pilha PILHA;


///////////////////////////////
/* Função: criaPilha() 
/  PARAM: nenhum
/  RETORNO: Um ponteiro para a pilha criada
/  RESUMO: Cria um ponteiro para um pilha vazia
/////////////////////////////*/
PILHA* criaPilha(){
    PILHA* p;
    p = (PILHA*) malloc(sizeof(PILHA)); //aloco o espaço da estrutura na memória
    p->topo = NULL; //pilha inicia vazia
    //puts("Pilha criada com sucesso!");
    return p;
}

///////////////////////////////
/* Função: vaziaPilha() 
/  PARAM: Ponteiro para a pilha que se quer verificar
/  RETORNO: Inteiro sendo (1) se a pilha estver vazia ou (0) caso contrário
/  RESUMO: Retorna um valor lógico que indica se a pilha está vazia ou não
/////////////////////////////*/
int vazia(PILHA* pilha){
    if(pilha->topo)
        return 0;
    else{
        //puts("A pilha está vazia!");
        return 1;
    }
}

void push(PILHA* pilha, char *valor){
    NODE* novo = (NODE*) malloc(sizeof(NODE));
    strcpy(novo->info,valor);
    novo->prox = pilha->topo;
    pilha->topo = novo;
    //printErr(pilha);
}

char* pop(PILHA* pilha){
    NODE* aux = pilha->topo;
    char valor[100];
    if(!vazia(pilha)){
        strcpy (valor, aux->info);
        pilha->topo = (pilha->topo)->prox;
        free(aux);
    }
    //printErr(pilha);
    return valor;
}

char* top(PILHA* pilha){
    if(!vazia(pilha))
        return ((pilha->topo)->info);
}



