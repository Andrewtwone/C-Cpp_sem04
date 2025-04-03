#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    cout << "PROGRAM ROZWIAZUJACY ROWNANIE KWADRATOWE ax^2 + bx + c = 0\n";

    double a, b, c;
    cout << "Podaj wspolczynniki:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    cout << fixed << setprecision(2);

    if (a == 0)
    {
        // Równanie liniowe
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Rownanie ma nieskonczenie wiele rozwiazan (0 = 0)." << endl;
            }
            else
            {
                cout << "Rownanie sprzeczne — brak rozwiazan (0x = " << c << ")." << endl;
            }
        }
        else
        {
            double x = -c / b;
            cout << "To jest rownanie liniowe. Rozwiazanie: x = " << x << endl;
        }
    }
    else
    {
        // Równanie kwadratowe
        double delta = b * b - 4 * a * c;

        if (delta < 0)
        {
            cout << "Brak rozwiazan rzeczywistych (delta < 0)." << endl;
        }
        else if (delta == 0)
        {
            double x = -b / (2 * a);
            cout << "Jedno rozwiazanie: x = " << x << endl;
        }
        else
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Dwa rozwiazania:\n";
            cout << "x1 = " << x1 << "\n";
            cout << "x2 = " << x2 << endl;
        }
    }

    return 0;
}
