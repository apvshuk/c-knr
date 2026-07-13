// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal;
// TODO: a vertical orientation is more challenging.

#include <stdio.h>

#define MAXLEN 20
#define IN 1
#define OUT 0

int main(void) {
	int c, i, j, state = OUT, temp = 0, count[MAXLEN + 1]; // index 0 unused, 1-20 for word lengths, 20 = "20 or more"

	for (i = 0; i <= MAXLEN; ++i)
		count[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				++count[temp];
				temp = 0;
			}
		}
		else {
			if (temp < 20) // length more than 20 will be counted in category-20, so count of the current word is not increased if more than 20.
				++temp;
			if (state == OUT)
				state = IN;
		}
	}

	for (i = 1; i <= MAXLEN; ++i) {
		// to make the histogram aligned
		if (i == 20)
			printf("%d+: ", i);
		else
			if (i < 10)
				printf("%d  : ", i);
			else
				printf("%d : ", i);

		for (j = 0; j < count[i]; ++j)
			printf("*");
		printf("\n");
	}

	return 0;
}