// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void) {

    printf("%d", setbits(0b1111, 3, 3, 0b1010));

    return 0;
}

int setbits(int x, int p, int n, int y) {
    // Step 1: Isolate the rightmost n bits of y
    int mask = ~(~0 << n);
    int y_ = y & mask;

    // Step 2: Left shift y_ into its target position
    int y_shifted = y_ << (p - n + 1);

    // Step 3: Create a mask to clear the target bits in x
    // This creates ones everywhere except at the target position, which are
    // zeroes
    int x_clear_mask = ~(mask << (p - n + 1));

    // Step 4: Clear the hole in x, then drop in the shifted y bits
    x = (x & x_clear_mask) | y_shifted;

    return x;
}
