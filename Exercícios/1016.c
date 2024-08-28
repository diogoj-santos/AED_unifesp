#include <stdio.h>

int main() {
    int distancia, tempo;
    
    // Leitura da distância
    scanf("%d", &distancia);
    
    // Cálculo do tempo em minutos
    tempo = distancia * 2;
    
    // Impressão do resultado com a mensagem "minutos"
    printf("%d minutos\n", tempo);
    
    return 0;
}