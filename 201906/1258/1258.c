#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct se
{
    char n[100], c[10], t;
} typedef te;

te e[61];

int cmp(const void *c1, const void *c2)
{
    te *e1 = (te *)c1;
    te *e2 = (te *)c2;

    if (e1->c[0] != e2->c[0])
        return e1->c[0] - e2->c[0];
    else if (e1->t != e2->t)
        return e2->t - e1->t;

    return strcmp(e1->n, e2->n);
}

int main(void)
{

    int n, i, k = -1;

    while (scanf("%d", &n) && n)
    {
        for (i = 0; i < n; i++)
        {
            getchar();
            gets(e[i].n);
            scanf("%s %c", e[i].c, &e[i].t);
        }

        qsort(e, n, sizeof(te), cmp);

        if(++k)
            printf("\n");

        for (i = 0; i < n; i++)
            printf("%s %c %s\n", e[i].c, e[i].t, e[i].n);
    }

    return 0;
}