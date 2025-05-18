#include <iostream>
using namespace std;

double poleKwadratu(int a)
{
    return a * a;
}

double poleProstokata(double a, double b)
{
    return a * b;
}

double objetoscSzescianu(double a = 1, double b = 1, double c = 1)
{
    return a * b * c;
}

int main()
{
    int wybor;
    cout << "1. Pole kwadratu\n2. Pole prostokata\n3. Objetosc szescianu\nWybierz opcje: ";
    cin >> wybor;
    if (wybor == 1)
    {
        int a;
        cout << "Podaj bok: ";
        cin >> a;
        cout << "Pole: " << poleKwadratu(a) << endl;
    }
    else if (wybor == 2)
    {
        double a, b;
        cout << "Podaj boki: ";
        cin >> a >> b;
        cout << "Pole: " << poleProstokata(a, b) << endl;
    }
    else if (wybor == 3)
    {
        double a, b, c;
        cout << "Podaj wymiary (a b c): ";
        cin >> a >> b >> c;
        cout << "Objetosc: " << objetoscSzescianu(a, b, c) << endl;
    }
    else
    {
        cout << "Niepoprawny wybor." << endl;
    }
    return 0;
}