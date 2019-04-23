#include <stdio.h>
#include <string.h>

int main()
{
    float a1, a2, a3, t1, t;
    int d, i, a, c, l;
    char n[10000];

    while (scanf("%d", &d) != EOF)
    {
        c = a = t1 = t = 0;
        for (l = 1; l <= d; l++)
        {
            scanf("%f", &a1);
            t += a1;
            getchar(), gets(n);

            for (i = 0; n[i] != '\0'; i++)
                if (n[i] == 32)
                    c++;

            a = c + 1, t1 += a, c = 0;
            printf("day %d: %d kg\n", l, a);
        }
        a2 = (float)(t / d), a3 = (float)(t1 / d);
        printf("%.2f kg by day\n", a3);
        printf("R$ %.2f by day\n", a2);
    }

    return 0;
}
