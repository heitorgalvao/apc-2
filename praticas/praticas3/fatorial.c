#include <stdio.h>

long long fatorial(int numero) {
    if (numero < 0) {
        printf("Nao e possivel calcular o fatorial de um numero negativo.\n");
        return -1;
    }
    if (numero == 0) {
        return 1;
    }
    long long fatorial = 1;
    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    return fatorial;
}

int main() {
    int num1;
    printf("insira um numero para o calculo de fatorial: ");
    scanf("%d" , &num1);
    printf("O fatorial de %d e: %lld\n", num1, fatorial(num1));
    return 0;
}