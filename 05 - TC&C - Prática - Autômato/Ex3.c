/*
Crie um AFD que reconheça todas as palavras que tenham um
número par de 0’s, sabendo que o alfabeto desta linguagem é {0,1}.
*/

#include <stdio.h>

int main() {
    enum estados { q0, qf };
    enum estados estadoAtual = q0;

    char alfabeto[] = {'0', '1'};

    char entrada[100];
    printf("Digite a sequencia binaria (usando 0 e 1): ");
    scanf("%s", entrada);

    int countZeros = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == '0') {
            countZeros++;
        }
    }

    if (countZeros = 1 || countZeros > 1) {
        printf("A entrada possui um numero par de 0's. Aceito pelo AFD!\n");
    } else {
        printf("A entrada nao possui um numero par de 0's. Rejeitado pelo AFD!\n");
    }
    return 0;
}