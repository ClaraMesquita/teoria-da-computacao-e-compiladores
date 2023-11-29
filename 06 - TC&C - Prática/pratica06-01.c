#include <stdio.h>
#include <stdbool.h>

#define NUM_ESTADOS 9

// Função de transição
int transicao(int estadoAtual, char simbolo) {
    switch (estadoAtual) {
    // Estado Vaio = -1
        case 125:
            return (simbolo == 'A') ? 68 : ((simbolo == 'B') ? 468 : 0);
        case 468:
            return (simbolo == 'A') ? 78 : ((simbolo == 'B') ? 78 : 0);
        case 78:
            return (simbolo == 'A') ? 368 : ((simbolo == 'B') ? -1 : 0);
        case 678:
            return (simbolo == 'A') ? 368 : ((simbolo == 'B') ? 78 : 0);
        case 368:
            return (simbolo == 'A') ? 245 : ((simbolo == 'B') ? 78 : 0);
        case 245:
            return (simbolo == 'A') ? 678 : ((simbolo == 'B') ? 68 : 0);
        case 4:
            return (simbolo == 'A') ? 78 : ((simbolo == 'B') ? -1 : 0);
        case -1:
            return (simbolo == 'A') ? -1 : ((simbolo == 'B') ? -1 : 0);
        case 68:
            return (simbolo == 'A') ? -1 : ((simbolo == 'B') ? 78 : 0);
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

    return 0;
}
