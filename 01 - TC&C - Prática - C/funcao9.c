/* Receba os valores dos dois catetos de um triângulo, calcule e apresente o valor da
hipotenusa. OBS - Teorema de Pitágoras: a2 = b2 + c2*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
 float cateto1, cateto2;
    printf("Informe os valores dos catetos do triângulo: ");
    scanf("%f %f", &cateto1, &cateto2);
    float hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
    printf("Valor da hipotenusa: %.2f\n\n", hipotenusa);

    return 0;
}