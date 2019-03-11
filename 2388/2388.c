#include <stdio.h>

int main(void)
{
    int n, t, v, s = 0;

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d %d", &t, &v);
        s += t * v;
    }

    printf("%d\n", s);

    return 0;
}