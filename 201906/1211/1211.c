#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct snum
{
    char n[201];
} typedef num;

int cmp(const void *a, const void *b)
{
    return strcmp(((num *)a)->n, ((num *)b)->n);
}

num a[10001];

int main(void)
{
    int n, i, j, c;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%s", a[i].n);
        qsort(a, n, sizeof(num), cmp);
        for (c = 0, i = 1; i < n; i++)
        {
            for (j = 0; a[i].n[j] != '\0'; j++)
            {
                if (a[i - 1].n[j] != a[i].n[j])
                    break;
            }
            c += j;
        }
        printf("%d\n", c);
    }

    return 0;
}