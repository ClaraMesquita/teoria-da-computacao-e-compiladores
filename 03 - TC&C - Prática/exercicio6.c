#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Estrutura para representar o grafo
typedef struct {
    int numVertices;
    char rLabels[MAX_VERTICES]; // Rótulos dos vértices
    int matrizAdj[MAX_VERTICES][MAX_VERTICES]; // Matriz de adjacência
} Grafo;

// Função para inicializar o grafo
void inicializarGrafo(Grafo *grafo) {
    int i, j;
    grafo->numVertices = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        grafo->rLabels[i] = '\0';
        for (j = 0; j < MAX_VERTICES; j++) {
            grafo->matrizAdj[i][j] = 0;
        }
    }
}

// Função para adicionar um vértice ao grafo
void adicionarVertice(Grafo *grafo, char rLabel) {
    if (grafo->numVertices < MAX_VERTICES) {
        grafo->rLabels[grafo->numVertices] = rLabel;
        grafo->numVertices++;
    } else {
        printf("Limite máximo de vértices atingido!\n");
    }
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(Grafo *grafo, int origem, int destino, int peso) {
    if (origem >= 0 && origem < grafo->numVertices && destino >= 0 && destino < grafo->numVertices) {
        grafo->matrizAdj[origem][destino] = peso;
    } else {
        printf("Vértices de origem ou destino inválidos!\n");
    }
}

// Função para verificar a existência de ciclos usando busca em profundidade (DFS)
bool verificarCicloRecursivo(Grafo *grafo, int vertice, bool visitados[], bool pilhaRecursao[]) {
    if (!visitados[vertice]) {
        visitados[vertice] = true;
        pilhaRecursao[vertice] = true;

        for (int i = 0; i < grafo->numVertices; i++) {
            if (grafo->matrizAdj[vertice][i] != 0) {
                if (!visitados[i] && verificarCicloRecursivo(grafo, i, visitados, pilhaRecursao)) {
                    return true;
                } else if (pilhaRecursao[i]) {
                    return true;
                }
            }
        }
    }
    pilhaRecursao[vertice] = false;
    return false;
}

// Função para verificar a existência de ciclos no grafo
bool verificarCiclos(Grafo *grafo) {
    bool visitados[MAX_VERTICES] = {false};
    bool pilhaRecursao[MAX_VERTICES] = {false};

    for (int i = 0; i < grafo->numVertices; i++) {
        if (verificarCicloRecursivo(grafo, i, visitados, pilhaRecursao)) {
            return true;
        }
    }
    return false;
}

// Função para calcular o grau de entrada de um nó
int calcularGrauEntrada(Grafo *grafo, int vertice) {
    int grau = 0;
    for (int i = 0; i < grafo->numVertices; i++) {
        if (grafo->matrizAdj[i][vertice] != 0) {
            grau++;
        }
    }
    return grau;
}

// Função para calcular o grau de saída de um nó
int calcularGrauSaida(Grafo *grafo, int vertice) {
    int grau = 0;
    for (int i = 0; i < grafo->numVertices; i++) {
        if (grafo->matrizAdj[vertice][i] != 0) {
            grau++;
        }
    }
    return grau;
}

int main() {
    Grafo grafo;
    inicializarGrafo(&grafo);

    // Adicione vértices e arestas ao seu grafo conforme necessário
    adicionarVertice(&grafo, 'A');
    adicionarVertice(&grafo, 'B');
    adicionarVertice(&grafo, 'C');
    adicionarAresta(&grafo, 0, 1, 1); // A -> B com peso 1
    adicionarAresta(&grafo, 1, 2, 2); // B -> C com peso 2
    adicionarAresta(&grafo, 2, 0, 3); // C -> A com peso 3

    // Exemplo de cálculo do comprimento do caminho entre duas cidades (vértices)
    int cidadeOrigem = 0; // A
    int cidadeDestino = 2; // C
    int comprimentoCaminho = grafo.matrizAdj[cidadeOrigem][cidadeDestino];
    printf("Comprimento do caminho de %c para %c: %d\n", grafo.rLabels[cidadeOrigem], grafo.rLabels[cidadeDestino], comprimentoCaminho);

    // Verificar a existência de ciclos no grafo
    if (verificarCiclos(&grafo)) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo não possui ciclos.\n");
    }

    // Calcular e exibir o grau de entrada e saída de cada nó
    for (int i = 0; i < grafo.numVertices; i++) {
        printf("Nó %c: Grau de Entrada = %d, Grau de Saída = %d\n", grafo.rLabels[i], calcularGrauEntrada(&grafo, i), calcularGrauSaida(&grafo, i));
    }

    return 0;
}