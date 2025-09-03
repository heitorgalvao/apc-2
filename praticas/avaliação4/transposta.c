#include<stdio.h>
void transposta(int n, int m, int A[m][n], int T[n][m]){
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
}
     }
    }
int main(){
    int m , n;
    printf("insira a quantidade de linhas da matriz: ");
    scanf("%d", &m);
    printf("\ninsira a quantidade de colunas da matriz: ");
    scanf("%d" , &n);

    int A[m][n];
    int T[n][m];

    printf("\nDigite os elementos da matriz A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
     transposta(m, n, A, T);
     printf("\nA matriz transposta e:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
    return 0;
}