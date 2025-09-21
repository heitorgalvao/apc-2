#include <stdio.h>

typedef struct canais Canais;
typedef union pixel Pixel;

struct canais {
    #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        unsigned char r, g, b, a;
    #else 
        unsigned char a, b, g, r;
    #endif
};

union pixel {
    int cor;
    Canais canais;
};

void limpar_tela() {
    printf("\033[2J");
    printf("\033[H"); 
}

void desenha_pixel_em_xy(int x, int y, Pixel *pixel) {
    printf("\033[%d;%dH", y + 1, x * 2 + 1);
    printf("\033[48;2;%d;%d;%dm  \033[0;00m",
        pixel->canais.r, pixel->canais.g, pixel->canais.b);
}

void desenha_imagem_xy(int x, int y, int n, Pixel imagem[n][n]) {
    for(int l = 0; l < n; l++) {
        for(int c = 0; c < n; c++) {
            desenha_pixel_em_xy(x+c, y+l, &imagem[l][c]);
        }
    }
}

void copiar_imagem(int n, int origem[n][n], Pixel destino[n][n]) {
    for(int l = 0; l < n; l++)
        for(int c = 0; c < n; c++)
            destino[l][c].cor = origem[l][c];
}

int imagem[10][10] = {
    {0xFF0000FF, 0xE61919FF, 0xCC3333FF, 0xB34C4CFF, 0x996666FF, 0x808080FF, 0x669999FF, 0x4CB3B3FF, 0x33CCCCFF, 0x19E6E6FF},
    {0xFF1900FF, 0xE63319FF, 0xCC4C33FF, 0xB3664CFF, 0x998066FF, 0x809980FF, 0x66B399FF, 0x4CCCB3FF, 0x33E6CCFF, 0x19FFE6FF},
    {0xFF3300FF, 0xE64C19FF, 0xCC6633FF, 0xB3804CFF, 0x999966FF, 0x80B380FF, 0x66CC99FF, 0x4CE6B3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF4C00FF, 0xE66619FF, 0xCC8033FF, 0xB3994CFF, 0x99B366FF, 0x80CC80FF, 0x66E699FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF6600FF, 0xE68019FF, 0xCC9933FF, 0xB3B34CFF, 0x99CC66FF, 0x80E680FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF8000FF, 0xE69919FF, 0xCCB333FF, 0xB3CC4CFF, 0x99E666FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFF9900FF, 0xE6B319FF, 0xCCCC33FF, 0xB3E64CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFB300FF, 0xE6CC19FF, 0xCCE633FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFCC00FF, 0xE6E619FF, 0xCCFF33FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF},
    {0xFFE600FF, 0xE6FF19FF, 0xCCFF33FF, 0xB3FF4CFF, 0x99FF66FF, 0x80FF80FF, 0x66FF99FF, 0x4CFFB3FF, 0x33FFCCFF, 0x19FFE6FF}
};

void exercicio3() {
    Pixel imagem2[10][10];
    copiar_imagem(10, imagem, imagem2);
    printf("\033[%d;%dHImagem sem vermelho", 1, 20 * 2 + 1);
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            imagem2[i][j].canais.r = 0;
    desenha_imagem_xy(20, 1, 10, imagem2);
}

void exercicio4() {
    Pixel imagem3[10][10];
    copiar_imagem(10, imagem, imagem3);
    printf("\033[%d;%dHImagem escala de cinza", 1, 35 * 2 + 1);
    unsigned char cinza;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++) {
            cinza = 0.5 + (float)(
                    imagem3[i][j].canais.r +
                    imagem3[i][j].canais.g +
                    imagem3[i][j].canais.b
                    ) / 3;
            imagem3[i][j].canais.r = cinza;
            imagem3[i][j].canais.g = cinza;
            imagem3[i][j].canais.b = cinza;
        }
        
    desenha_imagem_xy(35, 1, 10, imagem3);
}

