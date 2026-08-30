// // Exercise 1-22. Write a program to `fold` long input lines into two or more shorter lines after
// // the last non-blank character that occurs before the n-th column of input. Make sure your
// // program does something intelligent with very long lines, and if there are no blanks or tabs
// // before the specified column.

#include <stdio.h>

#define MAXCOL 50

int main(void) {
    int i, c, n, col;
    char buff[MAXCOL];
    // difference between n and col - although col resets at newline, it is different from n as n resets at every space, i.e end of word; also n can be greater than MAXCOL, as words can have more characters than MAXCOL, but col will reset as soon as a new line starts which does when col reaches MAXCOL

    n = col = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            // flush buff for the last word, which never gets flushed if trailing characer is not blank
            for (i = 0; i < n; ++i)
                putchar(buff[i]);
            col = n = 0;
            putchar('\n'); // next input in a newline
        } else {
            ++col;
            if (c == ' ' || c == '\t') {
                if (n > (MAXCOL - col)) {
                    putchar('\n'), col = 0;
                }
                for (i = 0; i < n; ++i)
                    putchar(buff[i]);
                col += n;

                n = 0; // word ended, so reset word length tracker, which is n
                putchar(' ');
            } else {
                if (n == MAXCOL && col == 0) {
                    for (i = 0; i < MAXCOL; ++i) // i < MAXCOL, not i < n
                        putchar(buff[i]);
                    putchar('\n');
                    col = 0;
                    n = 0;
                }
                buff[n] = c;
                ++n;
            }
        }
    }

    return 0;
}