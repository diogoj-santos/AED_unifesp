#include <stdio.h>
 
int main(void) {
 
    int N, A;
  scanf("%d", &N);
  A = 1;
  while (N-->0) {
    printf("%d %d %d PUM\n", A , A+1, A+2);
     A=A+4;
}
 
    return 0;
}