#include <stdio.h>

long long apertos(int n) {
    if (n <= 1) {
        return 0;
    }
    return (long long)n * (n - 1) / 2;
}

int main() {
    int pessoas;

    printf("Digite o numero total de pessoas na sala: ");
    
    if (scanf("%d", &pessoas) != 1 || pessoas < 0) {
        printf("Entrada inválida. Por favor, digite um número inteiro não negativo.\n");
        return 1;
    }
    long long total_apertos = apertos(pessoas);

    printf("\nPara %d pessoas, existirao %lld apertos de maos no total.\n", pessoas, total_apertos);

    return 0;
}