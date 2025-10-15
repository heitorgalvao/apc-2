#include <stdio.h>
int mult2(int n ){
    return n * 2;
}
int main(){
    int numero;
    int resultado;
    int tamanho_for;
    printf("digite qualquer numero inteiro: ");
    scanf("%i", &numero);

    printf("digite o limite da sequencia:");
    scanf("%i", &tamanho_for);

    printf("sequencia gerada: ");
    printf("inicio: %i\n", numero);

     for (int i = 0; i < tamanho_for; i++) {
        numero = mult2(numero);
        printf("Passo %d (x2): %i\n", i + 1, numero);
     }
        printf("\nResultado final apos %d multiplicacoes: %i\n", tamanho_for, numero);
    return 0;
}
