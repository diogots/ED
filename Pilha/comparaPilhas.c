#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int compara(PILHA* p1, PILHA* p2){
    PILHA *ax1, *ax2;
    ax1 = criaPilha();
    ax2 = criaPilha();
    int igual=1;
    while(!vazia(p1) && !vazia(p2)){
        if(top(p1)==top(p2)){
            push(ax1,pop(p1));
            push(ax2,pop(p2));        
        }else{
            igual = 0;
            break;
        }
    }
    if(!vazia(p1))
        igual = 0;
    
    if(!vazia(p2))
        igual = 0;
    
    //reorganizar as pilhas originais
    while(!vazia(ax1))
        push(p1,pop(ax1));
    
    while(!vazia(ax2))        
        push(p2,pop(ax2));
    
    return igual;
}

main(){
    PILHA *p1, *p2;
    p1 = criaPilha();
    p2 = criaPilha();
    int in;
    for(int i=0; i<5; i++){
        scanf("%d",&in);
        push(p1,in);
    }
    for(int i=0; i<5; i++){
        scanf("%d",&in);
        push(p2,in);
    }
    puts("---");
    int cmp = compara(p1,p2);
    if(cmp)
        puts("pilhas iguais!");
    else puts("pilhas diferentes!");
}
