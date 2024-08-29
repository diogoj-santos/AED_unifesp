#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da célula da lista
typedef struct nodo {
    char valor[21];
    struct nodo* proximo;
} nodo;

// Função que adiciona um novo item à lista
void adicionar(nodo** cabeca, char* texto) {
    nodo* novo_nodo = (nodo*)malloc(sizeof(nodo));
    strcpy(novo_nodo->valor, texto);
    novo_nodo->proximo = *cabeca;
    *cabeca = novo_nodo;
}

// Função que verifica se um item já está na lista
int verificar(nodo* cabeca, char* chave) {
    nodo* cursor = cabeca;
    while (cursor != NULL) {
        if (strcmp(cursor->valor, chave) == 0) {
            return 1;
        }
        cursor = cursor->proximo;
    }
    return 0;
}

// Função que organiza os itens da lista em ordem alfabética
void organizar(nodo** cabeca) {
    if (*cabeca == NULL) return;

    nodo *atual, *comparacao;
    char temporario[21];
    for (atual = *cabeca; atual->proximo != NULL; atual = atual->proximo) {
        for (comparacao = atual->proximo; comparacao != NULL; comparacao = comparacao->proximo) {
            if (strcmp(atual->valor, comparacao->valor) > 0) {
                strcpy(temporario, atual->valor);
                strcpy(atual->valor, comparacao->valor);
                strcpy(comparacao->valor, temporario);
            }
        }
    }
}

// Função que imprime os itens da lista
void exibir(nodo* cabeca) {
    nodo* ponteiro = cabeca;
    while (ponteiro != NULL) {
        printf("%s", ponteiro->valor);
        if (ponteiro->proximo != NULL) {
            printf(" ");
        }
        ponteiro = ponteiro->proximo;
    }
    printf("\n");
}

int main() {
    int quantidade;
    scanf("%d", &quantidade);
    getchar(); 

    for (int i = 0; i < quantidade; i++) {
        nodo* cabeca_lista = NULL;
        char buffer[21000];
        fgets(buffer, 21000, stdin); 
        buffer[strcspn(buffer, "\n")] = '\0'; 

        char* palavra = strtok(buffer, " ");
        while (palavra != NULL) {
            if (!verificar(cabeca_lista, palavra)) {
                adicionar(&cabeca_lista, palavra);
            }
            palavra = strtok(NULL, " ");
        }

        organizar(&cabeca_lista);
        exibir(cabeca_lista);

        // Liberação da memória alocada
        nodo* cursor = cabeca_lista;
        while (cursor != NULL) {
            nodo* temporario = cursor;
            cursor = cursor->proximo;
            free(temporario);
        }
    }

    return 0;
}
