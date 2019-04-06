#include <stdio.h>
#include <math.h>
#include <limits.h>

#define N 505

typedef struct s_point
{
    double x, y;
} point;

point points[N];
int parent[N];
double key[N];
int mstSet[N];

double graph[N][N];

double distance(point p1, point p2)
{
    double d1 = (p1.x - p2.x), d2 = (p1.y - p2.y);
    return sqrt(d1 * d1 + d2 * d2);
}

double minKey(int n)
{
    double min;
    int i, minIndex;

    for (i = 0, min = LONG_MAX; i < n; i++)
    {
        if (!mstSet[i] && key[i] < min)
            min = key[i], minIndex = i;
    }
    return minIndex;
}

double prim(int n)
{
    int i, c, u, v;
    double sum;

    for (i = 0; i < n; i++)
        key[i] = LONG_MAX, mstSet[i] = 0;

    key[0] = 0, parent[0] = -1;

    for (c = 0; c < n - 1; c++)
    {
        u = minKey(n);
        mstSet[u] = 1;

        for (v = 0; v < n; v++)
            if (!mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    for (i = 0, sum = 0; i < n; i++)
        sum += graph[i][parent[i]];

    return sum;
}

int main(void)
{

    int c, n, i, j;

    scanf("%d", &c);

    while (c--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%lf %lf", &points[i].x, &points[i].y);

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                graph[i][j] = (i == j ? LONG_MAX : distance(points[i], points[j]));

        printf("%.2lf\n", prim(n) / 100);
    }

    return 0;
}