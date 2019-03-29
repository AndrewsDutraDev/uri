#include <stdio.h>

int g[30][30], p[30];

void init(int v);
void dfs(int i, int v, int cc);

int main(void)
{
    int n, i, j, c, v, e, cc;
    char a, b;

    scanf("%d", &n);

    for (c = 1; c <= n; c++)
    {
        scanf("%d %d", &v, &e);
        cc = 0, init(v);

        for (i = 0; i < e; i++)
        {
            scanf(" %c %c", &a, &b);
            a -= 97, b -= 97;
            g[a][b] = g[b][a] = 1;
        }

        printf("Case #%d:\n", c);

        for (i = 0; i < v; i++)
        {
            if (!p[i])
            {
                cc++;
                dfs(i, v, cc);
                for (j = 0; j < v; j++)
                    if (p[j] == cc)
                        printf("%c,", j + 97);

                printf("\n");
            }
        }

        printf("%d connected components\n\n", cc);
    }

    return 0;
}

void init(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        p[i] = 0;
        for (j = 0; j < v; j++)
            g[i][j] = 0;
    }
}

void dfs(int i, int v, int cc)
{
    int j;
    if (p[i])
        return;

    p[i] = cc;

    for (j = 0; j < v; j++)
        if (i != j && g[i][j])
            dfs(j, v, cc);
}