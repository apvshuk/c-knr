// my machine - int variables - 32 bits. Others may vary.
// a number stored as binary may not occupy all 32 bit positions; the remaining
// "vacant" positions, on the left are padded with 0's. When using UNARY
// operator, these "hidden" 0's flip to 1's. So keep that in mind when
// calculating the UNARY of a number, use the BIT SIZE of the variable. Answer
// of UNARY of a number is a function of BIT SIZE of the variable type.

#include <stdio.h>

int main(void) {
    int i = 0;

    scanf("%d", &i);

    printf("%d", ~i);

    return 0;
}