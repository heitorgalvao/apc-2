#include <stdio.h>

int main() {
    char string[100]; // talvez eu tenha me passado um pouco.
    char *p = string;
    char *ultimavogal = NULL;
    printf("Digite uma palavra: ");
    scanf("%s", string);

    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            ultimavogal = p;
        }
        p++;
    }

    if (ultimavogal != NULL) {
        printf("A string e: \"%s\"\n", string);
        printf("O endereco da ultima vogal ('%c') e: %p\n", *ultimavogal, (void *)ultimavogal);
    } else {
        printf("A string e: \"%s\"\n", string);
        printf("Nenhuma vogal encontrada.\n");
    }

    return 0;
}
