#include <stdio.h>
#include <string.h>

typedef struct produto Produto;

struct produto {
    char nome[100];
    char categoria[50];
    double valor;
};
Produto produtos[20] = {
    {"Caneta BIC", "Material Escolar", 1.50},
    {"Caderno 100 folhas", "Material Escolar", 15.00},
    {"Mochila", "Material Escolar", 120.00},
    {"Borracha", "Material Escolar", 2.00},
    {"Tablet", "Eletrônicos", 1500.00},
    {"Smartphone", "Eletrônicos", 3500.00},
    {"Notebook", "Eletrônicos", 4500.00},
    {"Fone de ouvido", "Eletrônicos", 200.00},
    {"Camiseta", "Vestuário", 50.00},
    {"Calça Jeans", "Vestuário", 120.00},
    {"Tênis", "Vestuário", 300.00},
    {"Jaqueta", "Vestuário", 250.00},
    {"Livro de C++", "Livros", 80.00},
    {"Livro de Java", "Livros", 90.00},
    {"Livro de Python", "Livros", 70.00},
    {"Livro de Algoritmos", "Livros", 100.00},
    {"Garrafa de água", "Acessórios", 25.00},
    {"Relógio de pulso", "Acessórios", 500.00},
    {"Óculos de sol", "Acessórios", 150.00},
    {"Chapéu", "Acessórios", 80.00}
};
int strings_iguais(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) return 0;
        s1++;
        s2++;
    }
    return 1;
}
void atualizar_produto(Produto *p) {
    char nome[100];
    char categoria[50];
    double valor;

     printf("Digite o novo nome do produto: ");
     scanf("%99[^\n]" , nome);
     printf("Digite a nova categoria do produto: ");
    scanf(" %49[^\n]", categoria);
    printf("Digite o novo valor do produto: ");
     scanf("%lf", &valor);

     while (strlen(nome) == 0 || strlen(categoria) == 0 || valor < 0) {
        printf("Entrada inválida. Por favor, tente novamente.\n");
        printf("Digite o novo nome do produto: ");
        scanf(" %99[^\n]", nome);
        printf("Digite a nova categoria do produto: ");
        scanf(" %49[^\n]", categoria);
        printf("Digite o novo valor do produto: ");
        scanf("%lf", &valor);
    }
strcpy(p->nome, nome);
    strcpy(p->categoria, categoria);
    p->valor = valor;
}
void atualizar_indice(int indice) {
    if (indice >= 0 && indice < 20) {
        atualizar_produto(&produtos[indice]);
    } else {
        printf("Produto não encontrado!\n");
    }
}
void exibir_produtos(char *categoria) {
    int exibir_todos = (categoria == NULL || strlen(categoria) == 0);
    
    for (int i = 0; i < 20; i++) {
        if (exibir_todos || strings_iguais(produtos[i].categoria, categoria)) {
            printf("Nome: %s\n", produtos[i].nome);
            printf("Categoria: %s\n", produtos[i].categoria);
            printf("Valor: %.2f\n", produtos[i].valor);
            printf("------------------------\n");
        }
    }
}
Produto *buscar_produto(char *nome) {
    for (int i = 0; i < 20; i++) {
        if (strings_iguais(produtos[i].nome, nome)) {
            return &produtos[i];
        }
    }
    return NULL;
}
Produto *aplicar_desconto(char *nome, double porcentagem) {
    if (porcentagem < 0 || porcentagem > 100) {
        printf("Porcentagem inválida. O valor deve estar entre 0 e 100.\n");
        return NULL;
    }
Produto *p = buscar_produto(nome);
    if (p != NULL) {
        p->valor = p->valor - (p->valor * (porcentagem / 100.0));
    }
    return p;
}
int main() {
    printf("Exibindo todos os produtos:\n");
    exibirProdutos(NULL);

    printf("\nBuscando e aplicando desconto em um produto:\n");
    Produto *caneta = buscarProduto("Caneta BIC");
    if (caneta != NULL) {
        printf("Valor original da Caneta BIC: %.2f\n", caneta->valor);
        aplicarDesconto("Caneta BIC", 10.0);
        printf("Novo valor da Caneta BIC com 10%% de desconto: %.2f\n", caneta->valor);
    } else {
        printf("Produto não encontrado.\n");
    }

    printf("\nAtualizando um produto pelo índice (Ex: índice 1):\n");
    atualizarIndice(1);
    printf("Produto no índice 1 atualizado. Exibindo todos os produtos novamente para verificar:\n");
    exibirProdutos(NULL);

    return 0;
}
