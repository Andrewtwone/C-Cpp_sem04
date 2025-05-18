#include <iostream>
#include <bitset>
using namespace std;

void printCharDetails(char ch)
{
    cout << "Znak: '" << ch << "'  ASCII: " << (int)ch << "  Binarnie: " << bitset<8>(ch) << endl;
}

int main()
{
    char ch;
    cout << "Podaj znaki (zakonczenie: kropka '.'): " << endl;

    while (true)
    {
        cin.get(ch);
        if (ch == '.')
            break;

        if (ch == '\n')
            continue;

        printCharDetails(ch);
    }

    cout << "Koniec programu." << endl;
    return 0;
}
