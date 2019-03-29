#include <stdio.h>

char i[3], d[3];

int diff(int a, int b)
{
    return a > b ? a - b : b - a;
}

int solve()
{
    int h = diff(i[0], d[0]);
    int v = diff(i[1], d[1]);

    return (h == 1 && v == 2) || (h == 2 && v == 1);
}

int main(void)
{
    scanf("%s %s", i, d);
    printf("%s\n", solve() ? "VALIDO" : "INVALIDO");
}