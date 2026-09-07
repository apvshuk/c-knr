// Exercise 2-2. Write a loop equivalent to the for loop
// below without using && or ||.
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//    s[i] = c;

#include <stdio.h>

int main(void) {
    int i = 0;
    const int lim = 1000;
    int c = 0;
    char s[lim + 1];

    while (i < lim - 1)
        if ((c = getchar()) != '\n')
            if (c != EOF)
                s[i] = c, ++i;
            else
                break;
        else
            break;
    return 0;
}

// both break statements are necessary, they mimic the && condition failing and
// the statement immediately stopping as a result, the loop stops. same here
// using the break statement.