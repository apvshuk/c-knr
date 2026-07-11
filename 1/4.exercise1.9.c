// Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

#include <stdio.h>

int main(void) {
	int c, lc;
	lc = 0; // why initialized to zero - Uninitialized variables containing garbage that happens to be 32 (space) is a real class of bug; which will cause eating of the first character. '\0' null character — no text input can match it, safe initial state

	// c - character; lc - last PRINTED character;

	while ((c = getchar()) != EOF) {
		if (!(lc == ' ' && c == ' ')) {
			putchar(c);
			lc = c;
		}

		
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