#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define TAMANHO_MAXIMO_NOME 21

int compararNomes(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int quantidadeAlunos, posicaoSorteada;
    char listaNomes[MAX_ALUNOS][TAMANHO_MAXIMO_NOME];
    
    scanf("%d %d", &quantidadeAlunos, &posicaoSorteada);
    
    for (int i = 0; i < quantidadeAlunos; i++) {
        scanf("%s", listaNomes[i]);
    }
    
    qsort(listaNomes, quantidadeAlunos, sizeof(listaNomes[0]), compararNomes);
    
    printf("%s\n", listaNomes[posicaoSorteada - 1]);
    
    return 0;
}
