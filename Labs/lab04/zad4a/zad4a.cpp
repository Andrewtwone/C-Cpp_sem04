#include <iostream>
#include <iomanip>

using namespace std;

double f(double x)
{
    return (x + 2) * (x * x) * (x + 4) - 2;
}

int main()
{

    double a, b;
    double krok = 0.1;

    printf("Podaj poczatek przedzialu: ");
    cin >> a;
    printf("Podaj koniec przedzialu: ");
    cin >> b;

    if (a > b)
    {
        cout << "Niepoprawny przedzial" << endl;
        return 1;
    }

    double min_x = a;
    double max_x = a;
    double min_f = f(a);
    double max_f = f(a);

    double x = a;
    double fx;

    while (x <= b)
    {
        fx = f(x);
        if (fx < min_f)
        {
            min_f = fx;
            min_x = x;
        }
        if (fx > max_f)
        {
            max_f = fx;
            max_x = x;
        }
        x += krok;
    }

    cout << fixed << setprecision(2);
    cout << "\nMinimum funkcji: f(" << min_x << ") = " << min_f << endl;
    cout << "Maksimum funkcji: f(" << max_x << ") = " << max_f << endl;

    return 0;
}