#include <iostream>

using namespace std;

int main()
{

    int a = 15, b = -128;
    cout << (a <<= 4) << endl;
    cout << (b >>= 1) << endl
         << (b <<= 1) << endl;

    int num = 11;

    int mask = (1 << 3) | (1 << 4);

    if (num & mask)
    {
        cout << "Bit trzeci lub czwarty jest ustawiony" << endl;
    }
    else
    {
        cout << "Bit trzeci i czwarty nie sa ustawione" << endl;
    }

    return 0;
}