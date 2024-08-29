#include <stdio.h>
#include <string.h>

// Função para encontrar o índice de um caractere no percurso infixo
int encontrarIndice(char *in, char raiz, int inicio, int fim) {
    for (int i = inicio; i <= fim; i++) {
        if (in[i] == raiz)
            return i;
    }
    return -1;
}

// Função recursiva para imprimir o percurso posfixo da árvore
void reconstruirArvore(char *pre, char *in, int inicio, int fim, int *indicePre) {
    if (inicio > fim) 
        return;

    // Obtém a raiz da subárvore atual
    char raiz = pre[(*indicePre)++];
    
    // Encontra a posição da raiz no percurso infixo
    int pos = encontrarIndice(in, raiz, inicio, fim);

    // Reconstrói a subárvore esquerda
    reconstruirArvore(pre, in, inicio, pos - 1, indicePre);

    // Reconstrói a subárvore direita
    reconstruirArvore(pre, in, pos + 1, fim, indicePre);

    // Imprime a raiz após subárvores para o percurso posfixo
    printf("%c", raiz);
}

int main() {
    char pre[27], in[27]; // Strings para os percursos prefixo e infixo
    int indicePre;        // Índice para o percurso prefixo

    // Lê as strings até o final do arquivo
    while (scanf("%s %s", pre, in) != EOF) {
        int n = strlen(pre); // Tamanho dos percursos
        indicePre = 0;       // Reseta o índice do percurso prefixo
        // Reconstrói a árvore e imprime o percurso posfixo
        reconstruirArvore(pre, in, 0, n - 1, &indicePre);
        printf("\n"); // Quebra de linha após cada percurso posfixo
    }

    return 0;
}
