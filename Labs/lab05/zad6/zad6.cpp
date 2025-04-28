#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 7;
    // const int SIZE = 8;
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7};
    int temp;

    cout << "Tablica poczatkowa:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    if (SIZE % 2 == 1)
    {
        int middle_index = SIZE / 2;
        cout << "\nSrodkowy element: " << array[middle_index]
             << " (indeks " << middle_index << ")" << endl;
    }
    else
    {
        int middle_index1 = (SIZE / 2) - 1;
        int middle_index2 = SIZE / 2;
        cout << "\nSrodkowe elementy: "
             << array[middle_index1] << " (indeks " << middle_index1 << ") oraz "
             << array[middle_index2] << " (indeks " << middle_index2 << ")" << endl;
    }

    cout << "\nOdwracanie tablicy...\n";

    if (SIZE % 2 == 1)
    {
        for (int i = 0; i < SIZE / 2; i++)
        {
            temp = array[i];
            array[i] = array[SIZE - 1 - i];
            array[SIZE - 1 - i] = temp;
        }
    }
    else
    {
        for (int i = 0; i < (SIZE / 2) - 1; i++)
        {
            temp = array[i];
            array[i] = array[SIZE - 1 - i];
            array[SIZE - 1 - i] = temp;
        }
    }

    cout << "\nTablica po odwróceniu:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
