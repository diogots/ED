#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

main(){
    PILHA *p;
    p = criaPilha();
    vazia(p);
    push(p,12);
    push(p,14);
    printErr(p);
    printf("removido: %d \n",pop(p));
    printPilha(p);
    push(p,14);
    printPilha(p);
    printf("topo atual: %d \n",top(p));
    destroiPilha(p);
    vazia(p);
}
