#include <stdio.h>

void mult_matrizes(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0; 
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m, n, p;

    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas da matriz A e linhas da matriz B: ");
    scanf("%d", &n);
    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &p);

    int A[m][n];
    int B[n][p];
    int C[m][p];

    printf("\nDigite os elementos da matriz A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nDigite os elementos da matriz B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("Elemento B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    mult_matrizes(m, n, p, A, B, C);

    printf("\nA matriz resultante da multiplicacao (C) e:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}