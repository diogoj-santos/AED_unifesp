#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_PAIS 24
#define TAM_PAIS 50
#define TAM_SAUDACAO 100

// Arrays de países e saudações
char *paises[NUM_PAIS] = {
    "brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos",
    "inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile",
    "mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria",
    "marrocos", "japao"
};

char *saudacoes[NUM_PAIS] = {
    "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
    "Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!",
    "Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!",
    "Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!",
    "Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!"
};

// Estrutura para armazenar país e saudação
typedef struct {
    char pais[TAM_PAIS];
    char saudacao[TAM_SAUDACAO];
} tradutor;

tradutor traducao[NUM_PAIS];

// Função para preencher a tabela de tradução
void preencheTradutor() {
    for (unsigned short i = 0; i < NUM_PAIS; i++) {
        strcpy(traducao[i].pais, paises[i]);
        strcpy(traducao[i].saudacao, saudacoes[i]);
    }
}

// Função para procurar a saudação com base no país
bool pesquisaPais(char *pais, unsigned short *posicao) {
    for (unsigned short i = 0; i < NUM_PAIS; i++) {
        if (strcmp(traducao[i].pais, pais) == 0) {
            *posicao = i;
            return true;
        }
    }
    return false;
}

int main() {
    preencheTradutor();
    char pais[TAM_PAIS];
    unsigned short posicao;

    // Ler a entrada até EOF
    while (scanf("%s", pais) != EOF) {
        if (pesquisaPais(pais, &posicao)) {
            printf("%s\n", traducao[posicao].saudacao);
        } else {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}
