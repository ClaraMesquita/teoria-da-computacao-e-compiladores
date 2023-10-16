#include <stdio.h>

// Função sucessor
int sucessor(int n) {
    return n + 1;
}

// Função de soma
int soma(int m, int n) {
    // Base: se n = 0, então m + n = m
    if (n == 0) {
        return m;
    } else {
        // Passo recursivo: m + s(n) = s(m + n)
        return soma(sucessor(m), n - 1);
    }
}

int main() {
    int num1, num2;

    printf("Informe o primeiro número: ");
    scanf("%d", &num1);

    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    int resultado = soma(num1, num2);

    printf("O resultado da soma é: %d\n", resultado);

    return 0;
}
