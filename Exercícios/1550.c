#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

// Função para inverter os dígitos de um número
int inverter(int num) {
    int invertido = 0;
    while (num > 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}

// Função para encontrar o número mínimo de apertos de botões
int bfs(int A, int B) {
    queue<int> q;
    int dist[10000]; // Vetor para armazenar as distâncias (número de apertos)
    memset(dist, -1, sizeof(dist)); // Inicializa todas as distâncias como -1

    q.push(A);
    dist[A] = 0; // A distância inicial é zero

    while (!q.empty()) {
        int atual = q.front();
        q.pop();

        // Se atingimos o número B, retornamos a distância atual
        if (atual == B) {
            return dist[atual];
        }

        // Operação 1: Adicionar 1
        int prox = atual + 1;
        if (prox < 10000 && dist[prox] == -1) { // Verifica se está dentro dos limites e não visitado
            dist[prox] = dist[atual] + 1;
            q.push(prox);
        }

        // Operação 2: Inverter os dígitos
        prox = inverter(atual);
        if (prox < 10000 && dist[prox] == -1) { // Verifica se está dentro dos limites e não visitado
            dist[prox] = dist[atual] + 1;
            q.push(prox);
        }
    }
    return -1; // Em teoria, isso nunca deve ser alcançado
}

int main() {
    int T, A, B;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }

    return 0;
}
