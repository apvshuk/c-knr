#include <stdio.h>

int main(void) {
    int n = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("You have %d item%s.\n", n, (n != 1) ? "s" : "");

    return 0;
}