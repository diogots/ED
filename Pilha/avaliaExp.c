#include <stdio.h>
#include <stdlib.h>
#include "pilhaC.h"

int main(){
    char exp[100];
    PILHAC* verif = criaPilha();
    scanf("%[^\n]s",exp);
    int i=0;
    char c = exp[i];
    int erro = 0;
    while( c != '\0'){
        if(c == '(')
            push(verif,c);
        if(c == ')'){
            if(vazia(verif)){
                erro = 1;
                break;
            }
            else pop(verif);        
        }
        //avançar a leitura
        i++;
        c = exp[i];
    }
    if(!vazia(verif))
        erro = 1;
    
    if(erro)
        puts("A expressão contém erros!");
    else puts("A expressão está correta!");
    
}
