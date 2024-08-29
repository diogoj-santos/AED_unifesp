#include <stdio.h>

// Função para calcular o número de Fibonacci e contar as chamadas recursivas
int fibonacci(int n, int *calls) {
    // Incrementa o contador de chamadas
    (*calls)++;

    // Caso base: fib(0) = 0, fib(1) = 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    // Caso recursivo: fib(n) = fib(n-1) + fib(n-2)
    return fibonacci(n - 1, calls) + fibonacci(n - 2, calls);
}

int main() {
    int num_testes; // Número de casos de teste
    scanf("%d", &num_testes);

    for (int i = 0; i < num_testes; i++) {
        int x; // O valor para o qual queremos calcular o Fibonacci
        scanf("%d", &x);

        int chamadas = -1; // Contador de chamadas recursivas (começa com -1 para ajustar a primeira chamada)
        int resultado = fibonacci(x, &chamadas);

        // Exibe o resultado no formato solicitado
        printf("fib(%d) = %d calls = %d\n", x, chamadas, resultado);
    }

    return 0;
}
