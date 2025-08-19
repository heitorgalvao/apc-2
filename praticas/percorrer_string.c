#include <stdio.h>

int main() {
    char str[] = "Aula de APC II";
    char *p = str;

    while (*p != '\0') {
        printf("%c", *p);
        p++;
    }
    printf("\n");

    return 0;
}