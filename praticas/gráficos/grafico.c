#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RED "\e[0;31m"
#define BLU "\e[0;34m"
#define YEL "\e[0;33m"
#define MAG "\e[0;35m"
#define GRN "\e[0;32m"
#define reset "\e[0m"

char tela[60][20] = {};

void limpar_tela() {
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 60; x++) {
            tela[x][y] = ' ';
        }
    }
}
void grafico() {
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 60; x++) {
            printf("%c", tela[x][y]);
        }
        printf("\n");
    }
}
double doubleY(double x1, double y1, double x2, double y2, double x) {
    double a = y1 - y2;
    double b = x2 - x1; 
    double c = (x1 * y2) - (x2 * y1);

    if (fabs(b) < 1e-9) {
        printf(YEL);
        printf("\n\nErro: A reta e vertical (x = %.1lf) e nao e uma funcao de x.\n", -c / a);
        printf(reset);
        exit(1); 
    }
    double m = -a / b;
    double n = -c / b;
    return m * x + n;
}
void funcao_reta(double x1, double y1, double x2, double y2) {
    double a = y1 - y2;
    double b = x2 - x1;
    double c = (x1 * y2) - (x2 * y1);

    printf(MAG);
    printf("A equacao geral da reta e:\n");
    printf(reset);
    printf(GRN);
    printf("%.1lfX + %.1lfY + %.1lf = 0\n", a, b, c);
    printf(reset);

    if (fabs(b) > 1e-9) {
        double m = -a / b;
        double n = -c / b;
        printf(MAG);
        printf("\nA reta e uma funcao y = f(x).\n");
        printf(reset);
        printf(YEL);
        printf("f(x) = y = %.1lfx + %.1lf\n", m, n);
        printf(reset);
    } else {
        printf(YEL);
        double x_const = -c / a;
        printf("\nA reta e vertical (x = %.1lf) e nao define uma funcao y = f(x).\n", x_const);
        printf(reset);
    }
}
void desenhar_reta(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int y_min = (y1 < y2) ? y1 : y2;
        int y_max = (y1 > y2) ? y1 : y2;
        for (int y = y_min; y <= y_max; y++) {
            if (x1 >= 0 && x1 < 60 && y >= 0 && y < 20) {
                tela[x1][y] = '@';
            }
        }
    } else if (y1 == y2) {
        int x_min = (x1 < x2) ? x1 : x2;
        int x_max = (x1 > x2) ? x1 : x2;
        for (int x = x_min; x <= x_max; x++) {
            if (x >= 0 && x < 60 && y1 >= 0 && y1 < 20) {
                tela[x][y1] = '@';
            }
        }
    } else {
        double m = (double)(y2 - y1) / (x2 - x1);
        double n = y1 - m * x1;

        int x_min = (x1 < x2) ? x1 : x2;
        int x_max = (x1 > x2) ? x1 : x2;
        
        for (double x = x_min; x <= x_max; x += 0.25) {
            double y_calc = m * x + n;
            int y = round(y_calc);

            if ((int)round(x) >= 0 && (int)round(x) < 60 && y >= 0 && y < 20) {
                tela[(int)round(x)][y] = '@';
            }
        }
    }
}
void desenhar_triangulo(int x1, int y1, int x2, int y2, int x3, int y3) {

    double area = (double)x1 * (y2 - y3) + (double)x2 * (y3 - y1) + (double)x3 * (y1 - y2);

    if (fabs(area) > 1e-9) {
        desenhar_reta(x1, y1, x2, y2);
        desenhar_reta(x2, y2, x3, y3);
        desenhar_reta(x3, y3, x1, y1);
    } else {
        printf(YEL);
        printf("\nOs pontos fornecidos sao colineares e nao formam um triangulo.\n");
        printf(reset);
    }
}

int main() {
    double x1_double, y1_double, x2_double, y2_double, x_arb;
    int x1_draw, y1_draw, x2_draw, y2_draw;
    int x1_tri, y1_tri, x2_tri, y2_tri, x3_tri, y3_tri;

    printf(MAG);
    printf("--- Calculo da Reta ---\n");
    printf("Insira as coordenadas do Ponto A:\n");
    printf(reset);
    printf(" x de A: ");
    scanf("%lf", &x1_double);
    printf(" y de A: ");
    scanf("%lf", &y1_double);

    printf("\nInsira as coordenadas do Ponto B:\n");
    printf(" x de B: ");
    scanf("%lf", &x2_double);
    printf(" y de B: ");
    scanf("%lf", &y2_double);

    funcao_reta(x1_double, y1_double, x2_double, y2_double);

    printf(RED);
    printf("\nInsira um valor arbitrario para x: ");
    printf(reset);
    scanf("%lf", &x_arb);
    
    if (fabs(x2_double - x1_double) > 1e-9) {
        double y_resultado = doubleY(x1_double, y1_double, x2_double, y2_double, x_arb);
        printf(GRN);
        printf("\nPara x = %.1lf, o valor de y e: %.1lf\n", x_arb, y_resultado);
        printf(reset);
    }

    printf(BLU);
    printf("\n--- Desenho da Reta ---\n");
    printf("Insira as coordenadas inteiras do Ponto A (para o desenho):\n");
    printf(reset);
    printf(" x de A: ");
    scanf("%d", &x1_draw);
    printf(" y de A: ");
    scanf("%d", &y1_draw);

    printf("\nInsira as coordenadas inteiras do Ponto B (para o desenho):\n");
    printf(" x de B: ");
    scanf("%d", &x2_draw);
    printf(" y de B: ");
    scanf("%d", &y2_draw);
    
    limpar_tela();
    desenhar_reta(x1_draw, y1_draw, x2_draw, y2_draw);
    grafico();

    printf(YEL);
    printf("\n--- Desenho de Triangulo ---\n");
    printf("Insira as coordenadas inteiras do Ponto A:\n");
    printf(reset);
    printf(" x de A: ");
    scanf("%d", &x1_tri);
    printf(" y de A: ");
    scanf("%d", &y1_tri);
    printf("\nInsira as coordenadas inteiras do Ponto B:\n");
    printf(" x de B: ");
    scanf("%d", &x2_tri);
    printf(" y de B: ");
    scanf("%d", &y2_tri);
    printf("\nInsira as coordenadas inteiras do Ponto C:\n");
    printf(" x de C: ");
    scanf("%d", &x3_tri);
    printf(" y de C: ");
    scanf("%d", &y3_tri);
    
    limpar_tela();
    desenhar_triangulo(x1_tri, y1_tri, x2_tri, y2_tri, x3_tri, y3_tri);
    grafico();

    return 0;
}