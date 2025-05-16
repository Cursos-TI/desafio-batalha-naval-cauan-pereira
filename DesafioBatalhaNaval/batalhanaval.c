#include <stdio.h>

// Definindo as dimensões do tabuleiro
#define LINHAS 10
#define COLUNAS 10

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para validar se a posição está dentro dos limites do tabuleiro
int posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS);
}

// Função para validar se há sobreposição de navios
int sobreposicao(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 3;
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, char direcao) {
    for (int i = 0; i < 3; i++) {
        if (direcao == 'H' && posicaoValida(linha, coluna + i) && !sobreposicao(tabuleiro, linha, coluna + i)) {
            tabuleiro[linha][coluna + i] = 3;
        } else if (direcao == 'V' && posicaoValida(linha + i, coluna) && !sobreposicao(tabuleiro, linha + i, coluna)) {
            tabuleiro[linha + i][coluna] = 3;
        } else {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio na diagonal
int posicionarNavioDiagonal(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, char direcao) {
    for (int i = 0; i < 3; i++) {
        if (direcao == 'D' && posicaoValida(linha + i, coluna + i) && !sobreposicao(tabuleiro, linha + i, coluna + i)) {
            tabuleiro[linha + i][coluna + i] = 3;
        } else if (direcao == 'I' && posicaoValida(linha + i, coluna - i) && !sobreposicao(tabuleiro, linha + i, coluna - i)) {
            tabuleiro[linha + i][coluna - i] = 3;
        } else {
            return 0;
        }
    }
    return 1;
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS];

    inicializarTabuleiro(tabuleiro);

    if (!posicionarNavio(tabuleiro, 2, 3, 'H')) {
        printf("Falha ao posicionar navio horizontal.\n");
    }
    if (!posicionarNavio(tabuleiro, 5, 7, 'V')) {
        printf("Falha ao posicionar navio vertical.\n");
    }

    if (!posicionarNavioDiagonal(tabuleiro, 0, 0, 'D')) {
        printf("Falha ao posicionar navio diagonal (principal).\n");
    }
    if (!posicionarNavioDiagonal(tabuleiro, 6, 9, 'I')) {
        printf("Falha ao posicionar navio diagonal (secundária).\n");
    }

    imprimirTabuleiro(tabuleiro);

    return 0;
}
