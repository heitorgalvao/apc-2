#include <stdio.h>
int main(void){
    int numero;
    int *p_numero;

    p_numero = &numero;

    *p_numero = 5;

     printf("(*p (i - valor da variável número): %d\n", numero);
     return 0;
}