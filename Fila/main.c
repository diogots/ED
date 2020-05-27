#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    FILA* f;
    f = criaFila();
    for(int i=0;i<10;i++)
        enqueue(f,i);
    imprimeFila(f);
    removePares(f);
    removeImpares(f);
    imprimeFila(f);
    
    
    
}
