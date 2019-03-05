#include <stdio.h>

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

int g[101][101], x, y;
char s[101][101];

int move(int i, int j, int m)
{
    if (i >= y || j >= x || g[i][j])
        return 0;

    g[i][j] = 1;

    if (s[i][j] == '>' || (s[i][j] == '.' && m == LEFT))
        return move(i, j + 1, LEFT);
    else if (s[i][j] == '<' || (s[i][j] == '.' && m == RIGHT))
        return move(i, j - 1, RIGHT);
    else if (s[i][j] == '^' || (s[i][j] == '.' && m == UP))
        return move(i - 1, j, UP);
    else if (s[i][j] == 'v' || (s[i][j] == '.' && m == DOWN))
        return move(i + 1, j, DOWN);
    else if (s[i][j] == '*')
        return 1;
}

int main(void)
{

    int a, i, j;

    scanf("%d\n%d", &x, &y);

    for (i = 0; i < y; i++)
    {
        scanf("%s", s[i]);
        for (j = 0; j < x; j++)
            g[i][j] = 0;
    }

    printf("%c\n", move(0, 0, LEFT) ? '*' : '!');

    return 0;
}