#include <stdio.h>

int g[10001][10001], v[10001], c;

void initiateg(int n);
void initiatev(int n);
void dfs(int i, int n);

int main(void)
{

    int t, n, m, a, b, i, j;

    scanf("%d", &t);

    for (j = 1; j <= t; j++)
    {
        scanf("%d %d", &n, &m);
        initiateg(n);
        initiatev(n);

        for (i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            a--, b--;
            g[a][b] = 1;
        }

        c = 0;
        for (i = 0; i < n; i++)
        {
            if (!v[i])
                dfs(i, n);
            if (c)
                break;
        }

        printf("%s\n", c ? "SIM" : "NAO");
    }

    return 0;
}

void initiateg(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            g[i][j] = 0;
    }
}

void initiatev(int n)
{
    int i;
    for (i = 0; i < n; i++)
        v[i] = 0;
}

void dfs(int i, int n)
{
    v[i] = 1;
    if (c)
        return;

    v[i] = 1;

    int j, d;

    for (j = 0; j < n; j++)
    {
        if (g[i][j])
        {
            if (v[j] == 1)
            {
                c = 1;
                return;
            }
            else if (v[j] == 0)
                dfs(j, n);
        }
    }
    v[i] = 2;
}