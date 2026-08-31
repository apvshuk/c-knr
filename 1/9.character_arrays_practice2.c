// code to print at the end of the program the longest line

#include <stdio.h>
#define MAXLENGTH 1000

int get_line(char current[]);
void copy(char to[], char from[]);

int main(void) {
    char current[MAXLENGTH],
        longest[MAXLENGTH]; // current line and longest so far
    int len, max = 0;       // current length and maximum so far

    while ((len = get_line(current)) > 0)
        if (len > max)
            copy(longest, current), max = len;
    if (max > 0)
        printf("%s", longest);
    if (len == 0)
        printf("write something boss");

    return 0;
}

int get_line(char current[]) {
    int i, c = 0;
    for (i = 0; i < MAXLENGTH - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        current[i] = c;

    if (c == '\n')
        current[i] = c, ++i;
    current[i] = '\0'; // end of array

    return i; // returns the length of the newest input line
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}