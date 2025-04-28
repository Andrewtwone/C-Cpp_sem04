#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int SIZE = 10;
    vector<vector<int>> matrix(SIZE, vector<int>(SIZE));
    int diagonal_sum = 0;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 100;
        }
        matrix[i][SIZE - 1 - i] = i;
        diagonal_sum += i;
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

    cout << "\nSuma elementow przekatnej (prawo -> lewo): " << diagonal_sum << endl;

    return 0;
}
