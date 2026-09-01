/* Exercise 1-23. Write a program to remove all comments from a C program. Don't
 */
/* forget to handle quoted strings and character constants properly.C comments
 */
/* don't nest. */

#include <stdio.h>

#define MAXLENGTH 1000
#define IN 1
#define OUT 0

int get_code(char line[]); /*returns character count excluding '\n' and '\0'*/
void rc(char line[], char cleansed[], int len); /*(r)emoves(c)omments - rc*/

int main(void) {
    int len = 0;
    char line[MAXLENGTH], cleansed[MAXLENGTH];

    /* I skip the while loop, let's do just one input - enter entire code in one
    / * line */
    if ((len = get_code(line)) > 0)
        rc(line, cleansed, len),
            printf("\n\n%s\n\n/*this is not a comment*/", cleansed);

    return 0;
}

void rc(char line[], char cleansed[], int len) {
    int i = 0, state = OUT, count = 0, quote = OUT;
    while (i < len) {
        if (line[i] == '"' && state == OUT) {
            if (quote == IN)
                quote = OUT;
            else if (quote == OUT)
                quote = IN;
        }
        if (i + 1 < len && line[i] == '/' && line[i + 1] == '*' && quote == OUT)
            state = IN;
        else if (line[i - 2 >= 0 ? i - 2 : 0] == '*' &&
                 line[i - 1 >= 0 ? i - 1 : 0] == '/' && quote == OUT &&
                 state == IN)
            state = OUT;

        if (state == OUT)
            cleansed[count] = line[i], ++count;

        ++i;
    }
    cleansed[count] = '\0';
}

int get_code(char line[]) {
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n')
        if (i < MAXLENGTH - 1)
            line[i] = c, ++i;

    line[i] = '\0';

    return i; /* returns character-count only, not including '\0', and '\n' is
               */
              /* completely eliminated from the array; add '\n' in the printf */
              /* statement.*/
}