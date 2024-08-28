#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Posicao;

typedef struct {
    Posicao *dados;
    int front, rear, capacidade;
} Fila;

void inicializarFila(Fila *fila, int capacidade) {
    fila->capacidade = capacidade;
    fila->front = fila->rear = 0;
    fila->dados = (Posicao *)malloc(capacidade * sizeof(Posicao));
    if (fila->dados == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a fila\n");
        exit(1);
    }
}

int filaVazia(Fila *fila) {
    return fila->front == fila->rear;
}

void enfileirar(Fila *fila, int x, int y) {
    if (fila->rear == fila->capacidade) {
        fila->capacidade *= 2;
        fila->dados = (Posicao *)realloc(fila->dados, fila->capacidade * sizeof(Posicao));
        if (fila->dados == NULL) {
            fprintf(stderr, "Erro ao realocar memória para a fila\n");
            exit(1);
        }
    }
    fila->dados[fila->rear].x = x;
    fila->dados[fila->rear].y = y;
    fila->rear++;
}

Posicao desenfileirar(Fila *fila) {
    return fila->dados[fila->front++];
}

void liberarFila(Fila *fila) {
    free(fila->dados);
}

#define MAX 1024

int N, M;
char **imagem;
int **visitado;

int mov_x[] = {-1, 1, 0, 0};
int mov_y[] = {0, 0, -1, 1};

int dentro_dos_limites(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

void bfs(int start_x, int start_y) {
    Fila fila;
    inicializarFila(&fila, 1000);

    enfileirar(&fila, start_x, start_y);
    visitado[start_x][start_y] = 1;

    while (!filaVazia(&fila)) {
        Posicao p = desenfileirar(&fila);
        int x = p.x;
        int y = p.y;

        for (int i = 0; i < 4; i++) {
            int novo_x = x + mov_x[i];
            int novo_y = y + mov_y[i];

            if (dentro_dos_limites(novo_x, novo_y) && !visitado[novo_x][novo_y] && imagem[novo_x][novo_y] == '.') {
                visitado[novo_x][novo_y] = 1;
                enfileirar(&fila, novo_x, novo_y);
            }
        }
    }

    liberarFila(&fila);
}

int main() {
    scanf("%d %d", &N, &M);

    imagem = (char **)malloc(N * sizeof(char *));
    if (imagem == NULL) {
        fprintf(stderr, "Erro ao alocar memória para 'imagem'\n");
        return 1;
    }

    visitado = (int **)malloc(N * sizeof(int *));
    if (visitado == NULL) {
        fprintf(stderr, "Erro ao alocar memória para 'visitado'\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        imagem[i] = (char *)malloc((M + 1) * sizeof(char));
        if (imagem[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para 'imagem[%d]'\n", i);
            return 1;
        }

        visitado[i] = (int *)malloc(M * sizeof(int));
        if (visitado[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para 'visitado[%d]'\n", i);
            return 1;
        }

        for (int j = 0; j < M; j++) {
            visitado[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        scanf("%s", imagem[i]);
    }

    int cliques_necessarios = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (imagem[i][j] == '.' && !visitado[i][j]) {
                bfs(i, j);
                cliques_necessarios++;
            }
        }
    }

    printf("%d\n", cliques_necessarios);

    for (int i = 0; i < N; i++) {
        free(imagem[i]);
        free(visitado[i]);
    }
    free(imagem);
    free(visitado);

    return 0;
}