/*
Crie um AFD que reconheça a linguagem L = {w | w tem um número
par de 0’s e 1’s}, sabendo que o alfabeto Σ = {0, 1} e que o AFD
aceitará uma palavra vazia.
*/

#include <stdio.h>
#include <stdbool.h>

#define NUM_ESTADOS 4

// Função de transição
int transicao(int estadoAtual, char simbolo) {
    switch (estadoAtual) {
        case 0:
            return (simbolo == '0') ? 1 : ((simbolo == '1') ? 3 : 0);
        case 1:
            return (simbolo == '0') ? 0 : ((simbolo == '1') ? 2 : 0);
        case 2:
            return (simbolo == '0') ? 3 : ((simbolo == '1') ? 1 : 0);
        case 3:
            return (simbolo == '0') ? 2 : ((simbolo == '1') ? 0 : 0);
        default:
            return 0;
    }
}

// Função principal para verificar se uma palavra é aceita pelo AFD
bool aceitaPalavra(char *palavra) {
    int estadoAtual = 0;

    while (*palavra != '\0') {
        estadoAtual = transicao(estadoAtual, *palavra);
        palavra++;
    }

    // Verificar se o estado final é um estado de aceitação
    return (estadoAtual == 0);
}

int main() {
    char palavra[100];

    printf("Digite a palavra a ser verificada: ");
    scanf("%s", palavra);

    if (aceitaPalavra(palavra)) {
        printf("A palavra foi ACEITA pelo AFD.\n");
    } else {
        printf("A palavra foi REJEITADA pelo AFD.\n");
    }

    return 0;
}