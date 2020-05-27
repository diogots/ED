#include <stdio.h>
#include <stdlib.h>
#include "data.c"

#define ANOMIN 1900
#define ANOMAX 2100
#define DIAMIN 1
#define MESMIN 1
#define MESMAX 12


struct nodePreco{
    float preco;
    DATE data;
    struct nodePreco* prox;
};
typedef struct nodePreco NODEP;



int validaData(int dia, int mes, int ano){
    int diaMax[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int valida = 1;
    //testa ano
    if (ano < ANOMIN || ano > ANOMAX){
        puts("-> Ano inválido");
        valida = 0;
    }
    //testa mes
    if (mes < MESMIN || mes > MESMAX){
        puts("-> Mês inválido");
        valida = 0;
    }
    //testa dia
    if (dia < DIAMIN || dia > diaMax[mes]){
            valida = 0;
            if(dia == 29 && mes == 2 && (ano%400 == 0 || (ano%4 == 0 && ano%100 !=0))){//ano ser bissexto é divisível por 400 ou 4 e não por 100
                valida = 1;
            }else{
                puts("-> Dia inválido");
            }
    }
    if(valida)
        puts("-> Data válida!");

    return valida;
}


/*
FUNÇÃO: criaLista
RESUMO: Cria uma nova lista vazia
PARAM: void
RETORNO: NODEP* (ponteiro para uma nó da lista)
*/
NODEP* criaLista(){
	//lista começa vazia logo não aponta para nada
	return NULL;
}


/*
FUNÇÃO: vazia
RESUMO: verifica se lista está vazia
PARAM: NODEP* lista (ponteiro para início da lista)
RETORNO: float (valor de teste para a condição de vazio)
*/
float vazia(NODEP *lista){
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
	NODEP* lista (começo da lista)
	float valor (dado a ser inserido)
RETORNO: NODEP* (ponteiro para o novo início da lista)
*/
NODEP* insereIni(NODEP *lista, float valor, DATE data){
	NODEP* novo = (NODEP*) malloc(sizeof(NODEP));
	novo->preco = valor;
    novo->data = data;
	novo->prox = lista;
	return novo; //análogo a "lista = novo", caso a função não tivesse retorno
}


////////////////////////// A PARTIR DAQUI, EDITE O QUE JULGAR NECESSÁRIO /////////////////////q
/*
FUNÇÃO: printLista
RESUMO: Percorre e imprime o conteúdo de toda a lista
PARAM:
	NODEP* lista (começo da lista)
	RETORNO: void (nada)
*/
void printLista(NODEP* lista){
    if(vazia(lista))
        puts("Lista de preços está vazia!\n");
    else{
        NODEP* aux;
	    aux = lista;
	    puts("Preços coletados em relação a data:");
	    while (aux){ //equivalente a (aux != NULL)
            printf("%d/%d/%d - ",aux->data.dia,aux->data.mes,aux->data.ano);
			printf(" %.2f \n",aux->preco);
			aux = aux->prox;
		}

    }
}

/*
FUNÇÃO: destroiLista
RESUMO: destroi elementos da lista e libera o espaço de memória
PARAM:
	NODEP* lista (começo da lista a ser destruída)
	RETORNO: void (não retorna nada, pois a lista é destruída)
*/
void destroiLista(NODEP* lista){
	NODEP* aux=lista;
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
FUNÇÃO: editaElem
RESUMO: Edita o conteúdo do nó apontado pelo ponteiro passado como parâmetro
PARAM:
	NODEP* edit (ponteiro para o nó a ter o conteúdo editado)
	RETORNO: void (não retorna nada, apenas edita o conteúdo)
*/
void editaElem(NODEP* edit, float valor, DATE dt){
    if(edit!=NULL){
        edit->preco = valor;
        edit->data.dia = dt.dia;
        edit->data.mes = dt.mes;
        edit->data.ano = dt.ano;
        puts("Dados editados com sucesso!");
    }
}

/*
FUNÇÃO: removeElem
RESUMO: remove o elemento com valor buscado
PARAM:
	NODEP* lista (começo da lista), float valor (valor a ser buscado)
	RETORNO: NODEP* (ponteiro para início da lista, caso o elemento seja o primeiro)
*/
/*
FUNÇÃO: buscaElem
RESUMO: remove o elemento com valor buscado
PARAM:
	NODEP* lista (começo da lista), float valor (valor a ser buscado)
	RETORNO: NODEP* (Ponteiro no qual se encontra o elemento)
*/
NODEP* buscaElemento(NODEP* lista, DATE dt){
	NODEP* aux=lista;
	//percorre a lista até o fim
	while(aux != NULL && (aux->data.ano != dt.ano && aux->data.mes != dt.mes && aux->data.dia != dt.dia))
		aux = aux->prox;
	//se o valor for encontrado a condição não é satisfeita
	//verifica se não encontrou
	return aux;
}

NODEP* buscaMenor(NODEP* lista){
    NODEP* menor = lista;
    NODEP* aux = lista;
    while(aux){
        if(aux->preco < menor->preco)
            menor = aux;
        aux = aux->prox;
    }
    return menor;
}

NODEP* buscaMaior(NODEP* lista){
    NODEP* maior = lista;
    NODEP* aux = lista;
    while(aux){
        if(aux->preco > maior->preco)
            maior = aux;
        aux = aux->prox;
    }
    return maior;
}

float mediapreco(NODEP* lista){
    float soma = 0.0;
    int n=0;
    NODEP* aux = lista;
    while(aux){
        n++;
        soma = soma + aux->preco;
        aux = aux->prox;
    }
    float media = (float)soma/n;
    return media;
}

void imprimeRelatorio(NODEP* lista){
    NODEP *maior, *menor;
    float media;
    menor = buscaMenor(lista);
    maior = buscaMaior(lista);
    media = mediapreco(lista);
    puts("Relatório de preços no período:");
    printf("Menor preço: %.2f no dia %d/%d/%d\n",menor->preco,menor->data.dia,menor->data.mes, menor->data.ano);
    printf("Maior preço: %.2f no dia %d/%d/%d\n",maior->preco,maior->data.dia,maior->data.mes, maior->data.ano);
    printf("Média de preço no período: %.2f\n",media);
    //implemente a impressão do relatório como específicado na descrição do trabalho
}

