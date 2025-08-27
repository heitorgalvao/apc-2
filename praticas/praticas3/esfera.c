#include <stdio.h>
#include <math.h>

double volume_esfera(double raio) {
    return (4.0 / 3.0) * M_PI * pow(raio,3);
}

int main() {
    double raio = 5.0;
    double volume = volume_esfera(raio);
    printf("O volume de uma esfera com raio %.2f e: %.2f\n", raio, volume);
    return 0;
}