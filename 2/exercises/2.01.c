// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <stdio.h>

int char_(void);  // returns 2^n, n is the bit; find range from it.
int short_(void); // returns the bits; find range from it. - 16bits
int int_(void);   // returns the bits; find range from it. - 32bits
int long_(void);  // returns the bits; find range from it. - 32bits

int power_of_two(int n);

// signed and unsigned char
int char_(void) {
    int count = 0;
    unsigned char c = 0;
    // signed char c = 0;

    do {
        c++;
        count++;
    } while (c != 0);

    return count;
}

// signed and unsigned short
int short_(void) {
    int bits = 0;
    unsigned short x = 1;
    // signed short x = 1;
    do {
        bits++, x = x * 2;
    } while (x != 0);

    return bits;
}

// signed and unsigned int
int int_(void) {
    unsigned int x = 1;
    // signed int x = 1;
    int bits = 0;
    do {
        x = x * 2;
        bits++;
    } while (x != 0);

    return bits;
}

int long_(void) {
    unsigned long x = 1;
    // signed long x = 1;
    int bits = 0;

    do {
        bits++;
        x = x * 2;
    } while (x != 0);

    return bits;
}

int power_of_two(int n) {
    int result = 1;

    while (n--)
        result *= 2;

    return result;
}

int main(void) {
    printf("character: 0 to %d", char_() - 1);
    printf("\nshort: 0 to %lld", power_of_two(short_()) - 1);
    printf("\ninteger: 0 to %lld", power_of_two(int_()) - 1);
    printf("\nlong: 0 to %lld", power_of_two(long_()) - 1);

    printf("\nThese are ranges of unsigned variants; for signed divide 2^n, "
           "by 2, half goes to negative ints and other half to whole numbers, "
           "not positive ints, but whole numbers, note that.");

    return 0;
}