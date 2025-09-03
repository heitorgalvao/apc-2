#include <math.h>
#include <stdio.h> 
// cálcula o valor absoluto de um número.
void modulo(double *x){
    *x = fabs(*x); // a função fabs é utilizada para calcular o valor absoluto.
};

int main(){
    double num;
    printf("digite um numero para o valor absoluto: ");
    scanf("%lf", &num);
    printf("o numero inserido: %lf", num);

    modulo(&num);
    printf("\no valor absoluto: %lf", num);

    return 0;
}

