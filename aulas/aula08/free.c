#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *p = (int*) malloc(sizeof(int)); 
    *p = 100;
    printf("%i",*p);

    free(p);// libera o espaço de memória mas não apaga o que estiver alocado.

return 0;
}