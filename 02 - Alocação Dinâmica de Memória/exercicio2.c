#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura Pessoa
struct Pessoa {
    char cpf[12];
    char nome[50];
    float salario;
};

// Função para alocar dinamicamente um array de estruturas Pessoa
struct Pessoa* alocarArrayPessoa(int tamanho) {
    struct Pessoa *array = (struct Pessoa *)calloc(tamanho, sizeof(struct Pessoa));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

// Função para preencher o array de estruturas Pessoa
void preencherArrayPessoa(struct Pessoa *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%s", array[i].cpf);

        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", array[i].nome);

        printf("Digite o salário da pessoa %d: ", i + 1);
        scanf("%f", &array[i].salario);
    }
}

// Função para imprimir o array de estruturas Pessoa
void imprimirArrayPessoa(struct Pessoa *array, int tamanho) {
    printf("Array de Pessoas:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("CPF: %s\n", array[i].cpf);
        printf("Nome: %s\n", array[i].nome);
        printf("Salário: %.2f\n\n", array[i].salario);
        printf("\n");
    }
}

int main() {
    struct Pessoa *array;
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Chama a função para alocar dinamicamente o array de estruturas Pessoa
    array = alocarArrayPessoa(n);

    // Chama a função para preencher o array de estruturas Pessoa
    preencherArrayPessoa(array, n);

    // Chama a função para imprimir o array de estruturas Pessoa
    imprimirArrayPessoa(array, n);

    // Libera a memória alocada com calloc
    free(array);

    return 0;
}
