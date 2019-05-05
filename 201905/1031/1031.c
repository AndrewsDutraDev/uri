#include <stdio.h>

int solve(int n, int k)
{
    int r, i;
    for (r = 0, i = 1; i < n; i++)
        r = (r + k) % i;
    return r;
}

int main(void)
{
    int n, x, y, s;
    while (scanf("%d", &n) && n)
    {
        y = 0;
        while (solve(n, ++y) != 11) ;
        printf("%d\n", y);
    }
    return 0;
}