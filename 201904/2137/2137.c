#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main(void)
{
    int n, i;
    char s[1005][5];

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%s", s[i]);

        qsort(s, n, 5 * sizeof(char), cmp);

        for (i = 0; i < n; i++)
            printf("%s\n", s[i]);
    }

    return 0;
}