/*Faça um programa que receba o salário de um funcionário, calcule e mostre o novo
salário, sabendo-se que ele teve um aumento de 25%.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float salario;

    printf("Informe o salário do funcionário: ");
    scanf("%f", &salario);

    float novoSalario = salario * 1.25;  // Aumento de 25%
    printf("Novo salário: %.2f\n\n", novoSalario);

    return 0;
}