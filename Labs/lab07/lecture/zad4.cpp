#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct LetterStat
{
    char letter;
    int count;
};

char *createRandomLetters(int n, char from, char to)
{
    if (from > to)
        swap(from, to);

    int range = to - from + 1;
    char *letters = new char[n];

    for (int i = 0; i < n; ++i)
    {
        letters[i] = from + rand() % range;
    }

    return letters;
}

void displayHistogram(char *arr, int size, char from, char to)
{
    int range = to - from + 1;
    int *counts = new int[range]();

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] >= from && arr[i] <= to)
            counts[arr[i] - from]++;
    }

    for (int i = 0; i < range; ++i)
    {
        cout << char(from + i) << " – [" << setw(2) << counts[i] << "] ";
        for (int j = 0; j < counts[i]; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    delete[] counts;
}

LetterStat *buildStatTable(char *arr, int size, char from, char to, int &outSize)
{
    int range = to - from + 1;
    int *counts = new int[range]();

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] >= from && arr[i] <= to)
            counts[arr[i] - from]++;
    }

    LetterStat *stats = new LetterStat[range];
    outSize = range;
    for (int i = 0; i < range; ++i)
    {
        stats[i].letter = from + i;
        stats[i].count = counts[i];
    }

    delete[] counts;
    return stats;
}

void showMenu(LetterStat *stats, int size)
{
    cout << "\n=== MENU ===" << endl;
    cout << "Litera | Ilosc wystapien" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "  " << stats[i].letter << "    |" << setw(8) << stats[i].count << endl;
    }
}

int main()
{
    srand(time(0));

    int n;
    char from, to;

    cout << "Podaj liczbe liter do wylosowania: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Błąd: liczba musi być dodatnia." << endl;
        return 1;
    }

    cout << "Podaj zakres liter (np. a c): ";
    cin >> from >> to;

    if (!isalpha(from) || !isalpha(to))
    {
        cout << "Błąd: dozwolone tylko litery." << endl;
        return 1;
    }

    char *tab = createRandomLetters(n, from, to);

    cout << "\nZawartosc tablicy:\n";
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    cout << "\nWykres czestotliwosci:\n";
    displayHistogram(tab, n, from, to);

    int statSize;
    LetterStat *statTable = buildStatTable(tab, n, from, to, statSize);

    showMenu(statTable, statSize);

    delete[] tab;
    delete[] statTable;

    return 0;
}