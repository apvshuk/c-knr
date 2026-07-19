// // Exercise 1-22. Write a program to `fold` long input lines into two or more shorter lines after
// // the last non-blank character that occurs before the n-th column of input. Make sure your
// // program does something intelligent with very long lines, and if there are no blanks or tabs
// // before the specified column.

// #include <stdio.h>

// #define MAXCOL 40

// int main(void) {
// 	int c, i, col = 0, n = 0;
// 	char buffer[MAXCOL];

// 	while ((c = getchar()) != EOF) {
// 		++col;

// 		if (c == ' ') {
// 			putchar(c);
// 			if (col == MAXCOL) {
// 				putchar('\n'), col = 0;
// 			}
// 			if ((MAXCOL - col) < n) {
// 				for (i = 0; i < n; ++i)
// 					putchar(buffer[i]);
// 				n = 0;
// 			}
// 		}
// 		else {
// 			if (col <= MAXCOL) {
// 				buffer[n] = c;
// 				++n;
// 			} else
// 				n = 0, putchar('\n'), col = 0;
// 		}
// 	}

// 	return 0;
// }

#include <stdio.h>

#define MAXCOL 40

int main(void) {
    int c, i, col, n;
    char buf[MAXCOL];

    col = 0;
    n = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            for (i = 0; i < n; ++i)
                putchar(buf[i]);
            putchar('\n');
            col = 0;
            n = 0;
        } else if (c == ' ' || c == '\t') {
            if (n == 0)
                continue;                   /* skip multiple spaces */
            if (col + 1 + n > MAXCOL) {    /* word doesn't fit — fold */
                putchar('\n');
                for (i = 0; i < n; ++i)
                	putchar(buf[i]);
                col = n;
            } else {                        /* word fits — print space then word */
                if (col > 0) {
                    putchar(' ');
                    ++col;
                }
                for (i = 0; i < n; ++i)
                    putchar(buf[i]);
                col += n;
            }
            n = 0;
        } else {
            buf[n++] = c;
            if (n == MAXCOL) {             /* word longer than MAXCOL — hard cut */
                if (col > 0)
                    putchar('\n');
                for (i = 0; i < n; ++i)
                    putchar(buf[i]);
                putchar('\n');
                col = 0;
                n = 0;
            }
        }
    }
    if (n > 0) {                           /* flush remaining buffer at EOF */
        if (col + 1 + n > MAXCOL)
            putchar('\n');
        else if (col > 0)
            putchar(' ');
        for (i = 0; i < n; ++i)
            putchar(buf[i]);
        putchar('\n');
    }

    return 0;
}