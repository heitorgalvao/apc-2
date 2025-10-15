#include <stdio.h>

int fatorial(int x){
    int resultado;

    if(x == 0){
        resultado = 1;
    }else{
        resultado = x * fatorial(x - 1);
    }
    return resultado;
}

int main (){

    int fatorial(int x);
    int numero , resultado;

    printf("digite um numero inteiro: ");
    scanf("%i", &numero);

    resultado = fatorial(numero);

    printf(" o fatorial eh %i", resultado);


    return 0;
}