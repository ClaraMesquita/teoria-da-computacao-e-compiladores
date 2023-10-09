/* Receba o ano de nascimento de uma pessoa, o ano atual e imprima:

a. A idade da pessoa no ano atual.
b. A idade que a pessoa terá em 2050.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    int anoNascimento, anoAtual;

    printf("Informe o ano de nascimento: ");
    scanf("%d", &anoNascimento);

    printf("Informe o ano atual: ");
    scanf("%d", &anoAtual);

    int idadeAtual = anoAtual - anoNascimento;
    int idade2050 = 2050 - anoNascimento;

    printf("Idade atual: %d anos\n", idadeAtual);
    printf("Idade em 2050: %d anos\n\n", idade2050);


    return 0;
}