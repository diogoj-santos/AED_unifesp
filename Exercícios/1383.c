#include <stdio.h>

/* A função recebe uma matriz 9x9 e verifica se há números de 1 a 9 repetidos nas linhas.
* Retorna 1 se não houver repetição, ou 0 se houver. */
int checarLinhas(int tabuleiro[9][9]) {
    int linha, coluna, numero;
    for (linha = 0; linha < 9; linha++) {
        int visitados[10] = {0}; // array para marcar os números já vistos
        for (coluna = 0; coluna < 9; coluna++) {
            numero = tabuleiro[linha][coluna];
            if (visitados[numero] == 1 || numero > 9 || numero < 1) {
                return 0;
            }
            visitados[numero] = 1;
        }
    }
    return 1;
}

/* A função verifica se há números de 1 a 9 repetidos nas colunas de uma matriz 9x9.
* Retorna 1 se não houver repetição, ou 0 se houver. */
int checarColunas(int tabuleiro[9][9]) {
    int linha, coluna, numero;
    for (coluna = 0; coluna < 9; coluna++) {
        int visitados[10] = {0}; // array para marcar os números já vistos
        for (linha = 0; linha < 9; linha++) {
            numero = tabuleiro[linha][coluna];
            if (visitados[numero] == 1 || numero > 9 || numero < 1) {
                return 0;
            }
            visitados[numero] = 1;
        }
    }
    return 1;
}

/* A função verifica se há números de 1 a 9 repetidos em cada bloco 3x3 de uma matriz 9x9.
* Retorna 1 se não houver repetição, ou 0 se houver. */
int checarBlocos(int tabuleiro[9][9]) {
    int linhaBloco, colunaBloco, linha, coluna, numero;
    for (linhaBloco = 0; linhaBloco < 9; linhaBloco += 3) {
        for (colunaBloco = 0; colunaBloco < 9; colunaBloco += 3) {
            int visitados[10] = {0}; // array para marcar os números já vistos
            for (linha = 0; linha < 3; linha++) {
                for (coluna = 0; coluna < 3; coluna++) {
                    numero = tabuleiro[linhaBloco + linha][colunaBloco + coluna];
                    if (visitados[numero] == 1 || numero > 9 || numero < 1) {
                        return 0;
                    }
                    visitados[numero] = 1;
                }
            }
        }
    }
    return 1;
}

/* A função lê os valores digitados pelo usuário para preencher uma matriz 9x9. */
void preencherTabuleiro(int tabuleiro[9][9]) {
    int linha, coluna;
    for (linha = 0; linha < 9; linha++) {
        for (coluna = 0; coluna < 9; coluna++) {
            scanf("%d", &tabuleiro[linha][coluna]);
        }
    }
}

int main() {
    int testes, contador;
    scanf("%d", &testes);

    for (contador = 1; contador <= testes; contador++) {
        int tabuleiro[9][9];
        preencherTabuleiro(tabuleiro);
        printf("Instancia %d\n", contador);
        if (checarLinhas(tabuleiro) && checarColunas(tabuleiro) && checarBlocos(tabuleiro)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
