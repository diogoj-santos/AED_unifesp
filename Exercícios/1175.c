#include <stdio.h>
  
int main() {
 
    int N[20];
    
    int a, temp;
    for (a = 0; a < 20; a++) {
        scanf("%d", &N[a]);
    }
    for (a = 0; a < 10; a++) {
        temp = N[a];
        N[a] = N[19 - a];
        N[19 - a] = temp;
    }
    for (a = 0; a < 20; a++) {
        printf("N[%d] = %d\n", a, N[a]);
    }
 
    return 0;
}