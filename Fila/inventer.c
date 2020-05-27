#include <stdio.h>
#include <stdlib.h>
#include "TADs.c"
#include "edLin.h"

int main(){
    FILA *f = criaFila();
    PILHA *p = criaPilha();
    int in;
    do{
        scanf("%d",&in);
        enqueue(f,in);
    }while(in != 0);
    printFila(f);
    //inventer usando a pilha    
    while(!vaziaF(f))
        push(p,dequeue(f));
    //retornar para a fila
    while(!vaziaP(p))
        enqueue(f,pop(p));
    printFila(f);
}

