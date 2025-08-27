#include <stdio.h>

void caractere(char caractere, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", caractere);
    }
}

int main() {
    caractere('*', 5);
    
    printf("\n");

    caractere('#', 3);
    
    printf("\n");
    
    return 0;
}