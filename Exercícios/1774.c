#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

typedef struct {
    int origem, destino, custo;
} Conexao;

Conexao grafo[250];
int representantes[70];

int comparar(const void *, const void *);
int encontrarRepresentante(int);
int calcularCustoMinimo(int);

int main() {
    int roteadores, cabos, i;
    scanf("%d %d", &roteadores, &cabos);

    for (i = 0; i < cabos; ++i) {
        scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].custo);
    }

    qsort(grafo, cabos, sizeof(Conexao), comparar);

    for (i = 1; i <= roteadores; ++i) {
        representantes[i] = i;
    }

    printf("%d\n", calcularCustoMinimo(cabos));

    return 0;
}

int comparar(const void *a, const void *b) {
    return ((Conexao *)a)->custo - ((Conexao *)b)->custo;
}

int encontrarRepresentante(int nodo) {
    if (nodo == representantes[nodo])
        return nodo;
    return encontrarRepresentante(representantes[nodo]);
}

int calcularCustoMinimo(int totalConexoes) {
    int i, custoTotal = 0, raizOrigem, raizDestino;

    for (i = 0; i < totalConexoes; ++i) {
        raizOrigem = encontrarRepresentante(grafo[i].origem);
        raizDestino = encontrarRepresentante(grafo[i].destino);

        if (raizOrigem != raizDestino) {
            representantes[raizOrigem] = raizDestino;
            custoTotal += grafo[i].custo;
        }
    }

    return custoTotal;
}
