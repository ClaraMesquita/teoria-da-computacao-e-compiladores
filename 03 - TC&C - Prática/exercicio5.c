/*
Implemente um grafo rotulado G = { N, R, A } em que:
a. N é o conjunto de vértices (nós ou nodos).
b. R é o conjunto de rótulos.
c. A é uma relação N x N x R (aresta, arcos).
O grafo deve ser representado em uma matriz que armazene a distância das estradas que
ligam 4 cidades vizinhas. O algoritmo deve:
1. Possuir um procedimento não recursivo para inserir a distância entre duas cidades
na matriz.
2. Possuir um procedimento não recursivo para contar quantas estradas ligam as
cidades.
3. Possuir um procedimento não recursivo para imprimir a matriz.
4. Possuir uma função recursiva que receba a identificação de duas cidades como
parâmetro e:
o Retorne a distância entre as cidades se houver uma estrada entre elas.
o Retorne zero se não houver uma estrada ligando as cidades.
*/



#include <stdio.h>

#define MAX_CIDADES 4

// Definir o grafo e as cidades
int grafo[MAX_CIDADES][MAX_CIDADES];

// Função para inserir a distância entre duas cidades na matriz
void inserirDistancia(int cidade1, int cidade2, int distancia) {
    grafo[cidade1][cidade2] = distancia;
    grafo[cidade2][cidade1] = distancia; // Como é um grafo não direcionado, atualize a distância nos dois sentidos
}

// Função para contar quantas estradas ligam as cidades
int contarEstradas(int cidade) {
    int contador = 0;
    for (int i = 0; i < MAX_CIDADES; i++) {
        if (grafo[cidade][i] > 0) {
            contador++;
        }
    }
    return contador;
}

// Função para imprimir a matriz com rótulos de linha e coluna
void imprimirMatriz() {
    // Imprimir rótulos das colunas
    printf("    ");
    for (int j = 0; j < MAX_CIDADES; j++) {
        printf("%-4d", j);
    }
    printf("\n");

    // Imprimir separador
    printf("    ");
    for (int j = 0; j < MAX_CIDADES; j++) {
        printf("----");
    }
    printf("\n");

    // Imprimir matriz com rótulos de linha
    for (int i = 0; i < MAX_CIDADES; i++) {
        printf("%-2d |", i);
        for (int j = 0; j < MAX_CIDADES; j++) {
            printf("%-4d", grafo[i][j]);
        }
        printf("\n");
    }
}


// Função recursiva para obter a distância entre duas cidades
int obterDistanciaRecursiva(int cidadeOrigem, int cidadeDestino) {
    if (cidadeOrigem == cidadeDestino){
        return 0;
    }
    // Base da recursão: se há uma distância direta, retorne essa distância
    if (grafo[cidadeOrigem][cidadeDestino] > 0) {
        return grafo[cidadeOrigem][cidadeDestino];
    }
    
    // Caso contrário, explore outros caminhos
    for (int i = 0; i < MAX_CIDADES; ++i) {
        if (grafo[cidadeOrigem][i] > 0) {
            int distanciaIntermediaria = obterDistanciaRecursiva(i, cidadeDestino);
            if (distanciaIntermediaria > 0) {
                // Se encontrarmos uma distância intermediária, retorne a soma das distâncias
                return grafo[cidadeOrigem][i] + distanciaIntermediaria;
            }
        }
    }

    // Se nenhum caminho for encontrado, retorne 0
    return 0;
}


int main() {

    // Inicialize o grafo
    for (int i = 0; i < MAX_CIDADES; i++) {
        for (int j = 0; j < MAX_CIDADES; j++) {
            grafo[i][j] = 0;
        }
    }

    // Insira distâncias entre cidades
    inserirDistancia(0, 1, 4);
    inserirDistancia(1, 2, 2);
    inserirDistancia(2, 3, 3);
    inserirDistancia(0, 3, 5);

    // Imprima a matriz
    printf("Matriz de distâncias:\n");
    imprimirMatriz();

    int cidade,cidadeDestino,cidadeOrigem;

    // Solicita ao usuário informar a cidades
    printf("Informe a cidade para contar as estradas: ");
    scanf("%d", &cidade);

    // Conte as estradas que ligam a cidade 
    int estradasCidade = contarEstradas(cidade);
    printf("Cidade %d tem %d estradas ligadas.\n", cidade ,estradasCidade);


    // Solicitar ao usuário informar as cidades
    printf("Informe a cidade de origem: ");
    scanf("%d", &cidadeOrigem);

    printf("Informe a cidade de destino: ");
    scanf("%d", &cidadeDestino);


    // Obtenha a distância entre cidades
    int distancia = obterDistanciaRecursiva(cidadeOrigem, cidadeDestino);
    printf("A distância entre cidade %d e cidade %d é %d.\n", cidadeOrigem, cidadeDestino, distancia);

    return 0;
}