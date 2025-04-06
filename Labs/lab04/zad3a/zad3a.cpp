#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double a, b, c;

    printf("Wczytaj a: ");
    cin >> a;
    printf("Wczytaj b: ");
    cin >> b;
    printf("Wczytaj c: ");
    cin >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                cout << "Niesk. wiele rozwiazan" << endl;
            else
                cout << "Brak rozwiazan" << endl;
        }
        else
        {
            cout << "To jest rownanie liniowe" << endl;
            cout << "Rozwiazanie: x = " << (-b / c) << endl;
        }
    }
    else
    {
        double delta = pow(b, 2) - 4 * a * c;

        if (delta < 0)
        {
            cout << "Brak rozwiazan rzeczywistyck (delta < 0)" << endl;
        }
        else if (delta == 0)
        {
            double x = -b / (2 * a);
            cout << "Jedno podwojne rozwiazanie: x = " << x << endl;
        }
        else
        {
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 = (-b + sqrt(delta)) / (2 * a);
            cout << "Rozwiazanie 1: x1 = " << x1 << endl;
            cout << "Rozwiazanie 2: x2 = " << x2 << endl;
        }
    }

    return 0;
}