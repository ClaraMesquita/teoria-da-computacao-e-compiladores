#include <stdio.h>
#include <stdlib.h>

/**@steniomatos
 * 
 * Um(a) procedimento/função que gere, e apresente na tela, o conjunto A a partir da
primeira sequência e o conjunto B a partir da segunda sequência. A e B também são
vetores. Armazene os conjuntos A e B no arquivo original. OBS: todos os elementos de
um conjunto são distintos, não há elementos repetidos.
*/

#define TAMANHO_MAXIMO 100  // Defina o tamanho máximo dos vetores

void lerEArmazenarSequencias(char *nomeArquivo, int vetor1[], int vetor2[], int *tamanho1, int *tamanho2) {
    FILE *arquivo;
    int numero;

    // Abre o arquivo no modo de leitura
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Inicializa os tamanhos dos vetores
    *tamanho1 = 0;
    *tamanho2 = 0;

    int sequenciaAtual = 1; // Flag para identificar a sequência atual

    // Lê sequências do arquivo e armazena nos vetores apropriados
    while (fscanf(arquivo, "%d", &numero) == 1) {
        if (sequenciaAtual == 1) {
            vetor1[*tamanho1] = numero;
            (*tamanho1)++;
        } else {
            vetor2[*tamanho2] = numero;
            (*tamanho2)++;
        }

        if (*tamanho1 >= TAMANHO_MAXIMO) {
            printf("Erro: Tamanho máximo do vetor1 atingido.\n");
            exit(1);
        }

        if (*tamanho2 >= TAMANHO_MAXIMO) {
            printf("Erro: Tamanho máximo do vetor2 atingido.\n");
            exit(1);
        }

        // Lê uma quebra de linha para separar as sequências
        fscanf(arquivo, "\n");

        // Troca para a próxima sequência
        sequenciaAtual = 3 - sequenciaAtual; // Alternância entre 1 e 2
    }

    fclose(arquivo);
}

// Função para gerar conjuntos A e B a partir das sequências lidas
void gerarConjuntos(int vetor1[], int tamanho1, int vetor2[], int tamanho2, int conjuntoA[], int *tamanhoA, int conjuntoB[], int *tamanhoB) {
    // Inicializa os conjuntos
    *tamanhoA = 0;
    *tamanhoB = 0;

    // Adiciona elementos distintos ao conjunto A
    for (int i = 0; i < tamanho1; i++) {
        int elemento = vetor1[i];

        // Verifica se o elemento já está no conjunto A
        int elementoRepetido = 0;
        for (int j = 0; j < *tamanhoA; j++) {
            if (conjuntoA[j] == elemento) {
                elementoRepetido = 1;
                break;
            }
        }

        // Se o elemento não estiver no conjunto A, adiciona
        if (!elementoRepetido) {
            conjuntoA[*tamanhoA] = elemento;
            (*tamanhoA)++;

            if (*tamanhoA >= TAMANHO_MAXIMO) {
                printf("Erro: Tamanho máximo do conjunto A atingido.\n");
                exit(1);
            }
        }
    }

    // Adiciona elementos distintos ao conjunto B
    for (int i = 0; i < tamanho2; i++) {
        int elemento = vetor2[i];

        // Verifica se o elemento já está no conjunto B
        int elementoRepetido = 0;
        for (int j = 0; j < *tamanhoB; j++) {
            if (conjuntoB[j] == elemento) {
                elementoRepetido = 1;
                break;
            }
        }

        // Se o elemento não estiver no conjunto B, adiciona
        if (!elementoRepetido) {
            conjuntoB[*tamanhoB] = elemento;
            (*tamanhoB)++;

            if (*tamanhoB >= TAMANHO_MAXIMO) {
                printf("Erro: Tamanho máximo do conjunto B atingido.\n");
                exit(1);
            }
        }
    }
}

// Função para apresentar um conjunto na tela
void apresentarConjunto(int conjunto[], int tamanho) {
    printf("Conjunto: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", conjunto[i]);
    }
    printf("\n");
}

int main() {
    // Nome do arquivo contendo as sequências
    char nomeArquivo[] = "sequencias.txt";

    // Vetores para armazenar as sequências
    int vetor1[TAMANHO_MAXIMO];
    int vetor2[TAMANHO_MAXIMO];

    // Tamanhos dos vetores
    int tamanho1, tamanho2;

    // Chama a função para ler e armazenar as sequências nos vetores
    lerEArmazenarSequencias(nomeArquivo, vetor1, vetor2, &tamanho1, &tamanho2);

    // Conjuntos A e B
    int conjuntoA[TAMANHO_MAXIMO];
    int tamanhoA;
    int conjuntoB[TAMANHO_MAXIMO];
    int tamanhoB;

    // Chama a função para gerar conjuntos A e B
    gerarConjuntos(vetor1, tamanho1, vetor2, tamanho2, conjuntoA, &tamanhoA, conjuntoB, &tamanhoB);

    // Apresenta os conjuntos na tela
    printf("Conjunto A:\n");
    apresentarConjunto(conjuntoA, tamanhoA);

    printf("Conjunto B:\n");
    apresentarConjunto(conjuntoB, tamanhoB);

    // Armazena os conjuntos A e B no arquivo original
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(arquivo, "\n"); // Adiciona uma quebra de linha antes de inserir os conjuntos

    // Armazena conjunto A no arquivo
    for (int i = 0; i < tamanhoA; i++) {
        fprintf(arquivo, "%d ", conjuntoA[i]);
    }

    fprintf(arquivo, "\n"); // Adiciona uma quebra de linha entre os conj

    // Armazena conjunto B no arquivo
    for (int i = 0; i < tamanhoB; i++) {
        fprintf(arquivo, "%d ", conjuntoB[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
