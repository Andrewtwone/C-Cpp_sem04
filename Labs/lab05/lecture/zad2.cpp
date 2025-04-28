#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    const int ROZMIAR = 1000;
    char tekst[ROZMIAR];
    int ascii[ROZMIAR];

    cout << "Podaj tekst: ";
    cin.getline(tekst, ROZMIAR);

    int licznik = 0;
    int suma = 0;

    for (int i = 0; tekst[i] != '\0'; ++i)
    {
        ascii[i] = (tekst[i]);
        licznik++;
        suma += ascii[i];
    }

    double srednia = licznik > 0 ? static_cast<double>(suma) / licznik : 0.0;

    cout << "\nIlosc znakow: " << licznik << endl;
    cout << "Suma kodow ASCII: " << suma << endl;
    cout << fixed << setprecision(3);
    cout << "Srednia wartosc kodow ASCII: " << srednia << endl;

    return 0;
}
