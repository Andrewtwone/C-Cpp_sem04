#include <iostream>
using namespace std;

long square(long x)
{
    return x * x;
}

void squareRef(long &x)
{
    x = x * x;
}

int main()
{
    long num;
    cout << "Podaj liczbe: ";
    cin >> num;
    cout << "Kwadrat (kopiowanie): " << square(num) << endl;
    squareRef(num);
    cout << "Kwadrat (referencja): " << num << endl;
    return 0;
}