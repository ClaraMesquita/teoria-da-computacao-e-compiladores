/* Receba uma temperatura em Celsius, calcule e mostre essa temperatura em Fahrenheit.
OBS: F = (C * 1,8) + 32.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float tempCelsius;
    printf("Celsius: ");
    scanf("%f", &tempCelsius);
    float tempFahrenheit = (tempCelsius * 1.8) + 32;
    printf("Fahrenheit: %.2f\n\n", tempFahrenheit);
    

    return 0;
}