// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void) {

    printf("%d\n\n", setbits(202, 5, 7, 306));

    return 0;
}

int setbits(int x, int p, int n, int y) {
    int donor = y & ~(~0 << n); // Get the rightmost n bits of y
    int donor_shifted = donor << p; // generates 1s only where x must be changed
    int x_cleansed = x & ~(donor_shifted); // generates 0s only where x must be changed

    int result = x_cleansed | donor_shifted;

    return result;

}
