#include <iostream>

using namespace std;

string tobin(int x);
char digit_hex(int x);
string tohex(int x);
void bin(char *x);
void dec(char *x);
void hex(char *x);

int main(void)
{
    int k, n;
    char x[50], y[4];

    cin >> n;

    for (k = 1; k <= n; k++)
    {
        cin >> x >> y;

        cout << "Case " << k << ":" << endl;

        if (y[0] == 'b')
            bin(x);
        else if (y[0] == 'd')
            dec(x);
        else if (y[0] == 'h')
            hex(x);

        cout << endl;
    }

    return 0;
}

string tobin(int x)
{
    string tmp;
    char c;
    while (x > 0)
    {
        c = x % 2 + '0';
        tmp = c + tmp;
        x /= 2;
    }
    return tmp;
}

char digit_hex(int x)
{
    if (x >= 0 && x < 10)
        return (x + '0');
    else if (x < 16)
        return (x - 10 + 'a');
    else
        return '!';
}

string tohex(int x)
{
    string tmp;
    while (x > 0)
    {
        tmp = digit_hex(x % 16) + tmp;
        x /= 16;
    }
    return tmp;
}

void bin(char *x)
{
    int xi = strtol(x, 0, 2);
    cout << xi << " dec" << endl;
    cout << tohex(xi) << " hex" << endl;
}

void dec(char *x)
{
    int xi = strtol(x, 0, 10);
    cout << tohex(xi) << " hex" << endl;
    cout << tobin(xi) << " bin" << endl;
}

void hex(char *x)
{
    int xi = strtol(x, 0, 16);
    cout << xi << " dec" << endl;
    cout << tobin(xi) << " bin" << endl;
}