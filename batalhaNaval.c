#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato: Implementação da lógica básica de posicionamento de navios em um tabuleiro de Batalha Naval utilizando vetores bidimensionais.
// Nível Aventureiro: Expansão do tabuleiro (matriz 10x10) e adição de mais navios, incluindo posicionamentos na diagonal.
// Nível Mestre: Implementação ed habilidades especiais, utilizando matrizes com padrões específicos (cone, cruz e octaedro).

#define TAM 5

void imprimirMatriz(int matriz[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int i, j;

    int cone[TAM][TAM]     = {0};
    int cruz[TAM][TAM]     = {0};
    int octaedro[TAM][TAM] = {0};

    /* === HABILIDADE: CONE === */
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (j >= (TAM/2 - i) && j <= (TAM/2 + i)) {
                cone[i][j] = 1;
            }
        }
    }

    /* === HABILIDADE: CRUZ === */
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (i == TAM/2 || j == TAM/2) {
                cruz[i][j] = 1;
            }
        }
    }

    /* === HABILIDADE: OCTAEDRO (LOSANGO) === */
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if ((abs(i - TAM/2) + abs(j - TAM/2)) <= TAM/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    /* === EXIBIÇÃO DAS MATRIZES === */

    printf("\nHABILIDADE EM CONE:\n\n");
    imprimirMatriz(cone);

    printf("\nHABILIDADE EM CRUZ:\n\n");
    imprimirMatriz(cruz);

    printf("\nHABILIDADE EM OCTAEDRO:\n\n");
    imprimirMatriz(octaedro);

    return 0;
    
}
