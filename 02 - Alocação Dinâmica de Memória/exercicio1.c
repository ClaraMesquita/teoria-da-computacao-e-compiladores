#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente um array de inteiros
int* alocarArray(int tamanho) {
    int *array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

// Função para preencher o array
void preencherArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = i * 10;
    }
}

// Função para imprimir o array
void imprimirArray(int *array, int tamanho) {
    printf("Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Chama a função para alocar dinamicamente o array
    array = alocarArray(n);

    // Chama a função para preencher o array
    preencherArray(array, n);

    // Chama a função para imprimir o array
    imprimirArray(array, n);

    // Libera a memória alocada com malloc
    free(array);

    return 0;
}
