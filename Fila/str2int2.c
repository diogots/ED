#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "filaC.h"

int main(){
    FILA* fNum = criaFila();
    char nStr[30] = "";
    char alg;
    char exp[1000];
    puts("Digite a expressão que deseja avaliar");
    scanf("%[^\n]s",exp);
    int i=0;
    while(exp[i] != '\0'){
        if(isdigit(exp[i]))
            enqueue(fNum,exp[i]);
        else{
            puts("caractere inválido");
            break;
        }
        i++;
    }
    printFila(fNum);
    //converte char pra str
    char cnv[2];
    cnv[1] = '\0';
    
    int numConv = 0;
    i--;
    while(!vazia(fNum)){
        cnv[0] = dequeue(fNum);
        numConv = numConv + atoi(cnv)*pow(10,i);
        i--;  
    }
    printf("Número convertido: %d",numConv);
    
}




    

