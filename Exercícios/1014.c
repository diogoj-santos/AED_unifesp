#include <stdio.h>

int main() {
    int X;         // Distância total percorrida (em Km)
    double Y;      // Total de combustível gasto (em litros)
    
    // Leitura dos valores de entrada
    scanf("%d %lf", &X, &Y);
    
    // Cálculo do consumo médio
    double consumoMedio = X / Y;
    
    // Impressão do resultado com 3 casas decimais
    printf("%.3lf km/l\n", consumoMedio);
    
    return 0;
}