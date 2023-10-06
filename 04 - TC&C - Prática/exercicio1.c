/*
Em linguagem de programação C, escreva um algoritmo quê:

1) Leia uma string a partir de um arquivo no modo texto e:
a. Determine o tamanho (comprimento) da string de forma recursiva. Armazene o
tamanho da string no arquivo original.
b. Determine o reverso da string de forma recursiva. Armazene o reverso da string no
arquivo original.
*/

#include <stdio.h>
#include <string.h>

int calcularTamanho(char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + calcularTamanho(str + 1);
    }
}

void inverterString(char *str, int tamanho) {
    if (tamanho <= 1) {
        return;
    } else {
        char temp = str[0];
        str[0] = str[tamanho - 1];
        str[tamanho - 1] = temp;
        inverterString(str + 1, tamanho - 2);
    }
}

int main() {
    FILE *arquivo = fopen("arquivo.txt", "r+");

    int tamanho = calcularTamanho(str);

    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d\n", tamanho);

    inverterString(str, tamanho);

    fprintf(arquivo, "%s", str);

    fclose(arquivo);

    printf("Tamanho da string: %d\n", tamanho);
    printf("Reverso da string: %s\n", str);

    return 0;
}