// Exercise 1-21. Write a program `entab` that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
// When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#include <stdio.h>

#define TABSTOP 8

int main(void) {
	int c, i, blanks = 0, col = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++col;
			++blanks;
			if ((col % TABSTOP) == 0)
				putchar('\t'), blanks = 0;
		} else {
			for (i = 0; i < blanks; ++i)
				putchar(' ');
			blanks = 0;
			putchar(c);
			if (c == '\n')
				col = 0;
			else
				++col;
		}
	}

	return 0;
}