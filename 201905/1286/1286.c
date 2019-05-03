#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

struct s
{
    int t, p;
};

struct s a[21];
int m[21][31];

int main()
{
    int n, p, i, j;

    while (scanf("%d", &n) && n)
    {
        scanf("%d", &p);
        for (i = 1; i <= n; i++)
            scanf("%d %d", &a[i].t, &a[i].p);

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= p; j++)
            {
                if (i == 0 || j == 0)
                    m[i][j] = 0;
                else
                    m[i][j] = a[i].p > j ? m[i - 1][j] : max(m[i - 1][j - a[i].p] + a[i].t, m[i - 1][j]);
            }
        }

        printf("%d min.\n", m[n][p]);
    }

    return 0;
}