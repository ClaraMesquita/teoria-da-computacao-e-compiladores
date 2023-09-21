// isalnum (char c) - Retorna 1 se 'c' for uma letra ou um dígito e 0 caso contrário.

#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'B';
    if (isalnum(c)) {
        printf("%c é uma letra ou um dígito.\n", c);
    } else {
        printf("%c não é uma letra ou um dígito.\n", c);
    }

    c = '@';
    if (isalnum(c)) {
        printf("%c é uma letra ou um dígito.\n", c);
    } else {
        printf("%c não é uma letra ou um dígito.\n", c);
    }

    return 0;
}