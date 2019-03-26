#include <stdio.h>

int main(void)
{
    long long int c, n;
    scanf("%lld", &c);

    while (c--)
    {
        scanf("%lld", &n);
        printf("%s\n", n > 8000 ? "Mais de 8000!" : "Inseto!");
    }

    return 0;
}