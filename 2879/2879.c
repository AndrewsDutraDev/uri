#include <stdio.h>

int main(void)
{
    int n, p, c = 0;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &p);
        c += !(p == 1);
    }

    printf("%d\n", c);

    return 0;
}