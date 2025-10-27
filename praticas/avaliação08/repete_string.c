#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_LENGTH 100
char *repete_string(char str[], int n) {
    if (n <= 0) {
        return NULL;
    }
    size_t len_str = strlen(str);
    size_t novo_tamanho = (size_t)n * len_str + 1;
    char *nova_string = (char *) malloc(novo_tamanho * sizeof(char));
    if (nova_string == NULL) {
        return NULL;
    }
    nova_string[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(nova_string, str);
    }
    return nova_string;
}
int main() {
    char input_str[MAX_INPUT_LENGTH];
    int n;
    printf("Digite a string a ser repetida (max %d caracteres): ", MAX_INPUT_LENGTH - 1);
    if (scanf("%99[^\n]", input_str) != 1) { 
        printf("Erro na leitura da string.\n");
        return 1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    printf("Digite o numero de repeticoes (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida para o numero de repeticoes.\n");
        return 1;
    }
    char *resultado = repete_string(input_str, n);
    printf("\n--- Resultado da Repeticao ---\n");
    if (resultado != NULL) {
        printf("String de Entrada: \"%s\"\n", input_str);
        printf("Numero de Repeticoes: %d\n", n);
        printf("String Resultante: \"%s\"\n", resultado);
        free(resultado);
        printf("\nMemoria alocada para a string resultante foi liberada.\n");
    } else {
        printf("Erro: O numero de repeticoes (n) e' invalido (<= 0) ou houve falha na alocacao de memoria.\n");
    }

    return 0;
}