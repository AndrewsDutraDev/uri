#include <stdio.h>

int main(void)
{
    int t, n, i, x, a, dx[101];
    char s[15];

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d\n", &n);

        for (i = x = 0; i < n; i++)
        {
            gets(s);
            if (s[0] == 'L')
                dx[i] = -1;
            else if (s[0] == 'R')
                dx[i] = 1;
            else
            {
                if (s[9] == '\0')
                    a = (s[8] - '0');
                else if (s[10] == '\0')
                    a = (s[8] - '0') * 10 + (s[9] - '0');
                else
                    a = (s[8] - '0') * 100 + (s[9] - '0') * 10 + (s[10] - '0');
                dx[i] = dx[--a];
            }
            x += dx[i];
        }

        printf("%d\n", x);
    }

    return 0;
}