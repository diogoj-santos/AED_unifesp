#include <stdio.h>

int main() {
    int a, b, d, e;
    double c, f, total;
    
    scanf("%d %d %lf", &a, &b, &c);
    scanf("%d %d %lf", &d, &e, &f);
    
    total = (b * c) + (e * f);
    
    printf("VALOR A PAGAR: R$ %.2lf\n", total);
    
    return 0;
}