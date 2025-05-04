#include <iostream>
using namespace std;

int main()
{
    int tab[5] = {0};

    int *wsk = tab;

    int (*wskTab10)[10] = (int (*)[10])tab;

    tab[0] = 1;
    wsk[1] = 2;
    *(wsk + 2) = 3;

    cout << "Zawartosc tablicy:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(wsk + i) << " ";
    }
    cout << endl;

    return 0;
}
