#include <stdio.h>

int calc(char s)
{
    if (s == 'W')
        return 64;
    else if (s == 'H')
        return 32;
    else if (s == 'Q')
        return 16;
    else if (s == 'E')
        return 8;
    else if (s == 'S')
        return 4;
    else if (s == 'T')
        return 2;
    else if (s == 'X')
        return 1;
    return 0;
}

int main(void)
{
    char s[205];
    int i, c, a;

    while (scanf("%s", s) && s[0] != '*')
    {
        for (i = 1, a = c = 0; s[i] != '\0'; i++)
        {
            c += calc(s[i]);
            if (s[i] == '/')
                a += c == 64, c = 0;
        }
        printf("%d\n", a);
    }
}