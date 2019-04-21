#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    int n;
    string s;
    while (getline(cin, s))
    {
        n = atoi(s.c_str());

        if (n < 0)
            return 0;

        if (s[1] != 'x')
            cout << "0x" << std::hex << uppercase << n << endl;
        else
            istringstream(s) >> std::hex >> n, cout << std::dec << n << endl;
    }
}