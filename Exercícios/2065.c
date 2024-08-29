#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int codigo;
    int qtd_itens;
    struct Cliente* prox;
} Cliente;

typedef struct {
    int identificacao;
    int tempo_ocio;
} Empregado;

/* A função insere um novo cliente no fim da fila encadeada */
void adicionarCliente(Cliente **inicio, Cliente **fim, int codigo, int qtd_itens) {
    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));
    novoCliente->codigo = codigo;
    novoCliente->qtd_itens = qtd_itens;
    novoCliente->prox = NULL;

    if (*fim == NULL) {
        *fim = *inicio = novoCliente;
    } else {
        (*fim)->prox = novoCliente;
        *fim = novoCliente;
    }
}

/* A função remove o primeiro cliente da fila encadeada */
void removerCliente(Cliente **inicio, Cliente **fim) {
    Cliente *temp;
    temp = *inicio;
    *inicio = temp->prox;
    free(temp);
    if (*inicio == NULL) {
        *fim = NULL;
    }
}

/* A função inicializa os empregados e lê seus tempos de atendimento */
void configurarEmpregados(Empregado* empregados, int* tempo_por_empregado, int total_empregados) {
    for (int i = 0; i < total_empregados; i++) {
        scanf("%d", &tempo_por_empregado[i]);
        if (tempo_por_empregado[i] < 1 || tempo_por_empregado[i] > 100) {
            printf("Tempo de atendimento inválido para o empregado %d.\n", i + 1);
            exit(1);
        }
        empregados[i].identificacao = i + 1;
        empregados[i].tempo_ocio = 0;
    }
}

/* A função processa a fila de clientes e retorna o tempo total de atendimento */
int calcularTempoTotal(Cliente** inicio, Cliente** fim, Empregado* empregados, int* tempo_por_empregado, int total_empregados) {
    int tempo_final = 0;
    while (*inicio != NULL) {
        Cliente* clienteAtual = *inicio;
        int itens_cliente = clienteAtual->qtd_itens;
        removerCliente(inicio, fim);
        int indice_min = 0;
        for (int i = 1; i < total_empregados; i++) {
            if (empregados[i].tempo_ocio < empregados[indice_min].tempo_ocio) {
                indice_min = i;
            }
        }
        int tempo_atualizado = empregados[indice_min].tempo_ocio + itens_cliente * tempo_por_empregado[indice_min];
        if (tempo_atualizado > tempo_final) {
            tempo_final = tempo_atualizado;
        }
        empregados[indice_min].tempo_ocio = tempo_atualizado;
    }

    return tempo_final;
}

int main () {
    int num_empregados, num_clientes;
    Cliente *inicio_fila = NULL;
    Cliente *fim_fila = NULL;

    scanf("%d %d", &num_empregados, &num_clientes);
    
    if (num_empregados < 1 || num_empregados > 10000 || num_clientes < num_empregados || num_clientes > 10000) {
        return 1;
    }

    int* tempo_por_empregado = (int*)malloc(num_empregados * sizeof(int));
    Empregado* empregados = (Empregado*)malloc(num_empregados * sizeof(Empregado));
    configurarEmpregados(empregados, tempo_por_empregado, num_empregados);

    for (int i = 0; i < num_clientes; i++) {
        int quantidade_itens;
        scanf("%d", &quantidade_itens);
        if (quantidade_itens < 1 || quantidade_itens > 100) {
            printf("Número de itens inválido para o cliente %d.\n", i + 1);
            return 1;
        }
        adicionarCliente(&inicio_fila, &fim_fila, i + 1, quantidade_itens);
    }

    int tempo_final = calcularTempoTotal(&inicio_fila, &fim_fila, empregados, tempo_por_empregado, num_empregados);
    printf("%d\n", tempo_final);

    free(tempo_por_empregado);
    free(empregados);

    return 0;
}
