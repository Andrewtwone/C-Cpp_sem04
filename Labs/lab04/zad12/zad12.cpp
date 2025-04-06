#include <iostream>
#include <string>
using namespace std;

enum Maska
{
    BIT_0 = 1 << 0, // 1
    BIT_1 = 1 << 1, // 2
    BIT_2 = 1 << 2, // 4
    BIT_3 = 1 << 3, // 8
    BIT_4 = 1 << 4, // 16
    BIT_5 = 1 << 5, // 32
    BIT_6 = 1 << 6, // 64
    BIT_7 = 1 << 7  // 128
};

int main()
{
    int liczba, bit;

    cout << "Program sprawdzajacy ustawienie wskazanego bitu w liczbie." << endl;
    cout << "Podaj liczbe z zakresu 0..255: ";
    cin >> liczba;
    cout << "Podaj numer bitu (0..7): ";
    cin >> bit;

    ((liczba >= 0 && liczba <= 255 && bit >= 0 && bit <= 7) && (cout << "\nSprawdzanie..." << endl) && ((cout << ((liczba & (1 << bit)) ? "TAK" : "NIE")) || true)) || (cout << "\nBlad danych! Liczba musi byc w zakresie 0..255, bit w zakresie 0..7.");

    cout << endl;
    return 0;
}
