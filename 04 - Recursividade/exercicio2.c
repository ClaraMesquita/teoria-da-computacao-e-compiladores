/*
2) Crie uma função recursiva chamada somaNaturais que calcule a soma dos primeiros n
números naturais. O usuário deve fornecer o valor de n. Exemplo: se o usuário fornecer o
valor n = 5, a função deve calcular e retornar a soma dos números de 1 a 5 (ou seja: 1 + 2 +
3 + 4 + 5 = 15).
*/

#include <stdio.h>

int somaNaturais(int n) {
    // Caso base: quando n é igual a 1, retornamos 1.
    if (n == 1) {
        return 1;
    } else {
        // Caso recursivo: somamos n com a soma dos primeiros n-1 números naturais.
        return n + somaNaturais(n - 1);
    }
}

int main() {
    int n;
    
    printf("Digite um valor para n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("O valor de n deve ser maior que zero.\n");
    } else {
        int resultado = somaNaturais(n);
        printf("A soma dos primeiros %d números naturais é: %d\n", n, resultado);
    }
    
    return 0;
}