#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct tipoNo {
    long long numero;
    struct tipoNo *proximo;
} tipoNo;

typedef struct tipoPilha {
    tipoNo *topo;
} tipoPilha;

void criaPilha(tipoPilha *pilha);
void push(tipoPilha *pilha, long long numero);
void pop(tipoPilha *pilha);
long long menorDaPilha(tipoPilha *pilha);

int main() {
    tipoPilha pilha, pilhaMinimos;
    char operacao[10];
    unsigned numOperacoes;
    long long numero, tmp;

    criaPilha(&pilha);
    criaPilha(&pilhaMinimos);

    scanf("%u", &numOperacoes);

    while (numOperacoes--) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%lld", &numero);
            push(&pilha, numero);
            if (pilhaMinimos.topo == NULL || numero <= pilhaMinimos.topo->numero) {
                push(&pilhaMinimos, numero);
            }
        } else if (strcmp(operacao, "POP") == 0) {
            if (pilha.topo != NULL) {
                if (pilha.topo->numero == pilhaMinimos.topo->numero) {
                    pop(&pilhaMinimos);
                }
                pop(&pilha);
            } else {
                printf("EMPTY\n");
            }
        } else if (strcmp(operacao, "MIN") == 0) {
            if (pilhaMinimos.topo == NULL) {
                printf("EMPTY\n");
            } else {
                printf("%lld\n", pilhaMinimos.topo->numero);
            }
        }
    }

    return 0;
}

void criaPilha(tipoPilha *pilha) {
    pilha->topo = NULL;
}

void push(tipoPilha *pilha, long long numero) {
    tipoNo *auxiliar = (tipoNo *) malloc(sizeof(tipoNo));
    if (!auxiliar)
        exit(1);

    auxiliar->numero = numero;
    auxiliar->proximo = pilha->topo;
    pilha->topo = auxiliar;
}

void pop(tipoPilha *pilha) {
    tipoNo *auxiliar = pilha->topo;
    if (auxiliar != NULL) {
        pilha->topo = auxiliar->proximo;
        free(auxiliar);
    }
}

long long menorDaPilha(tipoPilha *pilha) {
    if (pilha->topo != NULL) {
        return pilha->topo->numero;
    } else {
        return -1; // Indicador de que a pilha está vazia
    }
}
