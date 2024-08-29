#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int main() {
    int n;
    
    while (scanf("%d", &n) && n != 0) {
        int perm[MAX];
        while (1) {
            // Leitura da permutação desejada
            scanf("%d", &perm[0]);
            if (perm[0] == 0) {
                printf("\n");
                break;
            }
            for (int i = 1; i < n; i++) {
                scanf("%d", &perm[i]);
            }
            
            int stack[MAX];
            int top = -1; // Inicialmente, a pilha está vazia
            int current = 1; // Próximo vagão a entrar

            bool possible = true;

            for (int i = 0; i < n; i++) {
                int desired = perm[i];
                
                while (current <= desired) {
                    stack[++top] = current++; // Empilha até encontrar o vagão desejado
                }

                if (stack[top] == desired) {
                    top--; // Desempilha o vagão desejado
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    return 0;
}
