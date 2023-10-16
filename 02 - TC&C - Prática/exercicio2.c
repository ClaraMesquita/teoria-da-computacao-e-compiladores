#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTOS 100 // Ajuste conforme necessário

// Função para ler uma sequência de números naturais a partir do teclado e armazenar em um arquivo
void lerSequenciaEArmazenarEmArquivo(FILE *arquivo, int *tamanho) {
    int n;
    printf("Digite o número de elementos da sequência: ");
    scanf("%d", tamanho);
    n = *tamanho;

    if (n <= 0) {
        printf("O número de elementos deve ser maior que zero.\n");
        return;
    }

    printf("Digite os elementos da sequência:\n");
    for (int i = 0; i < n; i++) {
        int elemento;
        scanf("%d", &elemento);
        fprintf(arquivo, "%d ", elemento);
    }

    fprintf(arquivo, "\n");
}


// Função para ler uma sequência de números naturais a partir de um arquivo e armazenar em um vetor
void lerSequenciaDeArquivo(FILE *arquivo, int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
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

void gerarConjunto(int sequencia[], int tamanho, int **conjunto, int *tamanhoConjunto) {
    // Inicializar o conjunto
    *tamanhoConjunto = 0;
    
    // Alocar dinamicamente memória para o conjunto
    *conjunto = (int *)malloc(tamanho * sizeof(int));

    // Adicionar elementos distintos ao conjunto
    for (int i = 0; i < tamanho; i++) {
        int elemento = sequencia[i];
        int repetido = 0;

        // Verificar se o elemento já está no conjunto
        for (int j = 0; j < *tamanhoConjunto; j++) {
            if ((*conjunto)[j] == elemento) {
                repetido = 1;
                break;
            }
        }

        // Adicionar elemento ao conjunto se não for repetido
        if (!repetido) {
            (*conjunto)[*tamanhoConjunto] = elemento;
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

void armazenarConjuntoEmArquivo(int conjunto[], int tamanho, FILE *arquivo) {
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fprintf(arquivo, "%d\n", tamanho);

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d ", conjunto[i]);
    }

    fprintf(arquivo, "\n");
}

void calcularConjuntoPotencia(int conjunto[], int tamanho, FILE *arquivo) {
    int totalSubconjuntos = pow(2, tamanho);

    for (int i = 0; i < totalSubconjuntos; i++) {
        fprintf(arquivo, "{ ");

        for (int j = 0; j < tamanho; j++) {
            if ((i & (1 << j)) != 0) {
                fprintf(arquivo, "%d ", conjunto[j]);
            }
        }

        fprintf(arquivo, "}\n");
    }
}

// Função para calcular e armazenar os conjuntos próprios no arquivo
void calcularConjuntosProprios(int conjunto[], int tamanho, FILE *arquivo) {
    // TODO: Implemente esta função
}

// Função para calcular e armazenar a união de dois conjuntos
void calcularUniao(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, FILE *arquivo) {
    // Inicializar o conjunto de união
    int uniao[MAX_ELEMENTOS];
    int tamanhoUniao = 0;

    // Adicionar elementos de A à união
    for (int i = 0; i < tamanhoA; i++) {
        uniao[tamanhoUniao++] = conjuntoA[i];
    }

    // Adicionar elementos de B à união, excluindo duplicatas que já estão em A
    for (int i = 0; i < tamanhoB; i++) {
        int duplicata = 0;
        for (int j = 0; j < tamanhoA; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                duplicata = 1;
                break;
            }
        }

        if (!duplicata) {
            uniao[tamanhoUniao++] = conjuntoB[i];
        }
    }

    // Apresentar a união na tela
    printf("União de A e B: { ");
    for (int i = 0; i < tamanhoUniao; i++) {
        printf("%d ", uniao[i]);
    }
    printf("}\n");

    // Armazenar a união no arquivo
    fprintf(arquivo, "União de A e B: { ");
    for (int i = 0; i < tamanhoUniao; i++) {
        fprintf(arquivo, "%d ", uniao[i]);
    }
    fprintf(arquivo, "}\n");
}

// Função para calcular e armazenar a interseção de dois conjuntos
void calcularIntersecao(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, FILE *arquivo) {
    // Inicializar o conjunto de interseção
    int intersecao[MAX_ELEMENTOS]; // Tamanho máximo é MAX_ELEMENTOS
    int tamanhoIntersecao = 0;

    // Verificar elementos em A que também estão em B
    for (int i = 0; i < tamanhoA; i++) {
        for (int j = 0; j < tamanhoB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                // Elemento presente em ambos os conjuntos, adicionar à interseção
                intersecao[tamanhoIntersecao++] = conjuntoA[i];
                break;  // Parar de procurar em B para este elemento de A
            }
        }
    }

    // Apresentar a interseção na tela
    printf("Interseção de A e B: { ");
    for (int i = 0; i < tamanhoIntersecao; i++) {
        printf("%d ", intersecao[i]);
    }
    printf("}\n");

    // Armazenar a interseção no arquivo
    fprintf(arquivo, "Interseção de A e B: { ");
    for (int i = 0; i < tamanhoIntersecao; i++) {
        fprintf(arquivo, "%d ", intersecao[i]);
    }
    fprintf(arquivo, "}\n");
}

// Função para calcular e armazenar a diferença de dois conjuntos
void calcularDiferenca(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, FILE *arquivo) {
    // Inicializar o conjunto de diferença
    int diferenca[MAX_ELEMENTOS];
    int tamanhoDiferenca = 0;

    // Verificar elementos em A que não estão em B
    for (int i = 0; i < tamanhoA; i++) {
        int pertenceAB = 0;

        for (int j = 0; j < tamanhoB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                pertenceAB = 1;
                break;
            }
        }

        if (!pertenceAB) {
            diferenca[tamanhoDiferenca++] = conjuntoA[i];
        }
    }

    // Apresentar a diferença na tela
    printf("Diferença de: { ");
    for (int i = 0; i < tamanhoDiferenca; i++) {
        printf("%d ", diferenca[i]);
        fprintf(arquivo, "%d ", diferenca[i]);
    }
    printf("}\n");
    fprintf(arquivo, "}\n");
}


