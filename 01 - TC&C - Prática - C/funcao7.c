/* Receba o valor do salário mínimo e o valor do salário de um funcionário. O algoritmo
deve calcular e apresentar a quantidade de salários mínimos que esse funcionário
recebe.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float salario;
    float salarioMinimo;
    printf("Salário mínimo: ");
    scanf("%f %f", &salarioMinimo);
    printf("Salário do funcionário: ");
    scanf("%f %f",&salario);
    float qtdSalariosMinimos = salario / salarioMinimo;
    printf("Quantidade de salários mínimos recebidos: %.2f\n\n", qtdSalariosMinimos);

    return 0;
}