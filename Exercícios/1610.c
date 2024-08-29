#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10000

// Estrutura para a lista de adjacência
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_NODES];
bool visited[MAX_NODES];
bool inStack[MAX_NODES];

// Função para adicionar uma aresta ao grafo
void addEdge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = adjList[u];
    adjList[u] = node;
}

// Função para verificar se há um ciclo no grafo usando DFS
bool hasCycle(int v) {
    if (inStack[v]) return true;
    if (visited[v]) return false;

    visited[v] = true;
    inStack[v] = true;

    Node* node = adjList[v];
    while (node) {
        if (hasCycle(node->vertex)) return true;
        node = node->next;
    }

    inStack[v] = false;
    return false;
}

int main() {
    int T, N, M, A, B;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);

        // Inicializa as estruturas
        for (int i = 0; i < N; i++) {
            adjList[i] = NULL;
            visited[i] = false;
            inStack[i] = false;
        }

        // Lê as arestas
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);
            A--; // Ajusta para zero-base
            B--; // Ajusta para zero-base
            addEdge(A, B);
        }

        // Verifica se há ciclos em qualquer componente do grafo
        bool cycleFound = false;
        for (int i = 0; i < N; i++) {
            if (!visited[i] && hasCycle(i)) {
                cycleFound = true;
                break;
            }
        }

        if (cycleFound) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
