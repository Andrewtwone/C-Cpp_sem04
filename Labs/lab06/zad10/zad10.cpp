#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Podaj liczbe: ";
    cin >> a;

    cout << "Wczytana wartosc: " << a << endl;
    cout << "Adres zmiennej a: " << &a << endl;

    for (int i = 0; i < a; i++)
    {
        int *p = new int(i * 10);
        cout << "Iteracja " << i << ": adres dynamicznej zmiennej = " << p << ", wartosc = " << *p << endl;
        delete p;
    }

    // int *test = new int(10);
    // cout << *test << endl;
    // delete test;
    // cout << *test << endl;

    return 0;
}
