#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    string napis, clear_nap;

    cout << "Podaj napis: ";
    getline(cin, napis);

    for (char znak : napis)
    {
        if (znak != ' ')
        {
            clear_nap += tolower(znak);
        }
    }

    string odwrotny = clear_nap;
    reverse(odwrotny.begin(), odwrotny.end());

    if (clear_nap == odwrotny)
    {
        cout << "To jest palindrom!" << endl;
    }
    else
    {
        cout << "To NIE jest palindrom." << endl;
    }

    return 0;
}
