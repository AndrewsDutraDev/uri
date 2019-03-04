#include <stdio.h>

unsigned long solve(unsigned long a, unsigned long b)
{
    long a1, b1, c = 0, t = 0;

    while (a || b)
    {
        a1 = a % 10, b1 = b % 10;
        a /= 10, b /= 10;
        if ((a1 + b1 + c) > 9)
            t++, c = 1;
        else
            c = 0;
    }

    return t;
}

int main(void)
{
    unsigned long a, b, c;
    while (scanf("%lu %lu", &a, &b) && (a || b))
    {
        c = solve(a, b);
        if (c == 0)
            printf("No carry operation.\n");
        else if (c == 1)
            printf("1 carry operation.\n");
        else
            printf("%lu carry operations.\n", c);
    }
    return 0;
}