#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato: Implementação da lógica básica de posicionamento de navios em um tabuleiro de Batalha Naval utilizando vetores bidimensionais.

#define TAM 10

int main() {

    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    /* === Definição dos navios manualmente ==== */

    // Navio vertical (tamanho 4)
    int navioV_x = 2;   // coluna
    int navioV_y = 3;   // linha

    // Navio horizontal (tamanho 3)
    int navioH_x = 5;   // coluna
    int navioH_y = 7;   // linha

    // Posiciona navio vertical
    for (i = 0; i < 4; i++) {
        tabuleiro[navioV_y + i][navioV_x] = 3;
    }

    // Posiciona navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[navioH_y][navioH_x + i] = 3;
    }

    /* === Exibição do tabuleiro === */

    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    // Cabeçalho das colunas (A até J)
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Linhas do tabuleiro
    for (i = 0; i < TAM; i++) {
        // Numeração das linhas
        if (i < 9)
            printf(" %d ", i + 1);
        else
            printf("%d ", i + 1);

        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    /* === Exibição das coordenadas dos navios === */

    printf("\nCOORDENADAS DOS NAVIOS\n\n");

    printf("Navio Vertical:\n");
    for (i = 0; i < 4; i++) {
        printf("Parte %d -> Linha %d | Coluna %c\n",
               i + 1,
               navioV_y + i + 1,
               'A' + navioV_x);
    }

    printf("\nNavio Horizontal:\n");
    for (i = 0; i < 3; i++) {
        printf("Parte %d -> Linha %d | Coluna %c\n",
               i + 1,
               navioH_y + 1,
               'A' + navioH_x + i);
    }

    return 0;
}
