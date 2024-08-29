#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define uma estrutura para armazenar informações sobre os alunos
typedef struct {
    char nome[200];          // Nome do aluno
    short presenca;          // Contador de presenças
    short ausencia;          // Contador de ausências
    short totalAulas;        // Contador total de aulas consideradas (presença + ausência)
    float taxaPresenca;      // Taxa de presença (presença / total de aulas)
} classe;

int main() {
    unsigned short qtsAlunos, casos;        // Quantidade de alunos e quantidade de casos de teste
    unsigned short i, j;                    // Variáveis de controle de loop
    char registro[5000];                    // String para armazenar os registros de presença (P, A, M)

    // Lê o número de casos de teste
    scanf("%hu", &casos);

    // Loop para processar cada caso de teste
    while (casos--) {
        // Lê o número de alunos para o caso atual
        scanf("%hu", &qtsAlunos);

        classe alunos[qtsAlunos];            // Declaração do array de alunos
        memset(alunos, 0, sizeof(alunos));   // Inicializa todos os valores dos alunos como 0

        // Lê os nomes dos alunos
        for (i = 0; i < qtsAlunos; i++) {
            scanf(" %s", alunos[i].nome);
        }

        // Processa os registros de presença para cada aluno
        for (i = 0; i < qtsAlunos; i++) {
            // Lê o registro de presença (P = Presente, A = Ausente, M = Atestado)
            scanf(" %s", registro);

            // Itera sobre cada caractere do registro
            for (j = 0; registro[j]; j++) {
                if (registro[j] == 'P')
                    alunos[i].presenca++;    // Incrementa o contador de presenças
                else if (registro[j] == 'A')
                    alunos[i].ausencia++;    // Incrementa o contador de ausências
                // Atestados ('M') são ignorados no cálculo do total de aulas
            }

            // Calcula o total de aulas consideradas (presença + ausência)
            alunos[i].totalAulas = alunos[i].presenca + alunos[i].ausencia;

            // Calcula a taxa de presença do aluno
            if (alunos[i].totalAulas > 0) {
                alunos[i].taxaPresenca = (1.0f * alunos[i].presenca) / alunos[i].totalAulas;
            } else {
                alunos[i].taxaPresenca = 1.0f; // Se só teve atestados, considera 100% de presença
            }
        }

        bool primeiroNome = true;  // Flag para controlar a impressão de espaço entre nomes

        // Verifica os alunos com taxa de presença menor que 75%
        for (i = 0; i < qtsAlunos; i++) {
            if (alunos[i].taxaPresenca < 0.75f) {
                if (!primeiroNome) {
                    printf(" "); // Adiciona um espaço entre nomes
                }
                printf("%s", alunos[i].nome); // Imprime o nome do aluno com baixa presença
                primeiroNome = false; // Após o primeiro nome, essa flag se torna falsa
            }
        }

        printf("\n"); // Imprime uma nova linha após listar todos os alunos com baixa presença
    }

    return 0;
}
