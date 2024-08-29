#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma aresta
typedef struct {
    int u, v; // u e v são os vértices que a aresta conecta
    int weight; // weight é o peso da aresta
} Edge;

// Função para comparar duas arestas, utilizada na ordenação pelo peso
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

// Função para encontrar o representante (raiz) de um vértice
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]); // Compressão de caminho
}

// Função para unir (fazer a união) de dois subconjuntos
void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Função principal que implementa o algoritmo de Kruskal
int kruskal(int M, int N, Edge edges[]) {
    qsort(edges, N, sizeof(Edge), compareEdges); // Ordena as arestas pelo peso

    int parent[M], rank[M];
    for (int i = 0; i < M; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    for (int i = 0; i < N; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (find(parent, u) != find(parent, v)) {
            unionSets(parent, rank, u, v);
            totalWeight += weight;
        }
    }

    return totalWeight;
}

// Função principal do programa
int main() {
    while (1) {
        int M, N;
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0)
            break;

        Edge edges[N];
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        }

        int result = kruskal(M, N, edges);
        printf("%d\n", result);
    }

    return 0;
}