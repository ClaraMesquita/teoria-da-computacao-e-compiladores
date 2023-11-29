/*
Crie um AFD para reconhecer a linguagem representada pela
expressão regular 0*110*, sabendo que o alfabeto desta linguagem é
{0,1}.
*/ 

#include <stdio.h>
#include <stdbool.h>

bool aceitaString(char *str) {
    
    int estadoAtual = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (estadoAtual == 0 && str[i] == '0') {
            estadoAtual = 0;
        } else if (estadoAtual == 0 && str[i] == '1') {
            estadoAtual = 1;
        } else if (estadoAtual == 1 && str[i] == '1') {
            estadoAtual = 2;
        } else if (estadoAtual == 2 && str[i] == '0') {
            estadoAtual = 2;
        } else {
            return false;
        }
        i++;
    }
    return estadoAtual == 2;
}

int main() {
    char str[100];
    
    // Solicita que o usuário insira o número
    printf("Digite um numero: ");
    scanf("%s", str);

    // Verifica se a string é aceita pelo AFD
    printf("%s\n", aceitaString(str) ? "Aceita" : "Rejeita");
    
    return 0;
}