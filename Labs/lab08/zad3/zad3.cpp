#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Uzycie: " << argv[0] << " <plik> [minX]\n";
        return 1;
    }

    int minLen = 2;
    if (argc == 3)
    {
        string arg = argv[2];
        if (arg.rfind("min", 0) == 0)
        {
            minLen = stoi(arg.substr(3));
            if (minLen < 1)
            {
                cerr << "Minimalna dlugosc wyrazu musi byc > 0.\n";
                return 2;
            }
        }
    }

    ifstream file(argv[1]);
    if (!file.is_open())
    {
        cerr << "Nie mozna otworzyc pliku: " << argv[1] << endl;
        return 3;
    }

    char ch;
    int totalChars = 0, upper = 0, lower = 0, words = 0;
    int wordLen = 0;
    bool inWord = false;

    while (file.get(ch))
    {
        totalChars++;
        if (isupper(ch))
            upper++;
        if (islower(ch))
            lower++;

        if (isalpha(ch))
        {
            inWord = true;
            wordLen++;
        }
        else
        {
            if (inWord && wordLen >= minLen)
            {
                words++;
            }
            inWord = false;
            wordLen = 0;
        }
    }

    if (inWord && wordLen >= minLen)
        words++;

    cout << "Liczba znakow: " << totalChars << endl;
    cout << "Liczba liter malych: " << lower << endl;
    cout << "Liczba liter wielkich: " << upper << endl;
    cout << "Liczba wyrazow (min " << minLen << " znaki): " << words << endl;

    return 0;
}
