#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* prox;
};

typedef struct node NODE;

/*
FUNÇÃO: criaLista
RESUMO: Cria uma nova lista vazia
PARAM: void
RETORNO: NODE* (ponteiro para uma nó da lista)
*/
NODE* criaLista(){
	//lista começa vazia logo não aponta para nada
	puts("Lista criada com sucesso");
	return NULL;
}


/*
FUNÇÃO: vazia
RESUMO: verifica se lista está vazia
PARAM: NODE* lista (ponteiro para início da lista)
RETORNO: int (valor de teste para a condição de vazio)
*/
int vazia(NODE *lista){
	if(lista)
		return 0;
	else{
		return 1;
	}
}

/*
FUNÇÃO: insereInicio
RESUMO: insere novo elemento no início da lista
PARAM:
	NODE* lista (começo da lista)
	int valor (dado a ser inserido)
RETORNO: NODE* (ponteiro para o novo início da lista)
*/
NODE* insereIni(NODE *lista, int valor){
	NODE* novo = (NODE*) malloc(sizeof(NODE));
	novo->info = valor;
	novo->prox = lista;
	return novo; //análogo a "lista = novo", caso a função não tivesse retorno
}


/*
FUNÇÃO: insereFim
RESUMO: insere novo elemento no fim da lista
PARAM:
	NODE* lista (começo da lista)
	int valor (dado a ser inserido)
	RETORNO:  NODE* (ponteiro para novo início da lista, caso seja a primeira inserção)
*/
NODE* insereFim(NODE* lista, int valor){
	NODE* aux; //ponteiro para percorrer lista
	NODE* novo = (NODE*) malloc(sizeof(NODE)); //ponteiro para novo elemento
	novo->info = valor;
	novo->prox = NULL;//aponta para null pois é inserido no fim
	aux = lista;
	if(!vazia(lista)){
		while (aux->prox != NULL){//vai até o ultimo elemento
			aux = aux->prox;
		}
		aux->prox = novo;//aponta para novo (agora novo é o último)
	}else{
        //trata o caso da lista vazia, insere o primeiro elemento
		lista = novo;
	}
	return lista;
}

/*
FUNÇÃO: insereOrd
RESUMO: insere novo elemento de maneira ordenada
PARAM:
	NODE* lista (começo da lista), int valor (valor a ser inserido)
	RETORNO: NODE* (ponteiro para início da lista, caso o elemento seja o primeiro)
*/
NODE* insereOrd(NODE* lista, int valor){
	NODE* ant = NULL;
	NODE* aux = lista;
	NODE* novo = (NODE*) malloc(sizeof(NODE));
	novo->info = valor;
	//percorre lista e procura onde encaixar o elemento
	while(aux!=NULL && aux->info < valor){
		ant = aux;
		aux = aux->prox;
	}//se valor for menor que o info armazenado em aux, está exatamente entre o ant e o aux
	//caso seja o primeiro elemento
	if(ant == NULL){
		novo->prox = lista;
		lista = novo;
	}else{ //insere no meio ou final
		novo->prox = aux;
		ant->prox = novo;
	}
	return lista;
}


/*
FUNÇÃO: printLista
RESUMO: Percorre e imprime o conteúdo de toda a lista
PARAM:
	NODE* lista (começo da lista)
	RETORNO: void (nada)
*/
void printLista(NODE* lista){
    if(vazia(lista))
        puts("Lista está vazia!\n");
    else{
        NODE* aux;
	    aux = lista;
	    while (aux){ //equivalente a (aux != NULL)
			printf(" %d ->",aux->info);
			aux = aux->prox;
		}
		puts("|X|");
    }
}

/*
FUNÇÃO: removeInicio
RESUMO: remove o primeiro nó da lista
PARAM:
	NODE* lista (começo da lista)
	RETORNO: NODE* (ponteiro para a novo início da lista)
*/
NODE* removeIni(NODE* lista){
	NODE* aux;
		aux = lista;
		lista = lista->prox;
		free(aux);
		return lista;
}


/*
FUNÇÃO: removeFim
RESUMO: remove o último nó da lista
PARAM:
	NODE* lista (começo da lista)
	RETORNO: NODE* (ponteiro para início da lista, caso haja apenas um elemento)
*/
NODE* removeFim(NODE* lista){
	NODE* ant=NULL;
	NODE* aux=lista;
    //percorre a lista até o final
	while(aux->prox != NULL){
		ant = aux;
		aux = aux->prox;
	}
	if(ant == NULL){ //Se ant == NULL ( ou aux == lista) quer dizer que só tem um elemento
		free(aux);
		lista=NULL;
	}else{
        //caso em que possui mais elementos
		ant->prox = NULL;
		free(aux);
	}
	return lista;
}

