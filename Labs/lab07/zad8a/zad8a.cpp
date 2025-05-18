#include <iostream>
using namespace std;

int search(const int tab[], int size, int value)
{
    for (int i = 0; i < size; ++i)
    {
        if (tab[i] == value)
            return i;
    }
    return -1;
}

int main()
{
    const int tab[] = {4, 8, 15, 16, 23, 42};
    int size = sizeof(tab) / sizeof(tab[0]);

    int searched;
    cout << "Podaj wartosc do wyszukania: ";
    cin >> searched;

    int index = search(tab, size, searched);

    if (index != -1)
    {
        cout << "Wartosc znaleziona na indeksie: " << index << endl;
    }
    else
    {
        cout << "Wartosc nie wystepuje w tablicy." << endl;
    }

    return 0;
}
