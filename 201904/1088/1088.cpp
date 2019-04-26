#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vint;

vint v;
int c;

vint mergeSort(int l, int r);
vint merge(vint l, vint r);

int main(void)
{
    int n, x, i;

    while (cin >> n && n)
    {
        v.clear(), c = 0;

        for (i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }

        mergeSort(0, n);
        cout << (c % 2 ? "Marcelo" : "Carlos") << endl;
    }

    return 0;
}

vint mergeSort(int l, int r)
{
    vint v1;
    int m = (l + r) / 2;

    if (l + 1 >= r)
    {
        v1.push_back(v[l]);
        return v1;
    }

    vint a = mergeSort(l, m);
    vint b = mergeSort(m, r);

    v1 = merge(a, b);

    return v1;
}

vint merge(vint a, vint b)
{
    int i = 0, j = 0, sa = a.size(), sb = b.size();
    vint v1;

    while (i < sa && j < sb)
    {
        if (a[i] < b[j])
            v1.push_back(a[i++]);
        else
            v1.push_back(b[j++]), c += sa - i;
    }

    while (i < sa)
        v1.push_back(a[i++]);

    while (j < sb)
        v1.push_back(b[j++]);

    return v1;
}