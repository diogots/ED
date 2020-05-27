#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
/*
    NODE* lista;
    lista = criaLista();
    lista = insereIni(lista,6);
    lista = insereIni(lista,4);
    lista = insereIni(lista,7);
    printLista(lista);
    lista = inverte(lista);
    printLista(lista);
*/

	NODE *l1,*l2;
	l1 = criaLista();
	l2 = criaLista();
	l1 = insereIni(l1,23);
	l1 = insereIni(l1,20);
	l1 = insereIni(l1,10);
	l2 = insereIni(l2,10);
	printLista(l1);
	printLista(l2);
	int resp = ehSublista(l1,l2);
    printf("\n %d",resp);

/*
	l = criaLista();
	if (vazia(l)){
		puts ("Lista criada com sucesso");
	}
	printLista(l);
	l = insereIni(l,20);
	l = insereIni(l,50);
	l = insereIni(l,2);
	l = insereIni(l,10);
	printLista(l);
	l = removeIni(l);
	printLista(l);
	insereFim(l,35);
	printLista(l);
	l = inverte(l);
	printLista(l);
*/
return 0;
}
