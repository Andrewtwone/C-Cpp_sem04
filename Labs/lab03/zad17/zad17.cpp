#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cout << "Podaj zakres (gorna granice): ";
    cin >> N;
    cin.ignore();

    cout << "Pomyśl liczbe z zakresu 1 do " << N << ". Komputer bedzie zgadywal." << endl;
    cout << "Odpowiadaj: 'za malo', 'za duzo' lub 'tak'\n\n";

    int lewy = 1, prawy = N;
    string odpowiedz;

    while (lewy <= prawy)
    {
        int srodek = (lewy + prawy) / 2;
        cout << "Czy to " << srodek << "?\n";
        getline(cin, odpowiedz);

        if (odpowiedz == "za malo")
        {
            lewy = srodek + 1;
        }
        else if (odpowiedz == "za duzo")
        {
            prawy = srodek - 1;
        }
        else if (odpowiedz == "tak")
        {
            cout << "Komputer zgadl! Liczba to: " << srodek << endl;
            break;
        }
        else
        {
            cout << "Nie rozumiem odpowiedzi. Uzyj: 'za malo', 'za duzo' lub 'tak'.\n";
        }
    }

    return 0;
}
