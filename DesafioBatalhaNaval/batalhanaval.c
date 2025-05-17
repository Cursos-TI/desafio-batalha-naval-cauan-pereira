#include <stdio.h>

#define TAMANHO 10
#define TAM_HABILIDADE 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para sobrepor a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemX + i - offset;
            int y = origemY + j - offset;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Definindo navios no tabuleiro
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;
    tabuleiro[7][5] = 3;

    tabuleiro[8][1] = 3;
    tabuleiro[9][2] = 3;
    tabuleiro[9][3] = 3;

    tabuleiro[3][7] = 3;
    tabuleiro[4][6] = 3;
    tabuleiro[5][5] = 3;

    imprimirTabuleiro(tabuleiro);

    // Matriz de Habilidade: Cone
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Matriz de Habilidade: Cruz
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // Matriz de Habilidade: Octaedro
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);

    // Exibindo o tabuleiro com habilidades aplicadas
    imprimirTabuleiro(tabuleiro);

    return 0;
}
