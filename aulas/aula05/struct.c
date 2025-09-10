#include <stdio.h>
#include <string.h>
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define reset "\e[0m"
#define MAG "\e[0;35m"

struct pessoa{
    char nome[100];
    int idade;
};

int main(){
    struct pessoa pessoas[3];
    int i;
    printf("entre com os dados das 3 pessoas: ");
    for (i=0; i < 3; i++){
        printf(YEL);
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;
        printf("Idade: ");
        printf(reset);
        scanf("%d", &pessoas[i].idade);
        while (getchar() != '\n');

        printf("\n");
    }
    printf(MAG);
    printf("Dados das pessoas cadastradas\n");
    printf(reset);
    for (i = 0; i < 3; i++) {
        printf(GRN);
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("---\n");
        printf(reset);
    }
    
        
    return 0;
}