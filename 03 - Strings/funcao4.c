// islower (char c) - Retorna 1 se 'c' for uma letra minúscula e 0 caso contrário.

#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'a';
    if (islower(c)) {
        printf("%c é uma letra minúscula.\n", c);
    } else {
        printf("%c não é uma letra minúscula.\n", c);
    }

    c = 'Z';
    if (islower(c)) {
        printf("%c é uma letra minúscula.\n", c);
    } else {
        printf("%c não é uma letra minúscula.\n", c);
    }

    return 0;
}