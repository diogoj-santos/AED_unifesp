#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para comparar caracteres, usada para ordenação
int cmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Função para gerar a próxima permutação lexicográfica
int next_permutation(char *s, int n) {
    int i = n - 2;
    // Encontra o maior índice i tal que s[i] < s[i + 1]
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    // Se não existir, estamos na última permutação
    if (i < 0)
        return 0;

    // Encontra o maior índice j tal que s[j] > s[i]
    int j = n - 1;
    while (s[j] <= s[i])
        j--;

    // Troca s[i] com s[j]
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    // Inverte a sequência de s[i + 1] até o final
    int left = i + 1, right = n - 1;
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    return 1;
}

int main() {
    int n;
    char str[11]; // String com no máximo 10 caracteres + 1 para o terminador

    // Lê o número de strings
    scanf("%d", &n);

    // Processa cada string
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int len = strlen(str);

        // Ordena a string para começar da primeira permutação lexicográfica
        qsort(str, len, sizeof(char), cmp);

        // Imprime todas as permutações em ordem lexicográfica
        do {
            printf("%s\n", str);
        } while (next_permutation(str, len));

        printf("\n"); // Linha em branco após cada lista de permutações
    }

    return 0;
}
