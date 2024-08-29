#include <iostream>
#include <cstring>

void stripZeros(char *numStr) {
    int i = 0, j = 0;
    char temp[20]; // Buffer para armazenar o número sem zeros

    while (numStr[i] != '\0') {
        if (numStr[i] != '0') {
            temp[j++] = numStr[i];
        }
        i++;
    }
    temp[j] = '\0'; // Finaliza a nova string
    std::strcpy(numStr, temp); // Copia o resultado de volta para a string original
}

int main() {
    while (true) {
        int M, N, result;
        char resultStr[20]; // String para armazenar o resultado da soma

        std::cin >> M >> N;
        if (M == 0 && N == 0) break;

        result = M + N;
        std::sprintf(resultStr, "%d", result); // Converte o resultado da soma para string

        stripZeros(resultStr); // Remove os zeros da string

        std::cout << resultStr << std::endl; // Imprime o resultado sem zeros
    }

    return 0;
}
