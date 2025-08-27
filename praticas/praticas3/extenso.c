#include <stdio.h>

void data_extenso(int dia, int mes, int ano) {
    char *meses[] = {
        "janeiro", "fevereiro", "marco", "abril", "maio", "junho",
        "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };
    printf("%d de %s de %d\n", dia, meses[mes - 1], ano);
}

int main() {
    int dia = 1, mes = 1, ano = 2000;
    printf("Data: 01/01/2000,em extenso: ");
    data_extenso(dia, mes, ano);
    return 0;
}