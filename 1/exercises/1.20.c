// Exercise 1-20. Write a program `detab` that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter? 

#include <stdio.h>

#define TABSTOP 8

int main(void) {
	int c, i, col = 0, count = 1;
	// count is [n]umber of characters to be [p]rinted; count = 1 for a character and count = more than 1 if spaces are to be printed
	// c is a variable that stores what is to be printed. sometimes it may as well be equal to what was input by the user. But confidently it is what will be printed; that's why you will see c = ' ' blank and a for loop will iterate it as many times as required to reach the next tab stop.

	while ((c = getchar()) != EOF) {
		count = 1; // c is equal to what is input by user and will be printed count = 1 times
		if (c == '\t') {
			count = TABSTOP - (col % TABSTOP);
			c = ' '; // c set to blank and count is the number of times it'll be printed
		}

		for (i = 0; i < count; ++i)
			putchar(c);

		if (c == '\n')
			col = 0;
		else
			col += count;
	}

	return 0;
}