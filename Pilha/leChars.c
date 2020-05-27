#include <stdio.h>
#include <stdlib.h>
#include "pilhaC.h"

main(){
    PILHAC* p = criaPilha();
    push(p,'o');
    push(p,'l');
    push(p,'a');
    printPilha(p);
}
