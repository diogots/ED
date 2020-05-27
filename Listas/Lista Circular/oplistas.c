#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


main(){
	NODE *l;
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
}
