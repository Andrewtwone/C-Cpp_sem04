#include <iostream>
#include <cctype>

using namespace std;

bool bcdOK(const string &s)
{
    for (char c : s)
    {
        if (!isxdigit(c) || toupper(c) > 'F')
            return false;
    }
    return true;
}

int main()
{
    string s;
    cout << "Podaj ciag do sprawdzenia BCD: ";
    cin >> s;
    cout << (bcdOK(s) ? "Poprawny BCD" : "Niepoprawny BCD") << endl;
}