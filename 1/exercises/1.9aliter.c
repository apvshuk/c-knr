// Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
	int c, state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (state == IN)
				putchar(' '), state = OUT;
		}
		else
			putchar(c), state = IN;
	}

	return 0;
}