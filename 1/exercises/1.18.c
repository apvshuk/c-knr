// Exercise 1-18. Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.

#include <stdio.h>
#define MAXLENGTH 1000

int get_line(char line[]);
int clean(char line[], int len);

int main(void) {
    char line[MAXLENGTH];
    int len = 0;

    while ((len = get_line(line)) > 0) {
        ;
        if ((len = clean(line, len)) > 0) {
            printf("%s", line);
        }
    }
    return 0;
}

int get_line(char line[]) {
    int i, c = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < MAXLENGTH - 1)
            line[i] = c;
    }
    if (c == '\n') {
        if (i < MAXLENGTH - 1)
            line[i] = c, ++i;
    }

    line[i < MAXLENGTH - 1 ? i : MAXLENGTH - 1] = '\0';

    return i;
}

int clean(char line[], int len) {
    int i;
    for (i = len - 1; i >= 0; --i) {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
            line[i] = '\0';
        else
            break;
    }

    return i + 1;
}