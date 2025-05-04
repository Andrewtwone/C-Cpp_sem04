#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    char znak = 0;
    int ilosc = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc)
        {
            ilosc = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc)
        {
            znak = argv[i + 1][0];
        }
    }

    if (ilosc <= 0 || znak == 0)
    {
        cout << "Uzycie: " << argv[0] << " -c <znak> -n <ilosc>" << endl;
        return 1;
    }

    srand(time(NULL));

    char *tab = new char[ilosc + 1];

    for (int i = 0; i < ilosc; i++)
    {
        tab[i] = 'A' + rand() % 26;
    }
    tab[ilosc] = '\0';

    int licznik = 0;
    for (int i = 0; i < ilosc; i++)
    {
        if (tab[i] == znak)
            licznik++;
    }

    cout << "Wygenerowana tablica:\n"
         << tab << endl;
    cout << "Znak '" << znak << "' wystapil " << licznik << " razy." << endl;

    delete[] tab;

    return 0;
}
