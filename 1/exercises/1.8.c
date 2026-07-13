// Exercise 1-8. Write a program to count blanks, tabs, and newlines. 

#include <stdio.h>
int main(void) {
	int c, b, t, n;
	b = 0;
	t = 0;
	b = 0;

	while ((c = getchar()) != EOF)
		if (c == '\n')
			++n;
		else if (c == '\t')
			++t;
		else if (c == ' ') /* c == 32 can also be done for blank space */
			++b;

	printf("Lines: %d\nBlanks: %d\nTabs: %d\n", n, b, t);

	return 0;
}

