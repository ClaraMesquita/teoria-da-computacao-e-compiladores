/* Receba o peso de uma pessoa, calcule e apresente o novo peso:

a. Se a pessoa engordar 15%.
b. Se a pessoa emagrecer 20%.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float peso;
    
    printf("Informe o peso da pessoa: ");
    scanf("%f", &peso);
    float novoPesoEngordar = peso * 1.15;  // Aumento de 15%
    float novoPesoEmagrecer = peso * 0.8;  // Redução de 20%
    printf("a. Novo peso ao engordar 15%%: %.2f\n", novoPesoEngordar);
    printf("b. Novo peso ao emagrecer 20%%: %.2f\n\n", novoPesoEmagrecer);

    return 0;
}