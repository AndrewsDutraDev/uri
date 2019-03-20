#include <stdio.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a /= 2, b /= 3, c /= 5;
    printf("%d\n", MIN(a, MIN(b, c)));
    return 0;
}