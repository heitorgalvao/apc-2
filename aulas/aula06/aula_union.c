#include <stdio.h>
#include <stdlib.h>
// union ocupa bem menos espaço na memória da máquina.
union estrutura01{
    int numero;
    char palavra;
    float decimal;
};

struct estrutura02{
    int numero02;
    char palavra02;
    float decimal02;
};
int main(){
    printf("tamanho em bytes de union: %d\n",sizeof(union estrutura01));
    printf("tamanho em bytes de struct: %d\n",sizeof(struct estrutura02));
    return 0;
}