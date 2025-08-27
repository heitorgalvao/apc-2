#include <stdio.h> // equação da reta é  Ax + By + c = 0
#define GRN "\e[0;32m"
#define reset "\e[0m"
void funcao_reta(double x1, double y1 , double x2, double y2){
   double a = y1 - y2;
    double b = x1 -x2;
    double c = (x1*y2) - (x2*y1);

    printf("a equação da reta:\n");
    printf(GRN);
    printf("%.1lfX + %.1lfY + %.1lf = 0\n", a, b, c);
    printf(reset);
};
int main(){
    double x1 , y1 , x2, y2;
    
    printf("insira as coordenadas do ponto A:\n");
    printf(" insira o x de A: ");
    scanf("%lf" , &x1);
    printf("\nagora o y de A: ");
    scanf("%lf", &y1);
    printf("agora as coordenadas do ponto B:\n");
    printf(" insira o x de B: ");
    scanf("%lf" , &x2);
    printf("\nagora o y de B: ");
    scanf("%lf", &y2);

    funcao_reta(x1, y1, x2, y2);
    return 0;
}