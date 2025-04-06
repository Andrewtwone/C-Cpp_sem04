#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    char c = 126;
    unsigned char uc = 126;

    cout << "Operacje na char (ze znakiem):\n";
    cout << "Oryginalnie: " << (int)c << " -> " << bitset<8>(c) << endl;

    cout << "Przesuniecie w prawo o 1 bit: " << (int)(c >>= 1) << " -> " << bitset<8>(c) << endl;
    cout << "Przesuniecie w lewo o 1 bit: " << (int)(c <<= 1) << " -> " << bitset<8>(c) << endl;
    cout << "Przesuniecie w lewo o 3 bity: " << (int)(c <<= 3) << " -> " << bitset<8>(c) << endl;

    cout << "\nOperacje na unsigned char (bez znaku):\n";
    cout << "Oryginalnie: " << (int)uc << " -> " << bitset<8>(uc) << endl;

    cout << "Przesuniecie w prawo o 1 bit: " << (int)(uc >>= 1) << " -> " << bitset<8>(uc) << endl;
    cout << "Przesuniecie w lewo o 1 bit: " << (int)(uc <<= 1) << " -> " << bitset<8>(uc) << endl;
    cout << "Przesuniecie w lewo o 3 bity: " << (int)(uc <<= 3) << " -> " << bitset<8>(uc) << endl;

    return 0;
}
