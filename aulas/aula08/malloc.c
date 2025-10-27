// estudando alocação dinámica de memória
//memory alocation(malloc) delimita para o sistema o espaço de memória a ser ocupado
// malloc determina um espaço para memória mas não libera o espaço caso ja eteja alocado com algum dado
// size_t (variável para inteiros positivos), malloc(size_t) não existe valor de memória negativo
#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *p = (int*) malloc(sizeof(int)); // int *p = malloc(10 * sizeof(int));
    *p = 100;
    printf("%i",*p);
// utilizando casting para o void *p
return 0;
}