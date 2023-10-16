/* 
1) Escreva um algoritmo que possua uma função recursiva para cálculo de potência. O usuário
deve informar a base e o expoente a partir do teclado. A base e o expoente devem ser
números inteiros. Não utilize a biblioteca math.h ou qualquer outro recurso pronto.
*/

#include <stdio.h>

// Função recursiva para calcular potência
int calcularPotencia(int base, int expoente) {
    // Caso base: Se o expoente for igual a 0, o resultado é 1.
    if (expoente == 0) {
        return 1;
    }
    // Caso recursivo: Chama a função recursivamente para expoente - 1 e multiplica pela base.
    else {
        return base * calcularPotencia(base, expoente - 1);
    }
}

int main() {
    int base, expoente;

    // Solicita ao usuário que insira a base e o expoente
    printf("Digite a base (inteiro): ");
    scanf("%d", &base);
    printf("Digite o expoente (inteiro): ");
    scanf("%d", &expoente);

    // Verifica se o expoente é negativo
    if (expoente < 0) {
        printf("O expoente não pode ser negativo para este algoritmo.\n");
    } else {
        // Chama a função para calcular a potência e exibe o resultado
        int resultado = calcularPotencia(base, expoente);
        printf("%d elevado a %d é igual a %d\n", base, expoente, resultado);
    }

    return 0;
}
