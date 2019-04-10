#include <iostream>
#include <string.h>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int longestSubStr(char *x, char *y, int m, int n)
{
    int mem[m + 1][n + 1];
    int result = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                mem[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
            {
                mem[i][j] = mem[i - 1][j - 1] + 1;
                result = max(result, mem[i][j]);
            }
            else
                mem[i][j] = 0;
        }
    }
    return result;
}

int main(void)
{

    char s1[51], s2[51];

    while (cin.getline(s1, 51))
    {
        cin.getline(s2, 51);
        cout << longestSubStr(s1, s2, strlen(s1), strlen(s2)) << endl;
    }

    return 0;
}