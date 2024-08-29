#include <stdio.h>

int main() {
    // Variável para armazenar o código de DDD inserido pelo usuário
    int codigo_ddd;

    // Leitura do DDD fornecido pelo usuário
    scanf("%d", &codigo_ddd);

    // Verificação do DDD e mapeamento para a cidade correspondente
    if (codigo_ddd == 61) {
        printf("Brasilia\n");
    } else if (codigo_ddd == 71) {
        printf("Salvador\n");
    } else if (codigo_ddd == 11) {
        printf("Sao Paulo\n");
    } else if (codigo_ddd == 21) {
        printf("Rio de Janeiro\n");
    } else if (codigo_ddd == 32) {
        printf("Juiz de Fora\n");
    } else if (codigo_ddd == 19) {
        printf("Campinas\n");
    } else if (codigo_ddd == 27) {
        printf("Vitoria\n");
    } else if (codigo_ddd == 31) {
        printf("Belo Horizonte\n");
    } else {
        // Mensagem padrão caso o DDD não esteja na lista
        printf("DDD nao cadastrado\n");
    }

    return 0;  // Encerra o programa
}
