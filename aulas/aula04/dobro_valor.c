#include <stdio.h> // fazendo por valor.
int dobro(int dado);
void dobroref(int *dado);// por referência.

 int main(){
    int valor , resultado;
    printf("insira um valor para calcular o dobro: ");
    scanf("%i", &valor);

    resultado = dobro(valor);// a variável resultado recebe as informações do retun dado.
    printf("dobro do valor inserido: %i\n", resultado);

    dobroref(&valor);
    printf("dobro por referência %i", valor);
    return 0;
 }
 int dobro(int dado){
    dado = dado *2;
    return dado; // precisa de uma variável que receba as informações desse return. 
 }
//função por referência.
void dobroref(int *dado){
    *dado = *dado * 2;
}
