#include <stdio.h>

int main() {
    double n1, n2, med;
    
    scanf("%lf %lf", &n1, &n2);
    
    med = (n1 * 3.5 + n2 * 7.5) / 11;
    
    printf("MEDIA = %.5lf\n", med);
    
    return 0;
}
