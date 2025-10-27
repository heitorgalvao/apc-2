#include <stdio.h>
#include <stdlib.h>

float *medias_das_notas (int m, int n, float matriz [m] [n]) {
    float *medias = (float *) malloc(m * sizeof(float));
    if (medias == NULL) {
        return NULL;
    }
    for (int i = 0; i < m; i++) {
        float soma_notas = 0.0;
        for (int j = 0; j < n; j++) {
            soma_notas += matriz[i][j];
        }
        if (n > 0) {
            medias[i] = soma_notas / n;
        } else {
            medias[i] = 0.0;
        }
    }
    return medias;
}
int main() {
    int num_alunos, num_notas;
    printf("Digite o numero de alunos (m): ");
    if (scanf("%d", &num_alunos) != 1 || num_alunos <= 0) {
        printf("Entrada invalida para o numero de alunos.\n");
        return 1;
    }
    printf("Digite o numero de notas por aluno (n): ");
    if (scanf("%d", &num_notas) != 1 || num_notas < 0) {
        printf("Entrada invalida para o numero de notas.\n");
        return 1;
    }
    if (num_notas == 0) {
        printf("Nao ha notas para calcular a media.\n");
        return 0;
    }
    float notas[num_alunos][num_notas];
    printf("\nInsira as notas:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("--- Notas do Aluno %d ---\n", i + 1);
        for (int j = 0; j < num_notas; j++) {
            printf("  Nota %d: ", j + 1);
            if (scanf("%f", &notas[i][j]) != 1) {
                printf("Entrada invalida. Encerrando.\n");
                return 1;
            }
        }
    }
    float *medias_alunos = medias_das_notas(num_alunos, num_notas, notas);
    if (medias_alunos != NULL) {
        printf("\n--- Resultado do Calculo de Medias ---\n");
        for (int i = 0; i < num_alunos; i++) {
            printf("Media do Aluno %d: %.2f\n", i + 1, medias_alunos[i]);
        }
        free(medias_alunos);
        printf("\nMemoria alocada para as medias foi liberada.\n");
    } else {
        printf("\nErro: Falha na alocacao de memoria (NULL retornado).\n");
    }

    return 0;
}
