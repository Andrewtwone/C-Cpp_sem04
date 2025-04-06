#include <iostream>
using namespace std;

int main()
{
    int n, i = 0, suma = 0, a;

    cout << "Podaj liczbe elementow: ";
    cin >> n;

start:
    if (i < n)
    {
        cout << "Podaj liczbe: ";
        cin >> a;
        suma += a;
        i++;
        goto start;
    }

    cout << "Suma: " << suma << endl;
    return 0;
}