// Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

// this solution addresses slightly more than the problem: The first space or bunch of spaces even before the first word starts, is or are not printed in the output.

#include <stdio.h>

int main(void) {
	int c, lc;
	lc = ' ';
	// c - character; lc - last PRINTED character;

	while ((c = getchar()) != EOF) {
		if (!(lc == ' ' && c == ' ')) {
			putchar(c);
			lc = c;
		}
		if (c == '\n')
			lc = ' ';
	}

	return 0;
}


// De Morgans' Theorem equivalent
// if (lc != ' ' || c != ' ') {
// 	putchar(c);
// 	lc = c;
// }


// A redundant method: lc = c is moved outside
// while ((c = getchar()) != EOF) {
//     if (!(lc == ' ' && c == ' ')) {
//         putchar(c);
//     }
//     lc = c;
// }
// EARLIER when the program skips (both spaces), lc is not updated — it stays ' '. That's correct behavior; it was last printed character that lc stored. HERE even if the condition is not satisfied, meaning lc is already ' ' , still lc updates again to ' ' which is redundant, but not wrong.