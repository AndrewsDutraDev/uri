#include <stdio.h>

int main(void)
{
    int n, l, i, j, c, x, a[51];

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &l);
        
        for (i = 0; i < l; i++)
            scanf("%d", &a[i]);

        for (i = c = 0; i < l; i++)
            for (j = i + 1; j < l; j++)
                if (a[i] > a[j])
                    x = a[i], a[i] = a[j], a[j] = x, c++;

        printf("Optimal train swapping takes %d swaps.\n", c);
    }

    return 0;
}