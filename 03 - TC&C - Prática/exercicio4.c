#include <stdio.h>

void mq(int i, int aux);

int main(int argc, char const *argv[])
{
    int lim;

    printf("Informe o valor de i  ");
    scanf("%i", &lim);

    for (size_t i = 0; i <= lim; i++)
    {
        for (size_t j = 0; j < i + 1; j++)
        {
            printf("[%i, %i] ", j, i + 1);
        }
    }
    
    return 0;
}
