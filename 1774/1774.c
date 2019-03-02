#include <stdio.h>
#include <stdlib.h>

struct s_edge
{
    int v;
    int w;
    int p;
} typedef edge;

edge g[205];
int p[65];

int compare(const void *a, const void *b)
{
    return ((edge *)a)->p - ((edge *)b)->p;
}

int parent(int i)
{
    if (i == p[i])
        return i;
    return parent(p[i]);
}

int kruskal(int c)
{
    int i, mst, v, w;

    for (i = 0, mst = 0; i < c; i++)
    {
        v = parent(g[i].v);
        w = parent(g[i].w);

        if (v != w)
        {
            p[v] = p[w];
            mst += g[i].p;
        }
    }

    return mst;
}

int main(void)
{

    int r, c, i;

    scanf("%d %d", &r, &c);

    for (i = 0; i < c; i++)
    {
        scanf("%d %d %d", &g[i].v, &g[i].w, &g[i].p);
    }

    qsort(g, c, sizeof(edge), compare);
    for (i = 1; i <= r; i++)
        p[i] = i;

    printf("%d\n", kruskal(c));

    return 0;
}