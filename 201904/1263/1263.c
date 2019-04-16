#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char s[5200], v, f;
    int i, a;

    while (gets(s))
    {
        for (i = 1, a = f = 0, v = s[0]; s[i] != '\0'; i++)
        {
            if (s[i] == ' ')
            {
                if (tolower(v) == tolower(s[i + 1]))
                {
                    if (!f)
                        a++, f = 1;
                }
                else
                {
                    v = s[i + 1], f = 0;
                }
            }
        }
        printf("%d\n", a);
    }

    return 0;
}