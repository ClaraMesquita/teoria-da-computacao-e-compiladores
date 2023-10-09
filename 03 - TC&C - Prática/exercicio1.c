
int calcularResultado(int n) {
    if (n % 2 == 0) {
        return -n / 2;
    } else {
        return n / 2 + 1;
    }
}

void imprimirResultadosRecursivo(int atual, int limite) {
    if (atual <= limite) {
        printf("[%d, %d], ", atual, calcularResultado(atual));
        imprimirResultadosRecursivo(atual + 1, limite);
    }
}

int main() {
    int limite;
    printf("Informe o limite:");
    scanf("%d", &limite);

    printf("\n");
    printf("Recursiva:");
    printf("\n");
    imprimirResultadosRecursivo(0, limite);

    printf("\n");
    printf("Não recursiva:");
    printf("\n");

    for (int n = 0; n <= limite; n++) {
        int resultado;

        if (n % 2 == 0) {
            resultado = -n / 2;
        } else {
            resultado = n / 2 + 1;
        }

        printf("[%d, %d], ", n, resultado);
    }

    return 0;
}
