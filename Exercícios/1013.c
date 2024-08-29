#include <stdio.h>
#include <stdlib.h>  // Para a função abs()

int main() {
    int a, b, c;
    int maior_ab, maior_abc;

    // Leitura dos três valores inteiros
    scanf("%d %d %d", &a, &b, &c);

    // Calcula o maior entre a e b
    maior_ab = (a + b + abs(a - b)) / 2;

    // Calcula o maior entre maior_ab e c
    maior_abc = (maior_ab + c + abs(maior_ab - c)) / 2;

    // Impressão do maior valor seguido da mensagem
    printf("%d eh o maior\n", maior_abc);

    return 0;
}