int main() {
    FILE *arquivo = fopen("arquivo.txt", "w+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
     int tamanho1, tamanho2;

    printf("Sequência 1:\n");
    lerSequenciaEArmazenarEmArquivo(arquivo,&tamanho1);

    printf("Sequência 2:\n");
    lerSequenciaEArmazenarEmArquivo(arquivo,&tamanho2);

    // Retorna ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);


    int *sequencia1 = (int *)malloc(tamanho1 * sizeof(int));
    lerSequenciaDeArquivo(arquivo, sequencia1, tamanho1);


    int *sequencia2 = (int *)malloc(tamanho2 * sizeof(int));
    lerSequenciaDeArquivo(arquivo, sequencia2, tamanho2);

    printf("Sequência 1 lida do arquivo: ");
    imprimirVetor(sequencia1, tamanho1);

    printf("Sequência 2 lida do arquivo: ");
    imprimirVetor(sequencia2, tamanho2);

    //
    int tamanhoConjuntoA, tamanhoConjuntoB;
    int *conjuntoA = NULL, *conjuntoB = NULL;

    gerarConjunto(sequencia1, tamanho1, &conjuntoA, &tamanhoConjuntoA);
    gerarConjunto(sequencia2, tamanho2, &conjuntoB, &tamanhoConjuntoB);

    exibirConjunto(conjuntoA, tamanhoConjuntoA, "A");
    exibirConjunto(conjuntoB, tamanhoConjuntoB, "B");

    armazenarConjuntoEmArquivo(conjuntoA, tamanhoConjuntoA, arquivo);
    armazenarConjuntoEmArquivo(conjuntoB, tamanhoConjuntoB, arquivo);

    //

    fprintf(arquivo, "Conjunto potência de A:\n");
    calcularConjuntoPotencia(conjuntoA, tamanhoConjuntoA, arquivo);

    fprintf(arquivo, "\nConjunto potência de B:\n");
    calcularConjuntoPotencia(conjuntoB, tamanhoConjuntoB, arquivo);

    //

    fprintf(arquivo, "Conjuntos próprios de A:\n");
    // calcularConjuntosProprios(conjuntoA, tamanhoConjuntoA, arquivo);

    fprintf(arquivo, "\nConjuntos próprios de B:\n");
    // calcularConjuntosProprios(conjuntoB, tamanhoConjuntoB, arquivo);

    //

    calcularUniao(conjuntoA, tamanhoConjuntoA, conjuntoB, tamanhoConjuntoB, arquivo);

    //

    calcularIntersecao(conjuntoA, tamanhoConjuntoA, conjuntoB, tamanhoConjuntoB, arquivo);
    
    //
    
    calcularDiferenca(conjuntoA, tamanhoConjuntoA, conjuntoB, tamanhoConjuntoB, arquivo);
    calcularDiferenca(conjuntoB, tamanhoConjuntoB, conjuntoA, tamanhoConjuntoA, arquivo);

    // Liberar memória alocada dinamicamente
    free(sequencia1);
    free(sequencia2);

    free(conjuntoA);
    free(conjuntoB);

    fclose(arquivo);

    return 0;
}
