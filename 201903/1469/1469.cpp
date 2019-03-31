#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;

int dfs(graph &g, vector<int> &vi, vector<int> &age, int i, int j)
{
    int m = 101;
    vi[i] = j;
    for (int t = 0; t < g[i].size(); t++)
    {
        int to = g[i][t];
        if (vi[to] < j)
            m = min(min(m, age[to]), dfs(g, vi, age, to, j));
    }
    return m;
}

int main(void)
{
    int n, m, i;

    while (cin >> n >> m >> i)
    {
        graph g(n);
        vector<int> age(n), ind(n), vi(n, -1);

        for (int k = 0; k < n; k++)
        {
            cin >> age[k];
            ind[k] = k;
        }

        for (int k = 1; k <= m; k++)
        {
            int x, y;
            cin >> x >> y, x--, y--;
            g[y].emplace_back(x);
        }

        for (int k = 0; k < i; k++)
        {
            char t;
            cin >> t;
            if (t == 'T')
            {
                int a, b;
                cin >> a >> b, a--, b--;
                swap(age[ind[a]], age[ind[b]]);
                swap(ind[a], ind[b]);
            }
            else if (t == 'P')
            {
                int e;
                cin >> e, e--;

                if (!g[ind[e]].size())
                    cout << "*" << endl;
                else
                    cout << dfs(g, vi, age, ind[e], k) << endl;
            }
        }
    }

    return 0;
}