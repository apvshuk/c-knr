// Exercise 1-16. Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrary long input lines, and as much as
// possible of the text.

#include <stdio.h>
#define MAXLENGTH 1000

int get_line(char current[]);
void copy(char to[], char from[]);

int main(void) {
    char current[MAXLENGTH], longest[MAXLENGTH];
    int len, max = 0;

    while ((len = get_line(current)) > 0) {
        if (len > max)
            copy(longest, current), max = len;
    }

    if (max > 0)
        printf("%s\nlength: %d\n", longest, max);

    return 0;
}

int get_line(char current[]) {
    int i, c = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < MAXLENGTH - 1)
            current[i] = c;
    }
    if (c == '\n') {
        if (i < MAXLENGTH - 1)
            current[i] = c;
        ++i;
    }
    current[i < MAXLENGTH - 1 ? i : MAXLENGTH - 1] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}