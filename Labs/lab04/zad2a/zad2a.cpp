#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, x;
    printf("Wczytaj a: ");
    cin >> a;
    printf("Wczytaj b: ");
    cin >> b;

    if (a == 0)
    {
        if (b == 0)
            cout << "Rownanie ma niesk. wiele rozwiazan";
        else
            cout << "Brak rozwiazan";
    }
    else
    {
        x = -b / a;
        cout << "Rozwiazanie: x = " << x << endl;
    }

    return 0;
}