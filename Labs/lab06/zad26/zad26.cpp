#include <iostream>
using namespace std;

int main()
{
    int *wsk1;           // wskaźnik NIEZAINICJALIZOWANY
    int *wsk2 = new int; // wskaźnik ZAINICJALIZOWANY

    cout << "Adres wsk1: " << wsk1 << " (NIEZAINICJALIZOWANY!)" << endl;
    cout << "Adres wsk2: " << wsk2 << " (ZAINICJALIZOWANY)" << endl;

    // Nie wolno: cout << *wsk1;  → może wywołać błąd (undefined behavior)

    cout << "Zawartosc wskazywana przez wsk2 (przed przypisaniem): " << *wsk2 << endl;

    // Inicjalizacja danych, na które wskazują
    // wsk1 — nie możemy bez przypisania, np.:
    int zmienna = 42;
    wsk1 = &zmienna;

    *wsk2 = 99;

    cout << "\n-- Po przypisaniu --" << endl;
    cout << "Adres wsk1: " << wsk1 << endl;
    cout << "Zawartosc wskazywana przez wsk1: " << *wsk1 << endl;

    cout << "Adres wsk2: " << wsk2 << endl;
    cout << "Zawartosc wskazywana przez wsk2: " << *wsk2 << endl;

    delete wsk2;

    return 0;
}
