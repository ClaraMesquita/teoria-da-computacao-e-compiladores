/*Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
Imprima este valor em reais.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    
    float cotacaoDolar, valorDolar;

    printf("Informe a cotação do dólar: ");
    scanf("%f", &cotacaoDolar);

    printf("Informe o valor em dólares: ");
    scanf("%f", &valorDolar);


    float valorReais = cotacaoDolar * valorDolar;
    printf("Valor em reais: %.2f\n\n", valorReais);


    return 0;
}