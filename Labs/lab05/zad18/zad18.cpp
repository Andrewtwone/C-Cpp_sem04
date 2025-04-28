#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int X = 5;
    const int Y = 5;
    const int Z = 5;

    int array[X][Y][Z];
    int sum = 0;

    srand(time(NULL));

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            for (int k = 0; k < Z; k++)
            {
                array[i][j][k] = rand() % 10;
                sum += array[i][j][k];
            }
        }
    }

    cout << "Suma wszystkich elementow tablicy: " << sum << endl;

    return 0;
}
