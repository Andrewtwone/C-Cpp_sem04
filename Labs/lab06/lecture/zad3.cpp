#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

void print_binary(unsigned char byte)
{
    for (int i = 7; i >= 0; i--)
    {
        cout << ((byte >> i) & 1);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Uzycie: program <napis>\n";
        return 1;
    }

    setlocale(LC_ALL, "");

    const char *input = argv[1];

    wchar_t wtext[256] = {0};
    mbstowcs(wtext, input, sizeof(wtext) / sizeof(wchar_t));

    unsigned char *ptr = (unsigned char *)wtext;

    cout << "\nProgram wyswietla bajty HEX i BIN napisu:\n";
    cout << "[ ";

    for (size_t i = 0; i < (wcslen(wtext) + 1) * sizeof(wchar_t); i++)
    {
        cout << hex << setw(2) << setfill('0') << (int)ptr[i] << " ";
    }

    cout << "]\n[ ";

    for (size_t i = 0; i < (wcslen(wtext) + 1) * sizeof(wchar_t); i++)
    {
        print_binary(ptr[i]);
        cout << " ";
    }

    cout << "]\n";

    return 0;
}
