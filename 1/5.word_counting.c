#include <stdio.h>

#define IN 1 // inside a word
#define OUT 0 // outside a word

int main(void) {
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl; // counts lines
		else
			++nc; // counts characters

		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw; // counts words
		}
	}

	printf("new lines: %d\nnew words: %d\nnew characters: %d", nl, nw, nc);

	return 0;
}