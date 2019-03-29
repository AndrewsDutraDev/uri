#include <stdio.h>

int main(void)
{
    int n, s, m, min;

    scanf("%d %d", &n, &s);

    min = s;
    while (n--)
    {
        scanf("%d", &m);
        s += m;
        min = min < s ? min : s;
    }

    printf("%d\n", min);

    return 0;
}