// Receba três notas, calcule e apresente a média aritmética delas.

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float nota1, nota2, nota3;

    printf("Informe três notas: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    float media = (nota1 + nota2 + nota3) / 3;
    printf("Média aritmética: %.2f\n\n", media);


    return 0;
}