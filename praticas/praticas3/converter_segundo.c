#include <stdio.h>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
long int converts(int horas, int minutos, int segundos);

int main() {
    int hora;
    int min;
    int sec;
    long int totals;

    printf("insira hora: \n");
    scanf("%i", &hora);
    printf("insira minutos: \n");
    scanf("%i", &min);
    printf("insira segundos: \n");
    scanf("%i", &sec);

    totals = converts(hora, min, sec);

    printf("O total de segundos e: %li\n", totals);

    return 0;
}
long int converts(int horas, int minutos, int segundos) {
    long int converth = (long int)horas * 3600;
    long int convertm = (long int)minutos * 60;
   
    return converth + convertm + segundos;
}