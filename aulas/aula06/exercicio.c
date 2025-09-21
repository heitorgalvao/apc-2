#include <stdio.h>

#define N 10

#ifndef _BYTE_ORDER
#define _BYTE_ORDER _ORDER_BIG_ENDIAN__
#endif

#ifndef _ORDER_BIG_ENDIAN__
#define _ORDER_BIG_ENDIAN__ 4321
#endif

#ifndef _ORDER_LITTLE_ENDIAN__
#define _ORDER_LITTLE_ENDIAN__ 1234
#endif

typedef struct canais Canais;
struct canais {
#if _BYTE_ORDER_ == _ORDER_BIG_ENDIAN__
    unsigned char r, g, b, a;
#else
    unsigned char a, b, g, r;
#endif
};
typedef union pixel Pixel;
union pixel {
    int cor;
    Canais canais;
};
int imagem[N][N] = {
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
void limpar_tela() {
    printf("\033[2J");
    printf("\033[H");
}
void desenha_pixel_em_xy(int x, int y, Pixel *pixel) {
    printf("\033[%d;%dH", y + 1, x * 2 + 1);
    printf("\033[48;2;%d;%d;%dm \033[0;00m",
           pixel->canais.r, pixel->canais.g, pixel->canais.b);
}
void desenha_imagem(int n, Pixel imagem[n][n]) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            desenha_pixel_em_xy(x, y, &imagem[x][y]);
        }
    }
}
void copiar_imagem(int n, int origem[n][n], Pixel destino[n][n]) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            destino[x][y].cor = origem[x][y];
        }
    }
}
void remover_canal_vermelho(int n, Pixel imagem[n][n]) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            imagem[x][y].canais.r = 0;
        }
    }
}
void converter_para_cinza(int n, Pixel imagem[n][n]) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int media = (imagem[x][y].canais.r + imagem[x][y].canais.g + imagem[x][y].canais.b) / 3;
            imagem[x][y].canais.r = media;
            imagem[x][y].canais.g = media;
            imagem[x][y].canais.b = media;
        }
    }
}

int main() {

    Pixel imagem2[N][N];
    Pixel imagem3[N][N];

    limpar_tela();
    printf("\033[1;1HImagem Original:");
    desenha_imagem(N, (Pixel (*)[N])imagem);
    copiar_imagem(N, imagem, imagem2);
    remover_canal_vermelho(N, imagem2);
    printf("\033[1;%dHImagem sem o vermelho:", N * 2 + 5);

    desenha_imagem(N, imagem2);
    copiar_imagem(N, imagem, imagem3);
    converter_para_cinza(N, imagem3);
    printf("\033[1;%dHImagem em escala de cinza:", N * 4 + 10);
    desenha_imagem(N, imagem3);
    printf("\033[%d;%dH", N + 2, 1);

    return 0;
}