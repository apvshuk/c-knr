// Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input

#include <stdio.h>


int main(void) {
	int i, j, c, chr[95];
	for (i = 0; i <= 94; i++)
		chr[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 32 && c <= 126)
        	chr[c - 32]++;
	}

	for (i = 0; i <= 94; ++i) {
		if (chr[i] != 0) {
		    printf("%c: ", i + 32);
		    for (j = 0; j < chr[i]; ++j)
		        printf("*");
		    printf("\n");
		}
	}

	return 0;
}