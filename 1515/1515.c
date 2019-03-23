#include <stdio.h>
#include <stdlib.h>

struct s
{
    char p[55];
    int a;
};

int cmp(const void *a, const void *b)
{
    return ((struct s *)a)->a - ((struct s *)b)->a;    
}

int main(void)
{

    int n, i, a, t;
    struct s v[105];

    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%s %d %d", v[i].p, &a, &t);
            v[i].a = a - t;
        }

        qsort(v, n, sizeof(struct s), cmp);
        printf("%s\n", v[0].p);
    }

    return 0;
}