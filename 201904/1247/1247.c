#include <stdio.h>
#include <math.h>

int main(void)
{
    int d, vf, vg;
    double h;

    while (scanf("%d %d %d", &d, &vf, &vg) != EOF)
    {
        printf("%c\n", (sqrt(144.0 + d * d) / vg) <= (12.0 / vf) ? 'S' : 'N');
    }

    return 0;
}