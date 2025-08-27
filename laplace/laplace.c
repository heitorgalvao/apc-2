#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10

// Função para criar uma submatriz (cofator)
// Ela remove a linha 'p' e a coluna 'q' da matriz 'mat' de tamanho 'n'
// e armazena o resultado na 'submat'.
void getSubmatriz(int mat[MAX_SIZE][MAX_SIZE], int submat[MAX_SIZE][MAX_SIZE], int p, int q, int n) {
    int i = 0, j = 0;
    
    // Itera por cada elemento da matriz original
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Se o elemento não estiver na linha 'p' nem na coluna 'q'
            // ele é copiado para a submatriz
            if (row != p && col != q) {
                submat[i][j++] = mat[row][col];
                
                // Quando a linha da submatriz está cheia
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Função recursiva para calcular o determinante
int calcularDeterminante(int mat[MAX_SIZE][MAX_SIZE], int n) {
    int det = 0;

    // Caso base da recursão: matriz 1x1
    if (n == 1) {
        return mat[0][0];
    }
    
    int submat[MAX_SIZE][MAX_SIZE];
    
    // Itera pelos elementos da primeira linha para o desenvolvimento de Laplace
    for (int j = 0; j < n; j++) {
        // Cria a submatriz, removendo a primeira linha (índice 0) e a coluna 'j'
        getSubmatriz(mat, submat, 0, j, n);
        
        // Calcula o determinante: (-1)^(0+j) * elemento * det da submatriz
        det += pow(-1, j) * mat[0][j] * calcularDeterminante(submat, n - 1);
    }
    
    return det;
}

int main() {
    int n;

    printf("Digite o tamanho da matriz quadrada (n x n, max 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Tamanho da matriz invalido ou excede o limite.\n");
        return 1;
    }

    int matriz[MAX_SIZE][MAX_SIZE];

    printf("Digite os elementos da matriz %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int determinante = calcularDeterminante(matriz, n);
    printf("\nO determinante da matriz eh: %d\n", determinante);

    return 0;
}