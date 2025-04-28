#include <iostream>
using namespace std;

const int SIZE = 15;

void selectionSort(int array[], int size)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

int main()
{
    int array[SIZE] = {45, 12, 78, 34, 23, 67, 89, 10, 56, 44, 92, 11, 5, 30, 70};

    cout << "Tablica przed sortowaniem:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    selectionSort(array, SIZE);

    cout << "\nTablica po sortowaniu:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
