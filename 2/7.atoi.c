/* atoi: convert s to integer */
#include <stdio.h>

int main(void) {
    int i, n = 0;
    const char s[] = "123";

    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = (s[i] - '0');
        printf("%d", n);
    }

    return 0;
}