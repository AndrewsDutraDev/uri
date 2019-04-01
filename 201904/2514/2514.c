#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int lcm3(int a, int b, int c)
{
    return lcm(a, lcm(b, c));
}

int main(void)
{
    int m, a, b, c;

    while (scanf("%d", &m) != EOF)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", lcm3(a, b, c) - m);
    }

    return 0;
}