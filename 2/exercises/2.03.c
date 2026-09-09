// Exercise 2-3. Write a function htoi(s), which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a through f, and A
// through F.

// algorithm:
// convert each letter to its corresponding number
// each number if multiplied by (16^n), where n is the index of that number from
// right. add 'em all.

#include <stdio.h>

int htoi(char s[]);
int power(int base, int exp);

int main(void) {
    char inp[10];
    scanf("%s", inp);
    printf("%d\n", htoi(inp));

    return 0;
}

int power(int base, int exp) {
    int i = exp;
    int n = 1;
    while (i--)
        n *= base;

    return n;
}

int htoi(char s[]) {
    int n = 0;
    int i = 0;
    int max_index = 0;
    int temp = 0;
    int a = 0;

    while (s[max_index] != '\0')
        max_index++;
    max_index -= 1;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        s[0] = '0', s[1] = '0'; // convert both to zero; zero at the highest
                                // position in HEXADECIMAL does not contribute.

    while (s[i] != '\0') {
        temp = s[max_index - i];
        if (temp >= '0' && temp <= '9')
            a = temp - '0';
        else if (temp >= 'A' && temp <= 'F')
            a = (temp - 'A') + 10;
        else if (temp >= 'a' && temp <= 'f')
            a = (temp - 'a') + 10;
        else {
            printf("Enter hexadecimal number only! please! can't u understand "
                   "hexa!!!! hexaaaaa!");
            return -1;
        }
        n += (a) * (power(16, i));
        ++i;
    }

    return n;
}