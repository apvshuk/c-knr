#include <stdio.h>

int main(void) {
    int i = 0;

    int n = 52;
    char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < n; i++) {
        printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
    }

    return 0;
}