#include <stdio.h>

int main(){
    char string1[20] = "hello"; // char string1[] estava dando overflow.
    char string2[] = " world";

    char *p1 = string1; // hello
    char *p2 = string2; // world
    

    while(*p1 != '\0'){
    p1++;
    }
    while(*p2 != '\0'){
        *p1 = *p2; // creio eu que isso leve o codigo a associar essas duas variáveis.
                   //Posso estar terrivelmente errado.
        p1++;
        p2++;
    }
    *p1 = '\0'; // importante /0 tá errado. \0 tá certo.
    printf("String somada: %s\n", string1);
    return 0;

}