#include <iostream>
#include <limits>
using namespace std;

void analyzeSequence()
{
    int number;
    int sum = 0;
    int count = 0;
    int minValue = numeric_limits<int>::max();
    int maxValue = numeric_limits<int>::min();

    cout << "Podawaj liczby (zakoncz 0):" << endl;

    while (true)
    {
        cin >> number;
        if (number == 0)
            break;

        sum += number;
        count++;

        if (number < minValue)
            minValue = number;
        if (number > maxValue)
            maxValue = number;
    }

    cout << "\nLiczba elementow: " << count << endl;
    cout << "Suma: " << sum << endl;
    cout << "Minimum: " << (count ? minValue : 0) << endl;
    cout << "Maksimum: " << (count ? maxValue : 0) << endl;
}

int main()
{
    analyzeSequence();
    return 0;
}
