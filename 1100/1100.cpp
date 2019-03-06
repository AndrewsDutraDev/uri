#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct graph
{
    vector<string> e;
    bool v;
    int d;
};

map<string, graph> g;
queue<string> q;

int valid(int i, int j)
{
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

void init()
{
    string lti, nbj, lt = "abcdefgh", nb = "12345678";
    int di[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dj[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            lti = lt[i], nbj = nb[j];
            for (int k = 0; k < 8; k++)
            {
                int ik = i + di[k], jk = j + dj[k];

                if (valid(ik, jk))
                    g[lti + nbj].e.push_back(lt.substr(ik, 1) + nb.substr(jk, 1));
            }
        }
    }
}

void unvisit()
{
    string lti, nbj, lt = "abcdefgh", nb = "12345678";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            lti = lt[i], nbj = nb[j];
            g[lti + nbj].v = false;
            g[lti + nbj].d = 999;
        }
    }
}

int bfs(string a, string b)
{
    unvisit();

    g[a].v = true;

    q.push(a);
    g[a].d = 0;

    while (!q.empty())
    {
        string c = q.front();
        q.pop();

        for (vector<string>::iterator it = g[c].e.begin(); it != g[c].e.end(); it++)
        {
            if (!g[*it].v)
            {
                g[*it].v = true;
                q.push(*it);
                g[*it].d = g[c].d + 1;
            }
        }
    }

    return g[b].d;
}

void answer(string a, string b, int m)
{
    cout << "To get from " << a << " to " << b << " takes " << m << " knight moves." << endl;
}

int main(void)
{
    string a, b;

    init();

    while (cin >> a >> b)
        answer(a, b, bfs(a, b));

    return 0;
}