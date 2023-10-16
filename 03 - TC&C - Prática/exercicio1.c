#include <stdio.h>

void non_recursively(int rep);
void recursively(int rep);

int main(int argc, char const *argv[])
{
    int rep;

    printf("Informe o numero de repeticoes ");
    scanf("%i", &rep);

    printf("\nImpressao com chamada nao recursiva\n");
    non_recursively(rep);

    printf("\n\nImpressao com chamada recursiva\n");
    recursively(rep);

    return 0;
}

void non_recursively(int rep)
{
    int conj;

    for (size_t i = 0; i <= rep; i++)
    {
        if (i % 2 == 0)
        {
            conj = (i / 2) * -1;
        }
        else
        {
            conj = (i / 2) + 1;
        }
        printf("[%i, %i], ", i, conj);
    }
}

void recursively(int rep)
{
    int conj;

    if (rep == 0)
    {
        conj = (rep / 2) * -1;
        printf("[%i, %i], ", rep, conj);
    }
    else if (rep % 2 == 0)
    {
        conj = (rep / 2) * -1;
        recursively(rep - 1);
        printf("[%i, %i], ", rep, conj);
    }
    else
    {
        conj = (rep / 2) + 1;
        recursively(rep - 1);
        printf("[%i, %i], ", rep, conj);
    }
}