#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define C 60
#define U -1

int dfs_count, bridges, dfs_low[C], dfs_parent[C], dfs_num[C];
vector<vector<int>> a;

void dfs(int u)
{
    dfs_low[u] = dfs_num[u] = dfs_count++;

    for (int j = 0; j < (int)a[u].size(); j++)
    {
        int v = a[u][j];
        if (dfs_num[v] == U)
        {
            dfs_parent[v] = u;
            dfs(v);

            if (dfs_low[v] > dfs_num[u])
                bridges++;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(void)
{
    int c, p, x, y;

    while (cin >> c >> p)
    {
        memset(dfs_low, U, sizeof dfs_low);
        memset(dfs_parent, U, sizeof dfs_parent);
        memset(dfs_num, U, sizeof dfs_num);
        dfs_count = bridges = 0;

        a.assign(c, vector<int>());

        while (p--)
        {
            cin >> x >> y;
            x--, y--;
            a[x].push_back(y), a[y].push_back(x);
        }

        dfs(0);

        cout << bridges << endl;

        a.clear();
    }

    return 0;
}