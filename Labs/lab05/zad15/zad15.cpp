#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    const int SIZE = 10;
    const char BLOCK = 178;

    vector<vector<int>> matrix(SIZE, vector<int>(SIZE, BLOCK));

    for (int i = 0; i < SIZE; i++)
    {
        matrix[i][0] = i;
        matrix[i][1] = i * i;
    }

    cout << "\nMacierz 10x10:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (j == 0 || j == 1)
            {
                cout << setw(3) << matrix[i][j] << " ";
            }
            else
            {
                cout << setw(3) << static_cast<char>(matrix[i][j]) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
