#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int lim);
void copy(char from[], char to[]);

int main(void) {
    int len, max; // length of current line, maximum length seen so far
    char line[MAXLINE], longest[MAXLINE]; // current line, longest line seen so far
    max = 0;

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max)
            max = len, copy(line, longest);
    }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

int get_line(char given_line[], int limit) {
    int i, c;
    c = 0;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        given_line[i] = c;

    if (c == '\n')
        given_line[i] = c, ++i;
    given_line[i] = '\0'; // null character

    // (i < limit - 1), why not (i <= limit - 1) in the for loop, after all, the length of the array is 1000 (0 - 999). It is becayse - We need to restrict input leaving one space at the end of the array so that we can add a null character '\0' which is standard ending of an array. If input is taken to the last index of the array, we can no more add the null character '\0'; what happens then, I must find out.

    return i;
}

void copy(char from[], char to[]) {
    int i = 0;

    // remember that assignment returns the value of from[i], meaning the variable assigning to one getting assigned. This is critical, because otherwise had the value of to[i] been returned, the while loop would have ended as and when the smaller array ends, which is undesirable, for we need the bigger array to decide when to end the loop, so that no input character is missed. So, that assignment will return a null character '\0' at the end of the from[i] array; that's how we know when the array ends, by '\0'.
    while ((to[i] = from[i]) != '\0')
        ++i;
}