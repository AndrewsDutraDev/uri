#include <stdio.h>

int uri(char *s)
{
    return s[0] == 'U' && s[1] == 'R' && s[3] == '\0';
}

int obi(char *s)
{
    return s[0] == 'O' && s[1] == 'B' && s[3] == '\0';
}

int main(void)
{
    int n;
    char s[21];

    scanf("%d", &n);

    while (n--)
    {
        scanf("%s", s);

        if (obi(s))
            printf("OBI");
        else if (uri(s))
            printf("URI");
        else
            printf("%s", s);
        if (n)
            printf(" ");
    }

    printf("\n");

    return 0;
}