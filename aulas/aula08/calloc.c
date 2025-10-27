#include <stdio.h>
#include <stdlib.h>
/* ponteiro também pode ser vetor
 calloc(contiguous allocation) em resumo reserva um bloco de memória e inicializa todos os bits com
zero*/
int main (void){
    int *p;
    p = (int*) calloc (5, sizeof(int));
    int i;
        for ( i=0; i<=5; i++){
        printf("endereco de p %i = %p | valor de p%i = %i \n, ",i , (p+1),i, *(p+1));
    }

return 0;
}