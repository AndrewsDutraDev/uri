#include <stdio.h>

int main(void)
{
    char n[6];
    long long acm;
    int i, j, a[6], b[] = {1, 2, 6, 24, 120};

    while (scanf("%s", n) && n[0] != '0')
    {
        for (i = 0; n[i] != '\0'; i++)
            a[i] = n[i] - 48;
        for (j = i - 1, i = acm = 0; n[i] != '\0'; i++, j--)
            acm = acm + a[i] * b[j];
        printf("%lld\n", acm);
    }

    return 0;
}