void exercicio5() { // X azul
    Pixel imagem4[10][10];
    copiar_imagem(10, imagem, imagem4);
    printf("\033[%d;%dHImagem com X azul", 1, 50 * 2 + 1);
    for(int i = 0; i < 10; i++) {
        imagem4[i][i].canais.r = 0;
        imagem4[i][i].canais.g = 0;
        imagem4[i][i].canais.b = 255;
        imagem4[i][9-i].canais.r = 0;
        imagem4[i][9-i].canais.g = 0;
        imagem4[i][9-i].canais.b = 255;
    }
    desenha_imagem_xy(50, 1, 10, imagem4);
}
void exercicio6() {
    Pixel imagem5[10][10];
    copiar_imagem(10, imagem, imagem5);
    printf("\033[%d;%dHImagem com bordas", 1, 65 * 2 + 1);
    for(int i = 0; i < 10; i++) {
        imagem5[0][i].canais.r = 255;
        imagem5[0][i].canais.g = 0;
        imagem5[0][i].canais.b = 255;
        imagem5[9][i].canais.r = 255;
        imagem5[9][i].canais.g = 0;
        imagem5[9][i].canais.b = 255;
    
        imagem5[i][0].canais.r = 255;
        imagem5[i][0].canais.g = 0;
        imagem5[i][0].canais.b = 255;
    
        imagem5[i][9].canais.r = 255;
        imagem5[i][9].canais.g = 0;
        imagem5[i][9].canais.b = 255;
    }
    desenha_imagem_xy(65, 1, 10, imagem5);
}
void exercicio7() {
    Pixel imagem6[10][10];
    copiar_imagem(10, imagem, imagem6);
    printf("\033[%d;%dHImagem meia arvore", 15, 5 * 2 + 1);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j <= i; j++) {
            imagem6[i][j].canais.r = 0;
            imagem6[i][j].canais.g = 255;
            imagem6[i][j].canais.b = 0;
        }
    }
    desenha_imagem_xy(5, 15, 10, imagem6);
}
void exercicio8() {
    Pixel imagem7[10][10];
    copiar_imagem(10, imagem, imagem7);
    printf("\033[%d;%dHImagem c meia arvore inv", 15, 20 * 2 + 1);
    for(int i = 0; i < 10; i++) {
        for(int j = i; j < 10; j++) {
            imagem7[i][j].canais.r = 0;
            imagem7[i][j].canais.g = 255;
            imagem7[i][j].canais.b = 0;
        }
    }
    desenha_imagem_xy(20, 15, 10, imagem7);
}
void exercicio9() {
    Pixel imagem8[10][10];
    copiar_imagem(10, imagem, imagem8);
    printf("\033[%d;%dHInterseção árvores", 15, 35 * 2 + 1);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (j <= i && j >= i) { 
                imagem8[i][j].canais.r = 255;
                imagem8[i][j].canais.g = 165;
                imagem8[i][j].canais.b = 0;
            } else if (j <= i && j >= 9 - i) {
                 imagem8[i][j].canais.r = 255;
                 imagem8[i][j].canais.g = 165;
                 imagem8[i][j].canais.b = 0;
            }
        }
    }
    desenha_imagem_xy(35, 15, 10, imagem8);
}
void exercicio10() {
    Pixel imagem9[10][10];
    copiar_imagem(10, imagem, imagem9);
    printf("\033[%d;%dHUnião árvores", 15, 50 * 2 + 1);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if (j <= i) {
                imagem9[i][j].canais.r = 0;
                imagem9[i][j].canais.g = 255;
                imagem9[i][j].canais.b = 0;
            }
            if (j >= 9 - i) {
                imagem9[i][j].canais.r = 0;
                imagem9[i][j].canais.g = 255;
                imagem9[i][j].canais.b = 0;
            }
        }
    }
    desenha_imagem_xy(50, 15, 10, imagem9);
}

int main()
{
    limpar_tela();
    printf("\033[%d;%dHImagem Original", 1, 5 * 2 + 1);
    desenha_imagem_xy(5, 1, 10, (Pixel (*)[10])imagem);
    
    exercicio3();
    exercicio4();
    exercicio5();
    exercicio6();
    exercicio7();
    exercicio8();
    exercicio9();
    exercicio10();

    return 0;
}