#include <iostream>
using namespace std;

int main()
{
    int n, i = 0, suma = 0, a;
    cout << "Podaj liczbe elementow: ";
    cin >> n;

Start:
    switch (i < n ? 1 : 0)
    {
    case 1:
        cout << "Podaj liczbe: ";
        cin >> a;
        suma += a;
        i++;
        goto Start;
    case 0:
        break;
    }

    cout << "Suma: " << suma << endl;
    return 0;
}