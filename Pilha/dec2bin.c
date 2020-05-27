#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    int result;
    puts("Digite o número que deseja converter:");    
    scanf("%d",&result);
    PILHA *bin = criaPilha();
    while (result != 0 && result != 1){
        push(bin,result%2);        
        result = (int) result/2;
    }
    printf("Binário: ");
    if(result==1)
        printf("%d",result);
    while(!vazia(bin))
        printf("%d",pop(bin));
    printf("\n");
}
