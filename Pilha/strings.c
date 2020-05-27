#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaStr.h"

int main(){
    PILHA* p;
    p = criaPilha;    
    char texto[100];
    scanf("%[^\n]s",texto);
    push(p,texto);
    
}
