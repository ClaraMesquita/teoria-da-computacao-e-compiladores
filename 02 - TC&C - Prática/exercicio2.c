#include <stdio.h>
#include <stdlib.h>

// Função para ler uma sequência de números naturais a partir do teclado e armazenar em um arquivo
void lerSequenciaEArmazenarEmArquivo(FILE *arquivo) {
    int n;
    printf("Digite o número de elementos da sequência: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("O número de elementos deve ser maior que zero.\n");
        return;
    }
    
    int *sequencia = (int *)malloc(n * sizeof(int));
    
    printf("Digite os elementos da sequência:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequencia[i]);
    }
    
    // Escreve a sequência no arquivo
    fprintf(arquivo, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%d ", sequencia[i]);
    }
    
    fprintf(arquivo, "\n");
    
    free(sequencia);
}

// Função para ler uma sequência de números naturais a partir de um arquivo e armazenar em um vetor
void lerSequenciaDeArquivo(FILE *arquivo, int *vetor) {
    int n;
    fscanf(arquivo, "%d", &n);
    
    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%d", &vetor[i]);
    }
}

// Função para imprimir um vetor
void imprimirVetor(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void gerarConjunto(int sequencia[], int tamanho, int conjunto[], int *tamanhoConjunto) {
    // Inicializar o conjunto
    *tamanhoConjunto = 0;

    // Adicionar elementos distintos ao conjunto
    for (int i = 0; i < tamanho; i++) {
        int elemento = sequencia[i];
        int repetido = 0;

        // Verificar se o elemento já está no conjunto
        for (int j = 0; j < *tamanhoConjunto; j++) {
            if (conjunto[j] == elemento) {
                repetido = 1;
                break;
            }
        }

        // Adicionar elemento ao conjunto se não for repetido
        if (!repetido) {
            conjunto[*tamanhoConjunto] = elemento;
            (*tamanhoConjunto)++;
        }
    }
}

void exibirConjunto(int conjunto[], int tamanho, const char *nomeConjunto) {
    printf("Conjunto %s: ", nomeConjunto);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", conjunto[i]);
    }
    printf("\n");
}

void armazenarConjuntoEmArquivo(int conjunto[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", conjunto[i]);
    }

    fclose(arquivo);
}

int main() {
    FILE *arquivo = fopen("sequencias.txt", "w+");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    printf("Sequência 1:\n");
    lerSequenciaEArmazenarEmArquivo(arquivo);
    
    printf("Sequência 2:\n");
    lerSequenciaEArmazenarEmArquivo(arquivo);
    
    // Retorna ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);
    
    int tamanho1, tamanho2;
    fscanf(arquivo, "%d", &tamanho1);
    
    int *sequencia1 = (int *)malloc(tamanho1 * sizeof(int));
    lerSequenciaDeArquivo(arquivo, sequencia1);
    
    fscanf(arquivo, "%d", &tamanho2);
    
    int *sequencia2 = (int *)malloc(tamanho2 * sizeof(int));
    lerSequenciaDeArquivo(arquivo, sequencia2);
    
    printf("Sequência 1 lida do arquivo: ");
    imprimirVetor(sequencia1, tamanho1);
    
    printf("Sequência 2 lida do arquivo: ");
    imprimirVetor(sequencia2, tamanho1);
    
    //
    int tamanhoA, tamanhoB, tamanhoConjuntoA, tamanhoConjuntoB;
    int conjuntoA[], conjuntoB[];
    
    gerarConjunto(sequencia1, tamanho1, conjuntoA, &tamanhoConjuntoA);
    gerarConjunto(sequencia2, tamanho2, conjuntoB, &tamanhoConjuntoB);

    exibirConjunto(conjuntoA, tamanhoConjuntoA, "A");
    exibirConjunto(conjuntoB, tamanhoConjuntoB, "B");

    armazenarConjuntoEmArquivo(conjuntoA, tamanhoConjuntoA, "sequenciaA.txt");
    armazenarConjuntoEmArquivo(conjuntoB, tamanhoConjuntoB, "sequenciaB.txt");




    
    free(sequencia1);
    free(sequencia2);
    
    fclose(arquivo);
    
    return 0;
}
