#include <stdio.h>
// analísa o tamanho de um vetor, identifica os maior e o menor número e seu índice.
void min_max(int n, int vet[n], int *min, int *max) {
    if (n <= 0) {
        return;
    }

    *min = 0;
    *max = 0;

    for (int i = 1; i < n; i++) {
        if (vet[i] < vet[*min]) {
            *min = i;
        }

        if (vet[i] > vet[*max]) {
            *max = i;
        }
    }
}
int main(){
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);

    int vet[n];

    printf("Digite os %i numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Numero %i: ", i + 1);
        scanf("%i", &vet[i]);
    }
    int min , max;
    min_max(n, vet, &min, &max);
    printf("\nO menor valor e %i, e esta no indice %i.\n", vet[min], min);
    printf("O maior valor e %i, e esta no indice %i.\n", vet[max], max);

    return 0;
}// está certo mas com o terte que fiz ele começa com número 1 sendo índice zero.