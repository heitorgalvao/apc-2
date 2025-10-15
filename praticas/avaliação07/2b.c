#include <stdio.h>// soma de número i a n

int soma(int n){
    if (n <= 0){
        return 0;
    }
    return n + soma(n - 1);
}
int main(){
    int numero;

    printf("digite qualquer numero interiro:");
    scanf("%i", &numero);

    int resultado = soma(numero);

    printf("a soma recursiva eh: %i", resultado);
    return 0;
}