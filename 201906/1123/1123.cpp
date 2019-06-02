#include <iostream>
#include <queue>

using namespace std;

int g[1010][1010], c[1010];
queue<int> q;

void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        c[i] = INT32_MAX;
        for (int j = 0; j <= n; j++)
            g[i][j] = INT32_MAX;
    }
}

int dijkstra(int s, int d, int n)
{
    c[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] != INT32_MAX && c[j] > c[i] + g[i][j])
            {
                c[j] = c[i] + g[i][j];
                q.push(j);
            }
        }
    }
    return c[d];
}

int main(void)
{
    int n, m, c, k, i, u, v, p;

    while ((cin >> n >> m >> c >> k), (n || m || c || k))
    {
        init(n);
        for (i = 1; i <= m; i++)
        {
            cin >> u >> v >> p;

            if (u >= c && v >= c)
                g[u][v] = g[v][u] = p;
            if (u >= c & v < c)
                g[u][v] = p;
            if (u < c && v >= c)
                g[v][u] = p;
            if (u < c && v < c && abs(u - v) == 1)
                g[u][v] = g[v][u] = p;
        }
        cout << dijkstra(k, c - 1, n) << endl;
    }

    return 0;
}