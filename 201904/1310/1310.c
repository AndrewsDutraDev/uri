#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
    int n, c, i, x, m, tm;

    while (scanf("%d", &n) != EOF)
    {
        scanf("%d", &c);

        for (i = m = tm = 0; i < n; i++)
        {
            scanf("%d", &x);
            tm += (x - c);
            tm = max(tm, 0);
            m = max(m, tm);
        }

        printf("%d\n", m);
    }

    return 0;
}