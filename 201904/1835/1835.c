#include <stdio.h>

#define N 105

int g[N][N], v[N];

void dfs(int i, int c, int n)
{
    int j;
    for (v[i] = c, j = 0; j < n; j++)
        if (!v[j] && g[i][j])
            dfs(j, c, n);
}

int main(void)
{
    int t, m, n, x, y, k, i, j, c;

    scanf("%d", &t);

    for (k = 1; k <= t; k++)
    {
        scanf("%d\n%d", &n, &m);

        for (i = 0; i < n; i++)
            for (v[i] = 0, j = 0; j < n; j++)
                g[i][j] = 0;

        for (i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            x--, y--, g[x][y] = g[y][x] = 1;
        }

        for (i = 0, c = 0; i < n; i++)
            if (!v[i])
                dfs(i, ++c, n);

        if (c - 1)
            printf("Caso #%d: ainda falta(m) %d estrada(s)\n", k, c - 1);
        else
            printf("Caso #%d: a promessa foi cumprida\n", k);
    }

    return 0;
}