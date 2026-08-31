// Exercise 1-17. Write a program to print all input lines that are longer than
// 80 characters.

#include <stdio.h>
#define MAXLENGTH 1000
#define THRESHOLD 80

int get_line(char line[]);

int main(void) {
    int len = 0;
    char line[MAXLENGTH];
    while ((len = get_line(line)) > 0) {
        if (len > THRESHOLD)
            printf("%s", line);
    }

    return 0;
}

int get_line(char line[]) {
    int i = 0, c = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < MAXLENGTH - 1)
            line[i] = c;
    }
    if (c == '\n') {
        if (i < MAXLENGTH - 1)
            line[i] = c;
        ++i;
    }
    line[i < MAXLENGTH - 1 ? i : MAXLENGTH - 1] = '\0';

    return i;
}