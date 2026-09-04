#include <stdio.h>

int main(void) {
    enum months {
        JAN = 1,
        FEB,
        MAR,
        APR,
        MAY,
        JUN,
        JUL,
        AUG,
        SEP,
        OCT,
        NOV,
        DEC
    };

    enum months this_month = SEP;

    printf("%d", this_month);
    return 0;
}