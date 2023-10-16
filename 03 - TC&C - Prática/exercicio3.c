#include <stdio.h>

void mq(int i, int aux);

int main(int argc, char const *argv[])
{
    int lim;

    printf("Informe o valor de i  ");
    scanf("%i", &lim);

    mq(lim, lim);
    return 0;
}

void mq(int i, int aux)
{
    if (i == 0)
    {
        printf("[%i, %i] ", aux, i + 1);
    }
    else if (aux == 0)
    {
        mq(i - 1, i - 1);
        printf("[%i, %i] ", aux, i + 1);
    }
    else
    {
        mq(i, aux - 1);
        printf("[%i, %i] ", aux, i + 1);
    }
}
