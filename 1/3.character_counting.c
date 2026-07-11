#include <stdio.h>

// version 1
// int main(void) {
// 	long nc;
// 	int c;

// 	nc = 0;

// 	while (getchar() != EOF)
// 		++nc; // nc = nc + 1; or nc += 1;
// 	printf("%ld\n", nc);

// 	return 0;
// }

// version 2
int main(void) {
	double nc;

	for (nc = 0; getchar() != EOF; ++nc);
	printf("%.0f\n", nc);
}