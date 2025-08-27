#include <stdio.h>

int divisao_seis(int numero) {
    if (numero % 6 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num1 = 18;
    int num2 = 10;
    int num3;
    printf("%d e divisivel por 6? %d\n", num1, divisao_seis(num1));
    printf("%d e divisivel por 6? %d\n", num2, divisao_seis(num2));
    printf("isira um número para verificação: ");
    scanf("%d", &num3);
    printf("%d e dividivel por 6? %d", num3, divisao_seis(num3));
    
    return 0;
}