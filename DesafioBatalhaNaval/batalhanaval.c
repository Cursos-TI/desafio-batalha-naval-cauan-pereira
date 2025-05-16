#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0 (representando água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Navio Horizontal
        if (coluna + TAMANHO_NAVIO <= TAMANHO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                if (tabuleiro[linha][coluna + i] != 0) {
                    return 0; // Falha ao posicionar (há sobreposição)
                }
            }
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha][coluna + i] = 3;
            }
            return 1;
        }
    } else if (orientacao == 'V') { // Navio Vertical
        if (linha + TAMANHO_NAVIO <= TAMANHO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                if (tabuleiro[linha + i][coluna] != 0) {
                    return 0; // Falha ao posicionar (há sobreposição)
                }
            }
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = 3;
            }
            return 1;
        }
    }
    return 0; // Falha ao posicionar (fora dos limites)
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais definidas no código
    int linhaH = 2, colunaH = 3; // Para o navio horizontal
    int linhaV = 5, colunaV = 7; // Para o navio vertical

    // Posicionando os navios
    if (posicionarNavio(tabuleiro, linhaH, colunaH, 'H')) {
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("Falha ao posicionar o navio horizontal.\n");
    }

    if (posicionarNavio(tabuleiro, linhaV, colunaV, 'V')) {
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("Falha ao posicionar o navio vertical.\n");
    }

    // Exibindo o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
