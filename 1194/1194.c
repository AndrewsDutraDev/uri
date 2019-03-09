#include <stdio.h>

#define N 55

int ct;
char pre[N], in[N];

int indexOf(char *s, char c)
{
    int i = 0;
    while (s[i] != c)
        i++;
    return i;
}

void solve(int i, int j)
{
    if (i <= j)
    {
        int p = indexOf(in, pre[++ct]);
        solve(i, p - 1);
        solve(p + 1, j);
        printf("%c", in[p]);
    }
}

int main(void)
{
    int c, n;
    scanf("%d", &c);

    while (c--)
    {
        scanf("%d %s %s", &n, pre, in);
        ct = -1, solve(0, n - 1);
        printf("\n");
    }

    return 0;
}