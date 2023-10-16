#include <stdio.h>
#include <stdlib.h>

/**
 * @steniomatos
 * Um(a) procedimento/função que determine, e apresente na tela, o conjunto potência
(das partes) de A e de B. Armazene os conjuntos potência no arquivo original.
*/

#define TAMANHO_MAXIMO 100  // Defina o tamanho máximo dos conjuntos e vetores

// Função para escrever um conjunto em um arquivo
void escreverConjuntoEmArquivo(FILE *arquivo, int conjunto[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d ", conjunto[i]);
    }
    fprintf(arquivo, "\n");
}

// Função para ler sequências a partir de um arquivo e armazenar em vetores
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

    // Fecha o arquivo
    fclose(arquivo);
}

// Função para gerar conjuntos A e B a partir das sequências lidas
void gerarConjuntos(int vetor1[], int tamanho1, int vetor2[], int tamanho2, int conjuntoA[], int *tamanhoA, int conjuntoB[], int *tamanhoB) {
    // Inicializa conjuntos vazios
    *tamanhoA = 0;
    *tamanhoB = 0;

    // Adiciona elementos únicos do vetor1 para conjuntoA
    for (int i = 0; i < tamanho1; i++) {
        int elementoRepetido = 0;

        // Verifica se o elemento já está em conjuntoA
        for (int j = 0; j < *tamanhoA; j++) {
            if (vetor1[i] == conjuntoA[j]) {
                elementoRepetido = 1;
                break;
            }
        }

        // Adiciona o elemento a conjuntoA se não estiver repetido
        if (!elementoRepetido) {
            conjuntoA[*tamanhoA] = vetor1[i];
            (*tamanhoA)++;
        }
    }

    // Adiciona elementos únicos do vetor2 para conjuntoB
    for (int i = 0; i < tamanho2; i++) {
        int elementoRepetido = 0;

        // Verifica se o elemento já está em conjuntoB
        for (int j = 0; j < *tamanhoB; j++) {
            if (vetor2[i] == conjuntoB[j]) {
                elementoRepetido = 1;
                break;
            }
        }

        // Adiciona o elemento a conjuntoB se não estiver repetido
        if (!elementoRepetido) {
            conjuntoB[*tamanhoB] = vetor2[i];
            (*tamanhoB)++;
        }
    }
}

// Função para gerar o conjunto potência de um conjunto e armazenar no arquivo
void gerarConjuntoPotencia(int conjunto[], int tamanho, char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Itera sobre todos os possíveis subconjuntos
    for (int mascara = 0; mascara < (1 << tamanho); mascara++) {
        fprintf(arquivo, "{ ");

        // Adiciona elementos do conjunto que estão com bit ligado na máscara
        for (int i = 0; i < tamanho; i++) {
            if (mascara & (1 << i)) {
                fprintf(arquivo, "%d ", conjunto[i]);
            }
        }

        fprintf(arquivo, "}\n");
    }

    fclose(arquivo);
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

    // Armazena os conjuntos A e B no arquivo original
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(arquivo, "\n"); // Adiciona uma quebra de linha antes de inserir os conjuntos

    // Armazena conjunto A no arquivo
    escreverConjuntoEmArquivo(arquivo, conjuntoA, tamanhoA);

    // Armazena conjunto B no arquivo
    escreverConjuntoEmArquivo(arquivo, conjuntoB, tamanhoB);

    fclose(arquivo);

    // Gera e armazena o conjunto potência de A no arquivo
    gerarConjuntoPotencia(conjuntoA, tamanhoA, nomeArquivo);

    // Gera e armazena o conjunto potência de B no arquivo
    gerarConjuntoPotencia(conjuntoB, tamanhoB, nomeArquivo);

    return 0;
}
