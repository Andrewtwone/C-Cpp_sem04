#include <iostream>
using namespace std;

int main()
{
    char znak;
    int xor_wynik = 0;
    int liczba_jedynek = 0;
    int liczba_bledow = 0;

    cout << "Podaj ciag zer i jedynek. Enter konczy wprowadzanie:" << endl;

    while (true)
    {
        znak = cin.get();

        if (znak == '\n')
        {
            break;
        }

        if (znak == '1')
        {
            xor_wynik ^= 1;
            liczba_jedynek++;
        }
        else if (znak == '0')
        {
        }
        else
        {
            liczba_bledow++;
        }
    }

    cout << "\nWynik XOR: " << xor_wynik << endl;
    cout << "Liczba wprowadzonych jedynek: " << liczba_jedynek << endl;
    cout << "Liczba blednych znakow: " << liczba_bledow << endl;

    return 0;
}