/*
FUNÇÃO: removeElem
RESUMO: remove o elemento com valor buscado
PARAM:
	NODE* lista (começo da lista), int valor (valor a ser buscado)
	RETORNO: NODE* (ponteiro para início da lista, caso o elemento seja o primeiro)
*/
NODE* removeElem(NODE* lista, int valor){
	NODE* ant=NULL;
	NODE* aux=lista;
	//percorre a lista até o fim
	while(aux && aux->info != valor){
		ant = aux;
		aux = aux->prox;
	}//se o valor for encontrado a condição não é satisfeita, e a posição onde aponta aux é a que deve ser removida
     //se aux chega em NULL significa que toda lista foi percorrida e o elemento não foi encontrado

	if(aux){//se achou o elemento
	    //verifica se foi o primeiro elemento
	    if(ant == NULL){ //se ant == NULL (ou aux = lista), o elemento é o primeiro da lista, atualiza a cabeça
		    lista = lista->prox;
		    free(aux);
	    }else{ //elemento está no meio ou no fim
		    ant->prox = aux->prox;
	    	free(aux);
	    }
    }else
        puts("Elemento não encontrado!\n");
	return lista;
}

/*
FUNÇÃO: buscaElem
RESUMO: remove o elemento com valor buscado
PARAM:
	NODE* lista (começo da lista), int valor (valor a ser buscado)
	RETORNO: NODE* (Ponteiro no qual se encontra o elemento)
*/
NODE* buscaElemento(NODE* lista, int valor){
	NODE* aux=lista;
	//percorre a lista até o fim
	while(aux != NULL && aux->info != valor){
		aux = aux->prox;
	} //se o valor for encontrado a condição não é satisfeita
	//verifica se não encontrou
	return aux;
}

/*
FUNÇÃO: editaElem
RESUMO: Edita o conteúdo do nó apontado pelo ponteiro passado como parâmetro
PARAM:
	NODE* edit (ponteiro para o nó a ter o conteúdo editado)
	RETORNO: void (não retorna nada, apenas edita o conteúdo)
*/
void editaElem(NODE* edit, int valor){
    edit->info = valor;
}

/*
FUNÇÃO: destroiLista
RESUMO: destroi elementos da lista e libera o espaço de memória
PARAM:
	NODE* lista (começo da lista a ser destruída)
	RETORNO: void (não retorna nada, pois a lista é destruída)
*/
void destroiLista(NODE* lista){
	NODE* aux=lista;
	while(aux != NULL){
		lista = lista->prox;
		free(aux);
		aux = lista;
	}
	aux = NULL;
	lista = NULL;
	puts("lista destruída com sucesso");
}


/*
FUNÇÃO: inverte
RESUMO: Inverte a ordem dos elementos de uma lista
	PARAM: NODE* lista (começo da lista a ser invertida)
	RETORNO: NODE* (Nó para nova cabeça da lista invertida)
*/
NODE* inverte(NODE* lista){
    if(!vazia(lista)){
        NODE* aux = lista;
        NODE* ant = NULL;
        //passo 1: encontrar o final da lista
        while(aux->prox){
            ant = aux;
            aux = aux->prox;
        }//no final do laço, aux estará no último elemento da lista
        //passo 2: posicionar o final
        NODE* fim = aux;
        //passo 3: invertendo elementos interação por interação
        while(aux!=lista){
            ant = lista;
            while(ant->prox!=aux){
                ant = ant->prox;
            }
            aux->prox = ant;
            aux = ant;
        }
        //passo 4: atualiza o fim e o começo da lista
        aux->prox = NULL;
        lista = fim;
    }
    return lista;
}

NODE* concatena(NODE* L1, NODE* L2){
    NODE* aux = L1;
    if (!vazia(L1)){
        while(aux->prox)
            aux = aux->prox;
        aux->prox = L2;
    }
    return L1;
}

int ehSublista(NODE* L1, NODE* L2){
    NODE* aux1 = L1;
    while(aux1){
        NODE* test = aux1;
        NODE* aux2 = L2;
        while(aux2 && aux2->info == test->info){
            aux2 = aux2->prox;
            test = test->prox;
        }
        if(vazia(aux2)){
            puts("É sublista!");
            return 1;
        }
        aux1 = aux1->prox;
    }
    return 0;
}

float media(NODE* lista){
    float soma=0;
    float nNos = 0;
    NODE* aux;
    while(aux){
        nNos = nNos+1;
        soma = soma + (float)aux->info;
        aux = aux->prox;
    }
    return soma/nNos;
}

int menor(NODE* lista){
    NODE* aux = lista;
    int menor = aux->info;
    while(aux){
        if(aux->info < menor)
            menor = aux->info;
        aux = aux->prox;
    }
    return menor;
}


int maior(NODE* lista){
    NODE* aux = lista;
    int maior = aux->info;
    while(aux){
        if(aux->info > maior)
            maior = aux->info;
        aux = aux->prox;
    }
    return maior;
}

NODE* menorNode(NODE* lista){
    NODE* aux = lista;
    NODE* menor = aux;
    while(aux){
        if(aux->info < menor->info)
            menor = aux;
        aux = aux->prox;
    }
    return menor;
}


NODE* maiorNode(NODE* lista){
    NODE* aux = lista;
     NODE* maior = aux;
    while(aux){
        if(aux->info > maior->info)
            maior = aux;
            aux = aux->prox;
    }
    return maior;
}
