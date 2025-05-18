#include <iostream>
#include <cmath>
using namespace std;

double square(double x)
{
    return x * x;
}

double prostok(double a, double b)
{
    if (a <= 0 || b <= 0)
        return -1;
    return sqrt(square(a) + square(b));
}

int main()
{
    double a, b;
    cout << "Podaj dlugosci przyprostokatnych (a i b): ";
    cin >> a >> b;

    double wynik = prostok(a, b);

    if (wynik == -1)
    {
        cout << "Podano bledne dane. Dlugosci musza byc dodatnie." << endl;
    }
    else
    {
        cout << "Dlugosc przeciwprostokatnej: " << wynik << endl;
    }

    return 0;
}
