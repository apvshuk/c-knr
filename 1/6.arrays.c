// from the book - Let is write a program to count the number of occurrences of each digit, of white space characters (blank, tab, newline), and of all other characters. This is artificial, but it permits us to illustrate several aspects of C in one program.

/* count digits, whitespaces (tabs, blanks, newlines), others */

#include <stdio.h>
int main(void) {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i <= 9; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    for (i = 0; i <= 9; ++i)
        printf("%d: %d\n", i, ndigit[i]);
    printf("white spaces: %d\nothers: %d\n", nwhite, nother);

    return 0;
}