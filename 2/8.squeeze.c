// squeeze: delete all c from s

#include <stdio.h>

void squeeze(char s[], int c);

int main(void) {
    char s[] = "Hello";
    squeeze(s, 'l');
    printf("%s", s);
    return 0;
}

void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}