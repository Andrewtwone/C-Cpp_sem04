#include <iostream>
using namespace std;

int main()
{
    cout << "PROGRAM DO OBLICZANIA MIEJSCA ZEROWEGO FUNKCJI LINIOWEJ (y = ax + b)\n";
    cout << "Podaj wspolczynniki a oraz b dla rownania ax + b = 0:\n";

    double a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "\nWynik:\n";

    if (a == 0)
    {
        if (b == 0)
        {
            cout << "Rownanie ma nieskonczenie wiele rozwiazan (0 = 0)." << endl;
        }
        else
        {
            cout << "Brak rozwiazan (0x + b = 0)." << endl;
        }
    }
    else
    {
        double x0 = -b / a;
        cout << "Miejsce zerowe funkcji: x = " << x0 << endl;
    }

    while (true)
    {
        cout << "\nNacisnij Enter, aby zakonczyc...";
        cin.ignore();
        char znak = cin.get();
        if (znak == '\n')
        {
            break;
        }
    }
    return 0;
}