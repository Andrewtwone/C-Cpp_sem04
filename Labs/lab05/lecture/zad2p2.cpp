#include <iostream>
#include <iomanip> // dla setw
using namespace std;

int main()
{
    int tab[10][10] = {
        {19, 15, 29, 50, 92, 95, 27, 31, 11, 94},
        {99, 11, 32, 78, 64, 37, 48, 64, 63, 15},
        {69, 26, 74, 96, 41, 28, 16, 58, 77, 56},
        {89, 97, 71, 18, 47, 15, 14, 74, 98, 77},
        {21, 97, 88, 53, 27, 4, 43, 76, 68, 58},
        {91, 37, 84, 17, 86, 77, 98, 2, 88, 75},
        {10, 77, 24, 33, 96, 24, 48, 62, 98, 98},
        {39, 71, 48, 27, 77, 75, 84, 20, 51, 52},
        {78, 94, 42, 14, 64, 28, 44, 62, 82, 32},
        {37, 92, 9, 14, 25, 57, 38, 25, 19, 88}};

    cout << "Macierz 10x10:\n";

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << setw(3) << tab[i][j] << " ";
        }
        cout << endl;
    }

    // Obliczenie sumy pierwszej kolumny
    int suma = 0;
    for (int i = 0; i < 10; ++i)
    {
        suma += tab[i][0];
    }

    cout << "\nSuma elementow pierwszej kolumny: " << suma << endl;

    return 0;
}
