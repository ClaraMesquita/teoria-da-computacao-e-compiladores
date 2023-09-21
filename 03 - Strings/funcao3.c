// isupper (char c) - Retorna 1 se 'c' for uma letra maiúscula e 0 caso contrário.

#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'C';
    if (isupper(c)) {
        printf("%c é uma letra maiúscula.\n", c);
    } else {
        printf("%c não é uma letra maiúscula.\n", c);
    }

    c = 'd';
    if (isupper(c)) {
        printf("%c é uma letra maiúscula.\n", c);
    } else {
        printf("%c não é uma letra maiúscula.\n", c);
    }

    return 0;
}