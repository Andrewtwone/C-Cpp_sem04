#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    string filename;
    cout << "Podaj nazwę pliku: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Błąd otwarcia pliku!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    int maxLen = 0;
    int minLen = numeric_limits<int>::max();
    int longestLineNum = 0;

    while (getline(file, line))
    {
        ++lineCount;
        int length = line.length();

        if (length > maxLen)
        {
            maxLen = length;
            longestLineNum = lineCount;
        }
        if (length < minLen)
        {
            minLen = length;
        }
    }

    file.close();

    cout << "Liczba wierszy: " << lineCount << endl;
    cout << "Najdluzszy wiersz: nr " << longestLineNum << ", dlugosc: " << maxLen << endl;
    cout << "Najkrotszy wiersz: dlugosc: " << minLen << endl;

    return 0;
}
