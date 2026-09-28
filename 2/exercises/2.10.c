// Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if-else.

#include <stdio.h>

/////////// Original implementation using if-else conditionals
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

////////// Using conditional expression
int lower_(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : (c);
}

int main(void) {
    char c = 'A';
    printf("Lower case of %c is: %c\n", c, lower_(c));
    return 0;
}