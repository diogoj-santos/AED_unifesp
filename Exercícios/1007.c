#include <stdio.h>

int main() {
    int x, y, z, w, resultado;
    
    scanf("%d %d %d %d", &x, &y, &z, &w);
    
    resultado = (x * y - z * w);
    
    printf("DIFERENCA = %d\n", resultado);
    
    return 0;
}
