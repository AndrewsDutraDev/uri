#include <stdio.h>

int q[101];

int solve(int n)
{
    int i, j;
    for (i = 0; i < 100; i++)
        for (j = i; j < 100; j++)
            if (q[i] + q[j] == n)
                return 1;
    return 0;
}

int main(void)
{
    int n, i;

    for (i = 0; i <= 100; i++)
        q[i] = i * i;

    while (scanf("%d", &n) != EOF)
        printf("%s\n", solve(n) ? "YES" : "NO");

    return 0;
}