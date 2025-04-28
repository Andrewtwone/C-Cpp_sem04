#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int SIZE = 10;
    int matrix[SIZE][SIZE];
    int diagonal_sum = 0;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 100;
        }
        matrix[i][i] = i;
        diagonal_sum += i; // suma przekątnej (od razu bez dodatkowych pętli)
    }

    cout << "\nMacierz 10x10:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSuma elementow przekatnej: " << diagonal_sum << endl;

    return 0;
}
