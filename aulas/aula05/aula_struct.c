#include <stdio.h>
#include <string.h>

struct alunos{
char nome[30];
int matricula;
int idade;
};
int main(){
    struct alunos aluno;

    printf("digite o nome do aluno: ");
    scanf("%s", &aluno.nome);

    printf("digite a idade do aluno: ");
    scanf("%d", &aluno.idade);

    printf("digite a matricula: ");
    scanf("%i", &aluno.matricula);

    printf("o nome do aluno: %s", aluno.nome);
    printf("\na idade do aluno: %d", aluno.idade);
    printf("\na matricula do aluno: %i", aluno.matricula);
return 0;
} // o básico de struct.