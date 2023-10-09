/*Calcule e apresente a área de um losango. As diagonais maior e menor do losango
devem ser informadas pelo usuário. OBS: AREA = (DIAGONAL MAIOR * DIAGONAL
MENOR) / 2.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float diagonalMaior, diagonalMenor, areaLosango;

    printf("Informe a diagonal maior do losango: ");
    scanf("%f", &diagonalMaior);

    printf("Informe a diagonal menor do losango: ");
    scanf("%f", &diagonalMenor);

    areaLosango = (diagonalMaior * diagonalMenor) / 2;
    printf("Área do losango: %.2f\n\n", areaLosango);

    return 0;
}