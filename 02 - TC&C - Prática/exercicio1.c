#include <stdio.h>
/**
 * Programa que cria um arquivo
 * Recebe duas sequencias de inteiro positvo
 * Imprime no arquivo as sequencias
*/
// Função para ler e armazenar sequência em um arquivo
void lerEArmazenarSequencia(char *nomeArquivo) {
    FILE *arquivo;
    int numero;

    //abre o arquivo no modo escrita
    arquivo = fopen(nomeArquivo, "w");

    if(arquivo==NULL) {
        printf("Erro ao abrir arquivo. \n");
        return;
    }

    printf("Digite a primeira sequência de números naturais (digite um número negativo para encerrar):\n");

    while(1) {
        scanf("%d", &numero);

        if (numero < 0) 
            break;

        fprintf(arquivo, "%d", numero);

    }
    
    // Adiciona uma quebra de linha no arquivo
    fprintf(arquivo, "\n");


    printf("\nDigite a segunda sequência de números naturais (digite um número negativo para encerrar):\n");

        while(1) {
        scanf("%d", &numero);

        if (numero < 0) 
            break;

        fprintf(arquivo, "%d", numero);

    }

    printf("\n");

    //fecha arquivo
    fclose(arquivo);

}
int main() {
    // Nome do arquivo para armazenar as sequências
    char nomeArquivo[] = "sequencias.txt";

    // Chama a função para ler e armazenar as sequências
    lerEArmazenarSequencia(nomeArquivo);

    return 0;
}
