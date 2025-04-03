#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, wynik;
    int wybor;
    bool koniec = false;

    cout << "============================\n";
    cout << "  KALKULATOR ARYTMETYCZNY\n";
    cout << "============================\n";

    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "Podaj druga liczbe: ";
    cin >> b;

    while (!koniec)
    {
        cout << "\n=== MENU ===\n";
        cout << "1. Dodawanie (a + b)\n";
        cout << "2. Odejmowanie (a - b)\n";
        cout << "3. Mnozenie (a * b)\n";
        cout << "4. Dzielenie (a / b)\n";
        cout << "5. Zakoncz program\n";
        cout << "Wybierz operacje (1-5): ";
        cin >> wybor;

        cout << fixed << setprecision(3);

        switch (wybor)
        {
        case 1:
            wynik = a + b;
            cout << "Wynik: " << a << " + " << b << " = " << wynik << endl;
            break;
        case 2:
            wynik = a - b;
            cout << "Wynik: " << a << " - " << b << " = " << wynik << endl;
            break;
        case 3:
            wynik = a * b;
            cout << "Wynik: " << a << " * " << b << " = " << wynik << endl;
            break;
        case 4:
            if (b != 0)
            {
                wynik = a / b;
                cout << "Wynik: " << a << " / " << b << " = " << wynik << endl;
            }
            else
            {
                cout << "Blad: dzielenie przez zero!" << endl;
            }
            break;
        case 5:
            koniec = true;
            cout << "Program zakonczony." << endl;
            break;
        default:
            cout << "Niepoprawny wybor. Sprobuj ponownie." << endl;
            break;
        }
    }

    return 0;
}