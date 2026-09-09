/* atoi: convert s to integer */
#include <stdio.h>

int main(void) {
    int i, n = 0;
    const char s[] = "12310";

    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = (n * 10) + (s[i] - '0');
    }
    printf("%d", n + 10); // meaning the string of int is converted to int
                          // datatype, and + operator will treat it as a number.

    return 0;
}