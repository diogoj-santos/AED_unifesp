#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor;
    struct Elemento *prox;
} Elemento;

typedef struct Lista {
    Elemento *primeiro;
    Elemento *ultimo;
} Lista;

void adicionarNaTabela(Lista *, const int, unsigned);
void mostrarTabela(Lista *, unsigned);

int main() {
    unsigned casos, tamanhoTabela;
    int quantidadeValores, num;

    scanf("%u", &casos);

    while (casos--) {
        scanf("%u %d", &tamanhoTabela, &quantidadeValores);

        Lista tabelaHash[tamanhoTabela];
        for (unsigned i = 0; i < tamanhoTabela; ++i) {
            tabelaHash[i].primeiro = NULL;
            tabelaHash[i].ultimo = NULL;
        }

        for (int j = 0; j < quantidadeValores; ++j) {
            scanf("%d", &num);
            adicionarNaTabela(tabelaHash, num, tamanhoTabela);
        }

        mostrarTabela(tabelaHash, tamanhoTabela);

        if (casos) {
            printf("\n");
        }
    }

    return 0;
}

void adicionarNaTabela(Lista *tabela, const int chave, unsigned tamTabela) {
    Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
    if (!novoElemento) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    int indice = chave % tamTabela;
    novoElemento->valor = chave;
    novoElemento->prox = NULL;

    if (tabela[indice].ultimo) {
        tabela[indice].ultimo->prox = novoElemento;
    } else {
        tabela[indice].primeiro = novoElemento;
    }

    tabela[indice].ultimo = novoElemento;
}

void mostrarTabela(Lista *tabela, unsigned tamTabela) {
    for (unsigned k = 0; k < tamTabela; ++k) {
        printf("%u -> ", k);
        Elemento *atual = tabela[k].primeiro;
        while (atual) {
            printf("%d -> ", atual->valor);
            atual = atual->prox;
        }
        printf("\\\n");
    }
}
