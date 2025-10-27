#include <stdio.h>
#include <stdlib.h>

int *vet = NULL, length = 0;

int inserir(int dado) {
    int *temp = (int *)realloc(vet, (length + 1) * sizeof(int));
    if (temp == NULL) {
        return 0;
    }
    vet = temp;
    vet[length] = dado;
    length++;
    return 1;
}

int deletar() {
    if (length == 0) {
        return 0;
    }
    if (length == 1) {
        free(vet);
        vet = NULL;
        length--;
        return 1;
    }
    int *temp = (int *)realloc(vet, (length - 1) * sizeof(int));
    vet = temp;
    length--;
    return 1;
}

void listar() {
    for(int i = 0; i < length; i++) printf("[%d]", vet[i]);
    printf("\n");
}

void limpar_entrada_teclado() {
    scanf("%*[^\n]");
    scanf("%*c");
}

void ler(int *dado) {
    printf("Digite um valor: ");
    scanf("%d", dado);
    limpar_entrada_teclado();
}

int main() {
    int opcao, dado;
    do {
        printf("\033[H\033[J");
        printf("dados: %p, length: %d\n", (void*)vet, length);
        printf("1 - Inserir\n2 - Deletar\n3 - Listar\n0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_entrada_teclado();
        switch(opcao) {
            case 1:
                ler(&dado);
                if(inserir(dado)) printf("Valor inserido com sucesso!\n");
                else printf("Erro ao inserir valor!\n");
                break;
            case 2:
                if(deletar()) printf("Valor deletado com sucesso!\n");
                else printf("Erro ao deletar valor! O vetor está vazio.\n");
                break;
            case 3:
                listar();
                break;
            case 0:
                if (vet != NULL) {
                    free(vet);
                }
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        printf("Pressione Enter para continuar...\n");
        limpar_entrada_teclado();
    } while(opcao != 0);
    return 0;
}