#include<stdio.h>

int main(void) {
    int c, n, m;

    scanf("%d", &c);

    while(c--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", n % m ? n / m + 1 : n / m);
    }

    return 0;
}