#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    const int NUMBERS = 10000;
    int series;

    cout << "Podaj liczbe serii losowan: ";
    cin >> series;

    if (series <= 0)
    {
        cout << "Liczba serii musi byc dodatnia!" << endl;
        return 1;
    }

    srand(time(NULL));

    cout << "\n";
    cout << setw(8) << "Seria"
         << setw(10) << "Zero"
         << setw(10) << "1000"
         << setw(12) << "Parzyste"
         << setw(14) << "Nieparzyste"
         << setw(14) << "Podz. przez 3"
         << setw(14) << "Suma parz."
         << setw(16) << "Suma nieparz."
         << endl;
    cout << string(98, '-') << endl;

    for (int s = 1; s <= series; s++)
    {
        int zeros = 0;
        int thousands = 0;
        int even_count = 0;
        int odd_count = 0;
        int divisible_by_3 = 0;
        long long even_sum = 0;
        long long odd_sum = 0;

        for (int i = 0; i < NUMBERS; i++)
        {
            int num = rand() % 1001;

            if (num == 0)
                zeros++;
            if (num == 1000)
                thousands++;
            if (num % 2 == 0)
            {
                even_count++;
                even_sum += num;
            }
            else
            {
                odd_count++;
                odd_sum += num;
            }
            if (num % 3 == 0)
                divisible_by_3++;
        }

        cout << setw(8) << s
             << setw(10) << zeros
             << setw(10) << thousands
             << setw(12) << even_count
             << setw(14) << odd_count
             << setw(14) << divisible_by_3
             << setw(14) << even_sum
             << setw(16) << odd_sum
             << endl;
    }

    return 0;
}
