#include <stdio.h>

int main(void)
{
    int t, n, i, j, v, a, x, y, g[50][50], ans;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d\n%d %d", &n, &v, &a);

        for (i = 0; i <= v; i++)
        {
            for (j = 0; j <= v; j++)
                g[i][j] = 0;
        }

        for (i = 0, ans = 0; i < a; i++)
        {
            scanf("%d %d", &x, &y);
            if (!g[x][y])
                ans++;
            g[x][y] = g[y][x] = 1;
        }

        printf("%d\n", ans * 2);
    }

    return 0;
}