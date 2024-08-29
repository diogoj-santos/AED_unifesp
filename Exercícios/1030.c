#include <stdio.h>

// Função para encontrar a posição sobrevivente no problema de Josephus
int josephus(int n, int k) {
    int pos = 0;  // A posição inicial para uma pessoa é 0 (0-indexada)
    for (int i = 2; i <= n; i++) {
        pos = (pos + k) % i;  // Atualiza a posição conforme o número de pessoas
    }
    return pos + 1;  // Ajusta para 1-indexado
}

int main() {
    int NC;  // Número de casos de teste
    scanf("%d", &NC);

    // Loop para cada caso de teste
    for (int i = 1; i <= NC; i++) {
        int n, k;  // Número de pessoas e salto
        scanf("%d %d", &n, &k);

        // Encontra a posição sobrevivente e imprime o resultado
        int sobrevivente = josephus(n, k);
        printf("Case %d: %d\n", i, sobrevivente);
    }

    return 0;
}
