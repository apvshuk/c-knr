// strlen(s) implementation
#include <stdio.h>

int str_len(char s[]);

int main(void) {
    int i = 0;
    printf("%d", str_len("hello"));
}

int str_len(char s[]) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    return len;
}