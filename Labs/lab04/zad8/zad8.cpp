#include <iostream>
#include <bitset>
using namespace std;

int main()
{

    // 1. Utworzenie zmiennej o wartości 00001011 (dziesiętnie 11)
    unsigned char liczba = 0b00001011;
    cout << "Poczatkowa liczba: " << (int)liczba << " -> " << bitset<8>(liczba) << endl;

    // 2. Zresetowanie bitu LSB (najmłodszego bitu - bit 0)
    liczba &= ~(1 << 0);
    cout << "Po resecie LSB: " << (int)liczba << " -> " << bitset<8>(liczba) << endl;

    // 3. Ustawienie bitu MSB (najstarszego bitu - bit 7)
    liczba |= (1 << 7);
    cout << "Po ustawieniu MSB: " << (int)liczba << " -> " << bitset<8>(liczba) << endl;

    // 4. Ustawienie bitu nr 2
    liczba |= (1 << 2);
    cout << "Po ustawieniu bitu 2: " << (int)liczba << " -> " << bitset<8>(liczba) << endl;

    // 5. Sprawdzenie czy bit 4 jest ustawiony
    if (liczba & (1 << 4))
    {
        cout << "Bit 4 jest ustawiony." << endl;
    }
    else
    {
        cout << "Bit 4 NIE jest ustawiony." << endl;
    }

    // 6. Sprawdzenie czy bity 5 i 6 są ustawione
    if ((liczba & (1 << 5)) && (liczba & (1 << 6)))
    {
        cout << "Bity 5 i 6 sa ustawione." << endl;
    }
    else
    {
        cout << "Bity 5 i 6 NIE sa ustawione." << endl;
    }

    // 7. Inwersja bitu nr 3 (zmiana stanu na przeciwny)
    liczba ^= (1 << 3);
    cout << "Po inwersji bitu 3: " << (int)liczba << " -> " << bitset<8>(liczba) << endl;

    // 8. Ponowna inwersja bitu nr 3
    liczba ^= (1 << 3);
    cout << "Po ponownej inwersji bitu 3: " << (int)liczba << " -> " << bitset<8>(liczba) << endl;

    // 9. Przesunięcie liczby o dwa bity w lewo
    liczba <<= 2;
    cout << "Po przesunieciu o 2 bity w lewo: " << (int)liczba << " -> " << bitset<8>(liczba) << endl;

    // cout << bitset<3>(~(1 << 1)) << endl;

    return 0;
}
