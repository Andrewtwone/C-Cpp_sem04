#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    srand(time(0));

    int wylosowana = rand() % 100 + 1;
    int proba;

    cout << "=== Gra: Za duzo - za malo ===" << endl;
    cout << "Zgadnij liczbe z przedzialu 1 do 100." << endl;
    cout << "Wpisz 0, aby zakonczyc gre." << endl;

    do
    {
        cout << "\nTwoja propozycja: ";
        cin >> proba;

        if (proba == 0)
        {
            cout << "Przerwano gre. Wylosowana liczba to: " << wylosowana << endl;
            break;
        }
        else if (proba < wylosowana)
        {
            cout << "Za malo!";
        }
        else if (proba > wylosowana)
        {
            cout << "Za duzo!";
        }
        else
        {
            cout << "Zgadles liczbe: " << wylosowana << endl;
        }

    } while (proba != wylosowana);

    return 0;
}
