#include <iostream>

using namespace std;

int main(void)
{

    int n, d;

    while (cin >> n >> d, n && d)
    {
        char i[n + 1], o[n + 1];
        cin >> i;
        int t = -1, p = 0;

        while (d > 0)
        {
            if (t == -1)
                o[++t] = i[p++];

            if (o[t] < i[p])
                t--, d--;
            else
            {
                o[++t] = i[p++];
                if (p == n)
                    while (d--)
                        t--;
            }
        }

        for (int k = p; k < n; k++)
            o[++t] = i[k];
        o[t + 1] = '\0';
        cout << o << endl;
    }

    return 0;
}