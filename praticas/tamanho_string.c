#include <stdio.h>
int main(){

char string[] = "hello world";
char *p = string;
int tamanho = 0;
while (*p != '\0'){
    tamanho++;
    *p++;
}   
    printf("A string e: \"%s\"\n", string);
    printf("O tamanho da string e: %d\n", tamanho);
return 0;

}