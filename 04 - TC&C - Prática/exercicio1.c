/*
Em linguagem de programação C, escreva um algoritmo quê:

1) Leia uma string a partir de um arquivo no modo texto e:
a. Determine o tamanho (comprimento) da string de forma recursiva. Armazene o
tamanho da string no arquivo original.
b. Determine o reverso da string de forma recursiva. Armazene o reverso da string no arquivo original.
*/

#include <stdio.h>
#include <stdlib.h>
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
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê a string do arquivo
    fseek(arquivo, 0, SEEK_SET);
    char str[100];  // Tamanho máximo da string (ajuste conforme necessário)
    fscanf(arquivo, "%s", str);

    int tamanho = calcularTamanho(str);

    // Atualiza o tamanho no arquivo
    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d\n", tamanho);

    // Inverte a string
    inverterString(str, tamanho);

    // Atualiza o arquivo com a string invertida
    fprintf(arquivo, "%s", str);

    fclose(arquivo);

    printf("Tamanho da string: %d\n", tamanho);
    printf("Reverso da string: %s\n", str);

    return 0;
}
