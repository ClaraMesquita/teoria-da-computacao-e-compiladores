#include <stdio.h>

int sum_rec(int num1, int num2);

int main(int argc, char const *argv[])
{
    int num1, num2, sum;

    printf("Informe os numeros a serem somados ");
    scanf("%i", &num1);
    scanf("%i", &num2);
    sum = sum_rec(num1, num2);
    printf("\nValor da some = %i", sum);

    return 0;
}

int sum_rec(int num1, int num2)
{
    if (num1 == 0 && num2 == 0)
    {
        return 0;
    }
    else if (num2 == 0)
    {
        if (num1 > 0)
        {
            return 1 + sum_rec(num1 - 1, num2);
        }
        else
        {
            return -1 + sum_rec(num1 + 1, num2);
        }
    }
    else
    {
        if (num2 > 0)
        {
            return 1 + sum_rec(num1, num2 - 1);
        }
        else
        {
            return -1 + sum_rec(num1, num2 + 1);
        }
    }
}
