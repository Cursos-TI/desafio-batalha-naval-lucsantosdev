#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato: Implementação da lógica básica de posicionamento de navios em um tabuleiro de Batalha Naval utilizando vetores bidimensionais.
// Nível Aventureiro: Expansão do tabuleiro (matriz 10x10) e adição de mais navios, incluindo posicionamentos na diagonal.

#define TAM 10

int main() {

    int tabuleiro[TAM][TAM];
    int i, j;

    /* === Inicializa o tabuleiro com água === */
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    /* === Definição manual dos navios === */

    // Navio horizontal (tamanho 4)
    int navioH_x = 1;   // coluna inicial
    int navioH_y = 2;   // linha
    int tamH = 4;

    // Navio vertical (tamanho 3)
    int navioV_x = 7;   // coluna
    int navioV_y = 1;   // linha inicial
    int tamV = 3;

    // Navio diagonal principal ↘ (tamanho 4)
    int navioD1_x = 0;
    int navioD1_y = 5;
    int tamD1 = 4;

    // Navio diagonal secundária ↗ (tamanho 3)
    int navioD2_x = 6;
    int navioD2_y = 8;
    int tamD2 = 3;

    /* === Posicionamento dos navios === */

    // Horizontal →
    for (i = 0; i < tamH; i++) {
        tabuleiro[navioH_y][navioH_x + i] = 3;
    }

    // Vertical ↓
    for (i = 0; i < tamV; i++) {
        tabuleiro[navioV_y + i][navioV_x] = 3;
    }

    // Diagonal principal ↘
    for (i = 0; i < tamD1; i++) {
        tabuleiro[navioD1_y + i][navioD1_x + i] = 3;
    }

    // Diagonal secundária ↗
    for (i = 0; i < tamD2; i++) {
        tabuleiro[navioD2_y - i][navioD2_x + i] = 3;
    }

    /* === Exibição do tabuleiro === */

    printf("\nTABULEIRO BATALHA NAVAL (10x10)\n\n");

    // Cabeçalho das colunas A-J
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Linhas do tabuleiro
    for (i = 0; i < TAM; i++) {

        if (i < 9)
            printf(" %d ", i + 1);
        else
            printf("%d ", i + 1);

        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
