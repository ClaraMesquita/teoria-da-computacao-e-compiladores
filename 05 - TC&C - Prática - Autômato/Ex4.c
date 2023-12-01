/*
Dada a expressão regular, crie o grafo que representa o AFD:
L(E) = a(a + b)* ∪ ba(a + b)* ∪ bba(a + b)*
Dica: tente ver a expressão regular como se fosse três partes distintas, assim conseguirá
identificar os elementos em comum.
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    enum estados { q0, q1, q2, q3, qf };
    enum estados estadoAtual = q0;

    char alfabeto[] = {'a', 'b'};

    char entrada[100];
    printf("Digite a sequencia de entrada (usando 'a' e 'b'): ");
    scanf("%s", entrada);

    for (int i = 0; entrada[i] != '\0'; i++) {
        char simbolo = entrada[i];

        switch (estadoAtual) {
            case q0:
                if (simbolo == 'a') {
                    estadoAtual = q1;
                } else {
                    estadoAtual = qf;
                }
                break;

            case q1:
                if (simbolo == 'a' || simbolo == 'b') {
                    estadoAtual = q2;
                } else {
                    estadoAtual = qf;
                }
                break;

            case q2:
                if (simbolo == 'a') {
                    estadoAtual = q3;
                } else if (simbolo == 'b') {
                    estadoAtual = qf;  
                } else {
                    estadoAtual = qf;
                }
                break;

            case q3:
                if (simbolo == 'a' || simbolo == 'b') {
                } else {
                    estadoAtual = qf;
                }
                break;

            case qf:
                break;
        }
    }

    if (estadoAtual == q1 || estadoAtual == q2 || estadoAtual == q3 || estadoAtual == qf) {
        printf("A entrada foi aceita pelo AFD!\n");
    } else {
        printf("A entrada foi rejeitada pelo AFD!\n");
    }

    return 0;
}