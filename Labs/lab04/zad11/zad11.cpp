#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int liczba;
    cout << "Podaj liczbe (0..255): ";
    cin >> liczba;

    cout << "Postac binarna: ";

    for (int i = 7; i >= 0; i--)
    {
        if (liczba & (1 << i))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }

    cout << endl;
    cout << bitset<8>(liczba) << endl;
    return 0;
}
