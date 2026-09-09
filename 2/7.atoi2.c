#include <stdio.h>

int main(void) {
    char c = 'c';

    if (c >= 'A' && c <= 'Z')
        c = c + 'a' - 'A';

    putchar(c);

    return 0;
}