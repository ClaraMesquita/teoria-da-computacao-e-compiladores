/* 10) Receba o raio, calcule e apresente:

a. O comprimento de uma esfera: C = 2 * π * R.
b. A área de uma esfera: A = π * R2
c. O volume de uma esfera: V = 3⁄4 * π * R3
.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float raio;
    printf("Informe o raio da esfera: ");
    scanf("%f", &raio);

    float comprimentoEsfera = 2 * 3.14159 * raio;
    float areaEsfera = 3.14159 * raio * raio;
    float volumeEsfera = (3.0 / 4.0) * 3.14159 * raio * raio * raio;
    printf("a. Comprimento da esfera: %.2f\n", comprimentoEsfera);
    printf("b. Área da esfera: %.2f\n", areaEsfera);
    printf("c. Volume da esfera: %.2f\n\n", volumeEsfera);

    return 0;
}