#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pilhaC.h"

int main(){
    PILHAC* fNum = criaPilha();
    char nStr[30] = "";
    char alg;
    char exp[1000];
    puts("Digite a expressão que deseja avaliar");
    scanf("%[^\n]s",exp);
    int i=0;
    while(exp[i] != '\0'){
        if(isdigit(exp[i]))
            push(fNum,exp[i]);
        else{
            puts("caractere inválido");
            break;
        }
        i++;
    }
    printPilha(fNum);
    //converte char pra str
    char cnv[2];
    cnv[1] = '\0';
    
    int numConv = 0;
    i = 0;
    while(!vazia(fNum)){
        cnv[0] = pop(fNum);
        numConv = numConv + atoi(cnv)*pow(10,i);
        i++;  
    }
    printf("Número convertido: %d",numConv);
}






    

