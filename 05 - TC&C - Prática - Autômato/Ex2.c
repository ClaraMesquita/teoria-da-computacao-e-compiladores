/*
Para o alfabeto {a, b}, crie um AFD que reconheça todas as palavras
que não possuem dois a’s consecutivos.
*/

#include <stdio.h>
#include <stdbool.h>

bool aceitaString(char *str) {
    enum Estados { q0, q1, q2 };
    int estadoAtual = q0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (estadoAtual == q0 && str[i] == 'a') {
            estadoAtual = q1;
        } else if (estadoAtual == q0 && str[i] == 'b') {
            estadoAtual = q0;
        } else if (estadoAtual == q1 && str[i] == 'a') {
            estadoAtual = q2; // Dois 'a's consecutivos, estado de rejeição
        } else if (estadoAtual == q1 && str[i] == 'b') {
            estadoAtual = q0;
        } else if (estadoAtual == q2) {
            break;
        }
    }
    return estadoAtual != q2;
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);
    printf("%s\n", aceitaString(str) ? "Aceita" : "Rejeita");
    return 0;
}
