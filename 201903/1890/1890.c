#include <stdio.h>

long long c[10], d[10];

void init()
{
    int i;
    c[0] = d[0] = 1;
    for (i = 1; i < 10; i++)
    {
        c[i] = c[i - 1] * 26;
        d[i] = d[i - 1] * 10;
    }
}

int main(void)
{
    int tt, cc, dd;
    init();

    scanf("%d", &tt);

    while (tt--)
    {
        scanf("%d %d", &cc, &dd);
        printf("%d\n", (cc + dd) ? c[cc] * d[dd] : 0);
    }

    return 0;
}