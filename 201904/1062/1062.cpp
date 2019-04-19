#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int n, i, c, a[1001];

    while (cin >> n && n)
    {
        while (cin >> a[0] && a[0])
        {
            for (i = 1; i < n; i++)
                cin >> a[i];

            stack<int> p;

            for (i = 1, c = 0; i <= n; i++)
            {
                p.push(i);
                while (p.size() && a[c] == p.top())
                    c++, p.pop();
            }

            cout << (p.size() ? "No" : "Yes") << endl;
        }
        cout << endl;
    }

    return 0;
}