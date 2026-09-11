// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
// each character in s1 that matches any character in the string s2.

#include <stdio.h>

void squeeze(char a[], char b[]);

int main(void) {
    char a[] = "hello";
    char b[] = "lock";

    squeeze(a, b);

    printf("%s", a);

    return 0;
}

void squeeze(char a[], char b[]) {
    int i, j, k;

    for (i = k = 0; a[i] != '\0'; ++i) {
        for (j = 0; b[j] != '\0'; ++j) {
            if (a[i] == b[j])
                break;
        }

        if (b[j] == '\0') {
            printf("%d%d%d\n", i, j, k);
            a[k++] = a[i];
        }
    }

    a[k] = '\0';
}