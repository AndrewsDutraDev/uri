#include <stdio.h>

int main(void)
{
    int i, n, x, xa, f, a, aa;

    scanf("%d", &n);
    scanf("%d", &xa);

    for (i = f = 1, aa = -1; i < n; i++)
    {
        scanf("%d", &x);
        a = x > xa;
        f = f && a != aa && x != xa;
        aa = a;
        xa = x;
    }

    printf("%d\n", f);

    return 0;
}