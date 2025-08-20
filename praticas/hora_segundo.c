#include <stdio.h> // conversor de hora e minutos 
int main(){
    int hora;
    int min;
    int sec;
    printf("insira hora: \n");
    scanf("%i", &hora);

    printf("insira minutos: \n");
    scanf("%i", &min);

    printf("insira segundos: ");
    scanf("%i", &sec);

    int converth = hora*3600;
    int convertm = min*60;
    long int totals = (long int)converth + (long int)convertm + (long int)sec;
    
    printf("o total de segundos é:%li" , totals);


    return 0;
}