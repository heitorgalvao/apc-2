#include <stdio.h>

int main(void) {
    int i = 5;
    int *p;

    p = &i;

    printf("&p: %p\n", &p);
    printf("(&i - endereco de i): %p\n", p);
    printf("(*p (i - valor de i): %d\n", *p);
    *p = 7; // Agora, o valor de i é 7
    //depois de atribuir diretamente
    printf("(*p (i - valor de i): %d\n", *p);

    return 0;
}
 
