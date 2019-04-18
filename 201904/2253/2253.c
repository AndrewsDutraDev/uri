#include <stdio.h>

int main(void)
{
    char s[200];
    int v, c1, c2, c3, i;

    while (gets(s))
    {
        for (c1 = c2 = c3 = i = 0, v = 1; s[i] != '\0'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                c1 = 1;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                c2 = 1;
            else if (s[i] >= '0' && s[i] <= '9')
                c3 = 1;
            else
                v = 0;
        }
        printf("Senha %s.\n", v && c1 && c2 && c3 && i >= 6 && i <= 32 ? "valida" : "invalida");
    }

    return 0;
}