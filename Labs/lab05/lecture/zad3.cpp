#include <iostream>
using namespace std;

int main()
{
    int tablica[] = {0, 33, 115, 105, 112, 97, 110, 32, 121, 110, 106, 97, 102, 32, 116, 115, 101, 106, 32, 111, 84};

    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    cout << "Wynik:\n";
    for (int i = rozmiar - 1; i >= 0; i--)
    {
        cout << static_cast<char>(tablica[i]);
    }
    cout << endl;

    return 0;
}
