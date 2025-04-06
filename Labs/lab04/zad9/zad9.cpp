#include <iostream>
using namespace std;

int main()
{
    const int N = 10;
    int tablica[N];
    int wynik = 0;

    cout << "Podaj " << N << " liczb (0 lub 1):" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> tablica[i];
        if (tablica[i] != 0 && tablica[i] != 1)
        {
            cout << "Nieprawidlowy znak! Przyjmuje 0." << endl;
            tablica[i] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        wynik ^= tablica[i];
    }

    cout << "\nWynik XOR wszystkich elementow: " << wynik << endl;

    return 0;
}
