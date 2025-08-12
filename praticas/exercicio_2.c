#include <stdio.h>
int main(void) {
    int i = 5;
    int *p;
    p = &i;
    printf("&p: %p\n", &p);
    printf("(&i - endereco de i): %p\n", p);
    printf("(*p (i - valor de i): %d\n", *p);
    
    printf("Digite um novo valor para i: ");
    scanf("%d", p);

    printf("--- Apos a entrada do usuario ---\n");
    printf("(*p (i - valor de i): %d\n", *p);

    return 0;
}