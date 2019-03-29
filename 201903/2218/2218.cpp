#include <iostream>

using namespace std;

int main(void)
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (n*(n+1))/2+1 << endl;
    }
    return 0;
}