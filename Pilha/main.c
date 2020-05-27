#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    PILHA *p;
    p = criaPilha();
    vazia(p);
    push(p,12);
    push(p,24);
    push(p,12);
    push(p,24);
    push(p,25);
    printPilha(p);
    removePares(p);
    printPilha(p);
}
