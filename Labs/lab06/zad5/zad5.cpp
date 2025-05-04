#include <iostream>
using namespace std;

int main()
{

    int a[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}};
    char b[2][20] = {"Poniedzialek", "Wtorek"};
    char znaki[] = "Programowanie";

    int (*pa)[2] = a;

    cout << "Zawartosc tablicy a:\n";
    for (int i = 0; i < 6; i++)
    {
        cout << *(*(pa + i) + 0) << " " << *(*(pa + i) + 1) << endl;
    }

    char (*pb)[20] = b;

    cout << "\nZawartosc tablicy b:\n";
    for (int i = 0; i < 2; i++)
    {
        char *p = *(pb + i);
        while (*p)
        {
            cout << *p;
            p++;
        }
        cout << endl;
    }

    char *pz = znaki;

    cout << "\nZawartosc tablicy znaki:\n";
    while (*pz)
    {
        cout << *pz;
        pz++;
    }
    cout << endl;

    return 0;
}
