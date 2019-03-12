#include<stdio.h>

#define N 6

int main(void) {
    
    int a[N], s[N], i, j, c = 0;
    
    scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
    
    scanf("%d %d %d %d %d %d", &s[0], &s[1], &s[2], &s[3], &s[4], &s[5]);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            c += a[i] == s[j];
        }
    }

    if (c < 3) printf("azar\n");
    else if (c == 3) printf("terno\n");
    else if (c == 4) printf("quadra\n");
    else if (c == 5) printf("quina\n");
    else if (c == 6) printf("sena\n");

    return 0;
}