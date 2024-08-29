#include <stdio.h>

int main() {
    // Declaração da variável para a senha de entrada
    int tentativa_senha = 0;

    // Loop para verificar a senha até que seja correta
    do {
        // Lê a senha do usuário
        scanf("%d", &tentativa_senha);

        // Verifica se a senha está correta
        if (tentativa_senha == 2002) {
            // Senha correta, permite o acesso e termina o programa
            printf("Acesso Permitido\n");
            break;  // Encerra o loop quando a senha está correta
        } else {
            // Senha incorreta, exibe mensagem de erro
            printf("Senha Invalida\n");
        }
    } while (1); // Loop infinito até que a senha correta seja inserida

    return 0;  // Encerra o programa
}
