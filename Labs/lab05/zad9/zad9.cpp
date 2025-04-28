#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

int main()
{
    int N;
    cout << "Podaj liczbe liczb pseudolosowych do wygenerowania: ";
    cin >> N;

    if (N <= 0)
    {
        cout << "Liczba musi byc dodatnia!" << endl;
        return 1;
    }

    vector<int> numbers;
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        numbers.push_back(rand() % 101);
    }

    cout << "\nWygenerowane liczby:\n";
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    map<int, int> count_map;
    for (int num : numbers)
    {
        count_map[num]++;
    }

    cout << "\nWartosci powtarzajace sie:\n";
    bool any_repeats = false;
    for (auto pair : count_map)
    {
        if (pair.second > 1)
        {
            cout << "Liczba " << pair.first << " wystapila " << pair.second << " razy.\n";
            any_repeats = true;
        }
    }

    if (!any_repeats)
    {
        cout << "Brak powtarzajacych sie wartosci." << endl;
    }

    return 0;
}
