#include <iostream>

using namespace std;

int main(void)
{
    char s[100];
    int b, i, k;

    while (cin.getline(s, 100))
    {
        b = i = 0, k = -1;
        while (s[++k] != '\0')
        {
            if (s[k] == '_')
                cout << (i++ % 2 ? "</i>" : "<i>");
            else if (s[k] == '*')
                cout << (b++ % 2 ? "</b>" : "<b>");
            else
                cout << s[k];
        }
        cout << endl;
    }
    return 0;
}
