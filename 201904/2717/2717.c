#include <stdio.h>

int main(void)
{
    int n, a, b;
    scanf("%d\n%d %d", &n, &a, &b);
    printf("%s\n", (a + b) > n ? "Deixa para amanha!" : "Farei hoje!");
    return 0;
}