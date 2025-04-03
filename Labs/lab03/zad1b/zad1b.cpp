#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double podstawa;
    int wykladnik;

    cout << "Podaj podstawe: ";
    cin >> podstawa;

    cout << "Podaj wykladnik (moze byc ujemny): ";
    cin >> wykladnik;

    int abs_wykladnik = abs(wykladnik);

    // ------------------------------
    // 1. Pętla FOR
    double wynik_for = 1;
    for (int i = 0; i < abs_wykladnik; i++)
    {
        wynik_for *= podstawa;
    }
    if (wykladnik < 0)
        wynik_for = 1 / wynik_for;

    // ------------------------------
    // 2. Pętla WHILE
    double wynik_while = 1;
    int i = 0;
    while (i < abs_wykladnik)
    {
        wynik_while *= podstawa;
        i++;
    }
    if (wykladnik < 0)
        wynik_while = 1 / wynik_while;

    // ------------------------------
    // 3. Pętla DO..WHILE
    double wynik_do = 1;
    int j = 0;

    if (abs_wykladnik == 0)
    {
        wynik_do = 1;
    }
    else
    {
        do
        {
            wynik_do *= podstawa;
            j++;
        } while (j < abs_wykladnik);
        if (wykladnik < 0)
            wynik_do = 1 / wynik_do;
    }

    // ------------------------------
    cout << fixed << setprecision(2);
    cout << "\nWynik (for): " << wynik_for << endl;
    cout << "Wynik (while): " << wynik_while << endl;
    cout << "Wynik (do..while): " << wynik_do << endl;

    return 0;
}
