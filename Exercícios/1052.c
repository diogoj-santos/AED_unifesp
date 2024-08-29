#include <stdio.h>

int main() {
    // Array com os nomes dos meses
    const char *nomes[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int mes;
    // Lê o número do mês da entrada
    scanf("%d", &mes);

    // Verifica se o mês está no intervalo válido (1 a 12)
    if (mes >= 1 && mes <= 12) {
        // Imprime o nome do mês correspondente (lembrando que o índice do array é 0 baseado)
        printf("%s\n", nomes[mes - 1]);
    }

    return 0;
}
