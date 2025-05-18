#include <iostream>
using namespace std;

int swapAndCompare(int &a, int &b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}

int main()
{
    int a, b;
    cout << "Podaj a i b: ";
    cin >> a >> b;
    int result = swapAndCompare(a, b);
    cout << "Wynik porownania: " << result << endl;
    return 0;
}