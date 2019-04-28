#include <stdio.h>

int n, m, x[1001][1001], i, j, f;

int main(void)
{
    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &x[i][j]);

    for (f = 0, i = 1; !f && i < n; i++)
    {
        for (j = 1; !f && j < m; j++)
        {
            f = x[i][j] == 42 &&
                x[i - 1][j - 1] == 7 &&
                x[i - 1][j] == 7 &&
                x[i - 1][j + 1] == 7 &&
                x[i][j - 1] == 7 &&
                x[i][j + 1] == 7 &&
                x[i + 1][j - 1] == 7 &&
                x[i + 1][j] == 7 &&
                x[i + 1][j + 1] == 7;
        }
    }

    printf("%d %d\n", f ? i - 1 : 0, f ? j - 1 : 0);

    return 0;
}