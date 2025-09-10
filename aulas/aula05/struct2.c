#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    int idade;
};
void obter_pessoas(struct Pessoa pessoas[], int n) {
    printf("--- Entrada de dados de %d pessoas ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        while (getchar() != '\n');
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
    }
}
void exibir_pessoas(struct Pessoa pessoas[], int n) {
    printf("\n--- Dados das %d pessoas cadastradas ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("---\n");
    }
}
int main() {
    int num_pessoas = 3; 
    struct Pessoa pessoas[num_pessoas]; 

    obter_pessoas(pessoas, num_pessoas);

    exibir_pessoas(pessoas, num_pessoas);

    return 0;
}