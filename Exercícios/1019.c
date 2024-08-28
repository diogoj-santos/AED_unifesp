#include <stdio.h>
 
 
int main() {
 
    int t, A, B, C;
    scanf("%d", &t);
    A = t/3600;
    B = (t%3600)/60;
    C = (t%3600)%60;
    printf("%d:%d:%d\n", A, B, C);
    
    
    
 
    return 0;
}