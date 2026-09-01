// Exercise 1-19. Write a function reverse(s) that reverses the character string
// s. Use it to write a program that reverses its input a line at a time.

#include <stdio.h>
#define MAXLENGTH 10

// returns the number of characters in the input, not
// counting '\n' and '\0'
int get_line(char line[]);
void reverse(char line[], char reversed[], int len);

int main(void) {
    char line[MAXLENGTH], reversed[MAXLENGTH];
    int len = 0;

    while ((len = get_line(line)) > 0) {
        reverse(line, reversed, len);
        printf("%s\n", reversed);
    }

    return 0;
}

void reverse(char line[], char reversed[], int len) {
    int i = 0;
    while (len - i - 1 >= 0)
        reversed[len - i - 1] = line[i], ++i;
    reversed[len] = '\0';
}

int get_line(char line[]) {
    int c, i = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < MAXLENGTH - 1)
            line[i++] = c;
    }

    line[i] = '\0';
    return i; // letters only, no '\n' involved
}