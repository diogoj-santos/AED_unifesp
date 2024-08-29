#include <iostream>
 
using namespace std;
 
int main() {
 
 float A, B, C;
 scanf("%f", &A);
 scanf("%f", &B);
 scanf("%f", &C);
 printf("TRIANGULO: %.3f\nCIRCULO: %.3f\nTRAPEZIO: %.3f\nQUADRADO: %.3f\nRETANGULO: %.3f\n", ((A*C)/2), (C*C*3.14159), (((A+B)*C)/2), (B*B), (A*B));
 
    return 0;
}