// isdigit (char c) - Retorna 1 se 'c' for um dígito e 0 caso contrário.

#include <stdio.h>
#include <ctype.h>

int main() {
    char c = '5';
    if (isdigit(c)) {
        printf("%c é um dígito.\n", c);
    } else {
        printf("%c não é um dígito.\n", c);
    }

    c = 'A';
    if (isdigit(c)) {
        printf("%c é um dígito.\n", c);
    } else {
        printf("%c não é um dígito.\n", c);
    }

    return 0;
}