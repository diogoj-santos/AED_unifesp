#include <stdio.h>

int main() {
    char nome[50];
    double sal, vendas, total;
    
    scanf("%s", nome);
    scanf("%lf %lf", &sal, &vendas);
    
    total = sal + (vendas * 0.15);
    
    printf("TOTAL = R$ %.2lf\n", total);
    
    return 0;
}
