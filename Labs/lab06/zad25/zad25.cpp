#include <iostream>
using namespace std;

int main()
{
    int tab[5] = {1, 2, 3, 4, 5};

    int *dyn = new int[5];

    cout << "Tablica statyczna:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        dyn[i] = tab[i];
    }

    cout << "Tablica dynamiczna przed modyfikacja:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << dyn[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        dyn[i]++;
    }

    cout << "Tablica dynamiczna po modyfikacji:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << dyn[i] << " ";
    }
    cout << endl;

    delete[] dyn;

    return 0;
}
