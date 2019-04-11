#include <stdio.h>
#include <math.h>

int main(void)
{

    const double pi = atan(1.0) * 4;
    const double s = sin(0.6 * pi) / sin(0.35 * pi);
    double f;

    while (scanf("%lf", &f) != EOF)
    {
        printf("%.10f\n", s * f);
    }

    return 0;
}