#include <iostream>
using namespace std;

struct IP
{
    unsigned int octet[4];
};

IP calculateNetworkAddress(IP ip, IP mask)
{
    IP network;
    for (int i = 0; i < 4; ++i)
    {
        network.octet[i] = ip.octet[i] & mask.octet[i];
    }
    return network;
}

void readIP(IP &ip, const string &label)
{
    cout << "Podaj " << label << " (4 liczby oddzielone spacja): ";
    for (int i = 0; i < 4; ++i)
    {
        cin >> ip.octet[i];
        if (ip.octet[i] > 255)
        {
            cout << "Blad: kazda czesc adresu musi byc z zakresu 0-255.\n";
            exit(1);
        }
    }
}

void printIP(const IP &ip)
{
    for (int i = 0; i < 4; ++i)
    {
        cout << ip.octet[i];
        if (i < 3)
            cout << ".";
    }
    cout << endl;
}

int main()
{
    IP address, mask;

    readIP(address, "adres IP");
    readIP(mask, "maske");

    IP network = calculateNetworkAddress(address, mask);

    cout << "Adres sieci: ";
    printIP(network);

    return 0;
}
