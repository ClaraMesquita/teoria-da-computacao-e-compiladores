/*
Dada a expressão regular, crie o grafo que representa o AFD:
L(E) = a(a + b)* ∪ ba(a + b)* ∪ bba(a + b)*
Dica: tente ver a expressão regular como se fosse três partes distintas, assim conseguirá
identificar os elementos em comum.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura de transição do AFD
typedef struct Transicao {
    char simbolo;        // Símbolo da transição
    struct Estado* destino; // Próximo estado
} Transicao;

// Definição da estrutura de estado do AFD
typedef struct Estado {
    int id;               // Identificador do estado
    bool final;           // Indica se o estado é final
    Transicao* transicoes; // Lista de transições do estado
    int numTransicoes;    // Número de transições do estado
} Estado;

// Função para criar um novo estado
Estado* criarEstado(int id, bool final) {
    Estado* estado = (Estado*)malloc(sizeof(Estado));
    estado->id = id;
    estado->final = final;
    estado->transicoes = NULL;
    estado->numTransicoes = 0;
    return estado;
}

// Função para adicionar uma transição a partir de um estado de origem
void adicionarTransicao(Estado* origem, char simbolo, Estado* destino) {
    origem->transicoes = (Transicao*)realloc(origem->transicoes, (origem->numTransicoes + 1) * sizeof(Transicao));
    origem->transicoes[origem->numTransicoes].simbolo = simbolo;
    origem->transicoes[origem->numTransicoes].destino = destino;
    origem->numTransicoes++;
}

// Função para imprimir o grafo do AFD
void imprimirGrafo(Estado* inicial) {
    printf("Estados:\n");
    printf("Inicial: q%d\n", inicial->id);

    for (int i = 0; i < inicial->numTransicoes; i++) {
        printf("q%d ---%c---> q%d\n", inicial->id, inicial->transicoes[i].simbolo, inicial->transicoes[i].destino->id);
        imprimirGrafo(inicial->transicoes[i].destino);
    }
}

int main() {
    // Criando os estados para cada parte da expressão regular
    Estado* q0 = criarEstado(0, false); // estado inicial
    Estado* q1 = criarEstado(1, false);
    Estado* q2 = criarEstado(2, true);  // estado final

    Estado* q3 = criarEstado(3, false); // estado inicial
    Estado* q4 = criarEstado(4, false);
    Estado* q5 = criarEstado(5, true);  // estado final

    Estado* q6 = criarEstado(6, false); // estado inicial
    Estado* q7 = criarEstado(7, false);
    Estado* q8 = criarEstado(8, false);
    Estado* q9 = criarEstado(9, true);  // estado final

    // Adicionando transições para a primeira parte: a(a + b)*
    adicionarTransicao(q0, 'a', q1);
    adicionarTransicao(q1, 'a', q1);
    adicionarTransicao(q1, 'b', q1);
    adicionarTransicao(q1, '\0', q2); // Transição vazia para aceitar a primeira parte

    // Adicionando transições para a segunda parte: ba(a + b)*
    adicionarTransicao(q3, 'b', q4);
    adicionarTransicao(q4, 'a', q5);
    adicionarTransicao(q5, 'a', q5);
    adicionarTransicao(q5, 'b', q5);
    adicionarTransicao(q5, '\0', q2); // Transição vazia para aceitar a segunda parte

    // Adicionando transições para a terceira parte: bba(a + b)*
    adicionarTransicao(q6, 'b', q7);
    adicionarTransicao(q7, 'b', q8);
    adicionarTransicao(q8, 'a', q9);
    adicionarTransicao(q9, 'a', q9);
    adicionarTransicao(q9, 'b', q9);
    adicionarTransicao(q9, '\0', q2); // Transição vazia para aceitar a terceira parte

    // Imprimindo o grafo do AFD
    printf("Grafo do AFD:\n");
    imprimirGrafo(q0);

    // Liberando a memória alocada
    free(q0->transicoes);
    free(q1->transicoes);
    free(q2);
    free(q3->transicoes);
    free(q4->transicoes);
    free(q5);
    free(q6->transicoes);
    free(q7->transicoes);
    free(q8->transicoes);
    free(q9);

    return 0;
}
