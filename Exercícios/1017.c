#include <stdio.h>

int main() {
    int tempo, velocidade;
    double distancia, litros;

    // Leitura dos valores de entrada
    scanf("%d %d", &tempo, &velocidade);

    // Cálculo da distância percorrida
    distancia = tempo * velocidade;

    // Cálculo dos litros necessários
    litros = distancia / 12.0;

    // Impressão do resultado com 3 casas decimais
    printf("%.3lf\n", litros);

    return 0;
}