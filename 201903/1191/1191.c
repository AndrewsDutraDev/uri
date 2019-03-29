#include <stdio.h>
#include <string.h>

#define N 30

int ct;
char pre[N], in[N];

int indexOf(char *s, char c)
{
    int i = 0;
    while (s[i] != c)
        i++;
    return i;
}

void mount(int i, int j)
{
    if (i <= j)
    {
        int p = indexOf(in, pre[++ct]);
        mount(i, p - 1);
        mount(p + 1, j);
        printf("%c", in[p]);
    }
}

int main(void)
{
    int len;
    while (scanf("%s %s", pre, in) != EOF)
    {
        ct = -1, len = strlen(pre) - 1;
        mount(0, len);
        printf("\n");
    }

    return 0;
}