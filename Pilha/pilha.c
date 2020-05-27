#include <stdio.h>
#include <stdlib.h>

///////////////////////////////
/* Estrutura nó de pilha: 
/  Contém um campo de informação (chave) do tipo inteiro para efeitos didáticos
/  e também contém um ponteiro para o próximo nó de informação    
*/
//////////////////////////////
struct node{
    int info;
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

/////função de imprimir irregular ////////
void printErr(PILHA* pilha){
    NODE* aux = pilha->topo;
    if(!vazia(pilha)){
        printf("topo: ");        
        while(aux){
            printf(" %d ->",aux->info);
            aux = aux->prox;
        }
        puts(" |X|");
    }
}


///////////////////////////////
/* Função: push 
/  PARAM: (PILHA* pilha) Ponteiro para a pilha que iremos inserir no topo, (int valor) valor a ser inserido
/  RETORNO: void (o ponteiro para a pilha não se altera, só se altera o ponteiro para o topo dentro da função)
/  RESUMO: Insere um valor no topo da pilha passada como parâmetro 
/////////////////////////////*/
void push(PILHA* pilha, int valor){
    NODE* novo = (NODE*) malloc(sizeof(NODE));
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    //printErr(pilha);
}

///////////////////////////////
/* Função: pop 
/  PARAM: (PILHA* pilha) Ponteiro para a pilha que iremos remover um elemento do topo
/  RETORNO: (int) valor removido do topo da pilha
/  RESUMO: remove um valor do topo da pilha passada como parâmetro 
/////////////////////////////*/
int pop(PILHA* pilha){
    NODE* aux = pilha->topo;
    int valor;
    if(!vazia(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        free(aux);
    }
    //printErr(pilha);
    return valor;
}

///////////////////////////////
/* Função: top 
/  PARAM: (PILHA* pilha) Ponteiro para a pilha que iremos "espiar" o topo
/  RETORNO: (int) valor contido no topo da pilha
/  RESUMO: consulta o valor do topo da pilha passada como parâmetro 
/////////////////////////////*/
int top(PILHA* pilha){
    if(!vazia(pilha))
        return ((pilha->topo)->info);
}

///////////////////////////////
/* Função: destroiPilha 
/  PARAM: (PILHA* pilha) Ponteiro para a pilha que iremos destruir
/  RETORNO: void
/  RESUMO: destrói todo conteúdo da pilha
/////////////////////////////*/
void destroiPilha(PILHA* pilha){
    while(!vazia(pilha))
        pop(pilha);
}

void editarTopo(PILHA* pilha,int valor){
    if(!vazia(pilha))
        (pilha->topo)->info = valor;
}
//------------------------------------------- EXERCíCIOS ------------------------------------
///////////////////////////////
/* Função: printPilha
/  PARAM: (PILHA* pilha) Ponteiro para a pilha que iremos imprimir
/  RETORNO: void
/  RESUMO: imprime todo conteúdo da pilha
/////////////////////////////*/
void printPilha(PILHA* pilha){
    if(!vazia(pilha)){
        PILHA* aux = criaPilha();
        printf("topo:");
        while(!vazia(pilha)){ //enquanto não esvaziei minha pilha principal
            printf(" %d ->",top(pilha));
            push(aux,pop(pilha)); //empilho na auxiliar o conteúdo que desempilhei da principal
        }
        printf(" |X| \n");
        while(!vazia(aux))
            push(pilha,pop(aux));
    }
}

//exercício 1: buscar na pilha
//retorna 1 se achou e zero se não achou
int busca(PILHA* pilha, int valor){
    int retorno = 0;    
    if(!vazia(pilha)){
        PILHA* aux = criaPilha();        
        while (!vazia(pilha)){
            if (valor == top(pilha)){
                retorno = 1;
                break;
            }
            else push(aux,pop(pilha));
        }
        //reempilho a principal
        while(!vazia(aux)){
            push(pilha,pop(aux));
        }
    }
    return retorno;
}

//exercício 2
void buscaRemove1(PILHA* pilha, int valor){  
    if(!vazia(pilha)){
        PILHA* aux = criaPilha();        
        while (!vazia(pilha)){
            if (valor == top(pilha)){
                pop(pilha);
                puts("Removido!");
                break;
            }
            else push(aux,pop(pilha));
        }
        //reempilho a principal
        while(!vazia(aux))
            push(pilha,pop(aux));
    }

}

void buscaRemoveTodas(PILHA* pilha, int valor){  
    if(!vazia(pilha)){
        PILHA* aux = criaPilha();        
        while (!vazia(pilha)){
            if (valor == top(pilha)){
                pop(pilha);
                puts("Removido!");
            }
            else push(aux,pop(pilha));
        }
        //reempilho a principal
        while(!vazia(aux))
            push(pilha,pop(aux));
    }

}

//exercício 3: Remover os número pares
void removePares(PILHA* pilha){  
    if(!vazia(pilha)){
        PILHA* aux = criaPilha();        
        while (!vazia(pilha)){
            if (top(pilha)%2 == 0)
                pop(pilha);
            else push(aux,pop(pilha));
        }
        //reempilho a principal
        while(!vazia(aux))
            push(pilha,pop(aux));
    }
}

void removeImpares(PILHA* pilha){  
    if(!vazia(pilha)){
        PILHA* aux = criaPilha();        
        while (!vazia(pilha)){
            if (top(pilha)%2 != 0)
                pop(pilha);
            else push(aux,pop(pilha));
        }
        //reempilho a principal
        while(!vazia(aux))
            push(pilha,pop(aux));
    }
}

// removeRepetidos
void removeRepetidos(PILHA* pilha){
    if(!vazia(pilha)){
        PILHA *aux = criaPilha();
        PILHA* pBusca = criaPilha();
        while(!vazia(pilha)){//enquanto a pilha não estiver vazia
            int valor = top(pilha); //pego o valor do topo
            push(aux,pop(pilha));//empilho na pilha aux
            while(!vazia(pilha)){ //percorro o resto da pilha
                 if(valor == top(pilha)) //se topo(pilha) == valor, então é repetido
                    pop(pilha); //removo repetido
                 else push(pBusca,pop(pilha)); //senão, só empilho na minha pilha de busca          
            }
            //reempilho a principal com a pilha de Busca
            while(!vazia(pBusca))
                push(pilha,pop(pBusca));
        } 
        //reempilho a principal com a aux
        while(!vazia(aux))
            push(pilha,pop(aux));
    }
}






