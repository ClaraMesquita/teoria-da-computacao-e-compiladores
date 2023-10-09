#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura Veiculo
struct Veiculo {
    char chassi[20];
    char marca[50];
    char modelo[50];
    float preco;
};

// Função para alocar dinamicamente um array de estruturas Veiculo
struct Veiculo* alocarArrayVeiculo(int tamanho) {
    struct Veiculo *array = (struct Veiculo *)malloc(tamanho * sizeof(struct Veiculo));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

// Função para preencher o array de estruturas Veiculo
void preencherArrayVeiculo(struct Veiculo *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o número do chassi do veículo %d: ", i + 1);
        scanf("%s", array[i].chassi);

        printf("Digite a marca do veículo %d: ", i + 1);
        scanf("%s", array[i].marca);

        printf("Digite o modelo do veículo %d: ", i + 1);
        scanf("%s", array[i].modelo);

        printf("Digite o preço do veículo %d: ", i + 1);
        scanf("%f", &array[i].preco);
    }
}

// Função para imprimir o array de estruturas Veiculo
void imprimirArrayVeiculo(struct Veiculo *array, int tamanho) {
    printf("Array de Veículos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Veículo %d:\n", i + 1);
        printf("Chassi: %s\n", array[i].chassi);
        printf("Marca: %s\n", array[i].marca);
        printf("Modelo: %s\n", array[i].modelo);
        printf("Preço: %.2f\n\n", array[i].preco);
        printf("\n");
    }
}

// Função para realocar dinamicamente um array de estruturas Veiculo
struct Veiculo* realocarArrayVeiculo(struct Veiculo *array, int tamanhoAntigo, int novoTamanho) {
    array = (struct Veiculo *)realloc(array, novoTamanho * sizeof(struct Veiculo));
    if (array == NULL) {
        printf("Falha na realocação de memória.\n");
        exit(1);
    }
    // Preencher os elementos adicionais (após a realocação)
    for (int i = tamanhoAntigo; i < novoTamanho; i++) {
        printf("Digite o número do chassi do veículo %d: ", i + 1);
        scanf("%s", array[i].chassi);

        printf("Digite a marca do veículo %d: ", i + 1);
        scanf("%s", array[i].marca);

        printf("Digite o modelo do veículo %d: ", i + 1);
        scanf("%s", array[i].modelo);

        printf("Digite o preço do veículo %d: ", i + 1);
        scanf("%f", &array[i].preco);
    }
    return array;
}

int main() {
    struct Veiculo *array;
    int n;

    printf("Digite o tamanho inicial do array: ");
    scanf("%d", &n);

    // Chama a função para alocar dinamicamente o array de estruturas Veiculo
    array = alocarArrayVeiculo(n);

    // Chama a função para preencher o array de estruturas Veiculo
    preencherArrayVeiculo(array, n);

    // Chama a função para imprimir o array de estruturas Veiculo
    imprimirArrayVeiculo(array, n);

    // Realocar o array para um tamanho maior
    int novoTamanho = n + 2;
    array = realocarArrayVeiculo(array, n, novoTamanho);

    // Chama a função para imprimir o array de estruturas Veiculo após a realocação
    imprimirArrayVeiculo(array, novoTamanho);

    // Libera a memória alocada com malloc e realloc
    free(array);

    return 0;
}
