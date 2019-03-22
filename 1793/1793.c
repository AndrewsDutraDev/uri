#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int main(void)
{
    int n, b, r, t, i;

    while (scanf("%d", &n) && n)
    {
        r = 10, b = -1;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &t);
            if (i)
                r += min(t - b, 10);
            b = t;
        }
        printf("%d\n", r);
    }

    return 0;
}