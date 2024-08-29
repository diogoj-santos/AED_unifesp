#include <stdio.h>

int main() {
    // Variáveis: contagem de pares, índice de loop, e para armazenar os números e resultado da divisão
    int total_pares, contador;
    double num1, num2, resultado_divisao;

    // Lê a quantidade de pares de valores que serão processados
    scanf("%d", &total_pares);

    // Loop para processar cada par de números
    for (contador = 0; contador < total_pares; contador++) {
        // Lê os dois números
        scanf("%lf %lf", &num1, &num2);

        // Verifica se o divisor é zero
        if (num2 == 0) {
            // Mensagem de erro quando a divisão é impossível
            printf("divisao impossivel\n");
        } else {
            // Calcula a divisão e exibe o resultado com uma casa decimal
            resultado_divisao = num1 / num2;
            printf("%.1lf\n", resultado_divisao);
        }
    }

    return 0;  // Encerra o programa
}
