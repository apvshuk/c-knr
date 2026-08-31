// Exercise 1-19. Write a function reverse(s) that reverses the character string
// s. Use it to write a program that reverses its input a line at a time.

#include <stdio.h>
#define MAXLENGTH 1000

int get_line(char line[]);
int reverse(char line[], char reversed[], int len);

int main(void) {
    char line[MAXLENGTH], reversed[MAXLENGTH];
    int len = 0;

    while ((len = get_line(line)) > 0) {
        if ((len = reverse(line, reversed, len)) > 0) {
            printf("%s", reversed);
        }
    }

    return 0;
}

int reverse(char line[], char reversed[], int len) {
    int i;
    int end = len;

    if (line[len - 1] == '\n')
        end = len - 1;

    for (i = 0; i < end; ++i)
        reversed[end - 1 - i] = line[i];

    if (end < len)
        reversed[end] = '\n';

    reversed[len] = '\0';

    return len;
}

int get_line(char line[]) {
    int c, i = 0;
    for (i = 0; (c = getchar()) != '\n' && c != EOF; ++i)
        if (i < MAXLENGTH - 1)
            line[i] = c;

    if (c == '\n') {
        if (i < MAXLENGTH - 1)
            line[i] = c, ++i;
    }

    line[i < MAXLENGTH - 1 ? i : MAXLENGTH - 1] = '\0';
    // marks end of the array; both reverse and printf need
    // termination marker with a null character '\0'

    return i;
}