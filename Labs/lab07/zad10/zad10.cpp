#include <iostream>
#include <bitset>
using namespace std;

unsigned int setBit(unsigned int number, int n)
{
    return number | (1 << n);
}

unsigned int clearBit(unsigned int number, int n)
{
    return number & ~(1 << n);
}

void printBinary(unsigned int number)
{
    bitset<8> binary(number);
    cout << "Binarna postac: " << binary << endl;
}

int main()
{
    unsigned int number;
    int bit;
    int option;

    cout << "Podaj liczbe: ";
    cin >> number;

    cout << "Podaj numer bitu (0..7): ";
    cin >> bit;

    if (bit < 0 || bit > 7)
    {
        cout << "Niepoprawny numer bitu." << endl;
        return 1;
    }

    cout << "Wybierz operacje (1 - ustaw bit, 2 - kasuj bit): ";
    cin >> option;

    if (option == 1)
    {
        number = setBit(number, bit);
    }
    else if (option == 2)
    {
        number = clearBit(number, bit);
    }
    else
    {
        cout << "Niepoprawna opcja." << endl;
        return 1;
    }

    cout << "Nowa wartosc: " << number << endl;
    printBinary(number);

    return 0;
}