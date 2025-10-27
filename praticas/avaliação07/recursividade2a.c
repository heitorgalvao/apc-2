#include <stdio.h> // fatorial
int f(int n){
if(n == 1){ 
    return 1;
}else{
return n * f(n - 1);
} 
}

int main (){
    int f(int n);

    int numero, resultado;

    printf("digite um numero inteiro: ");
    scanf("%i", &numero);

    resultado = f(numero);

    printf(" o fatorial eh %i", resultado);

return 0;
}