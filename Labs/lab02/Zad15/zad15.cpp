#include <iostream>
using namespace std;

int main()
{
  int liczba;
  cout << "Podaj liczbe calkowita: ";
  cin >> liczba;

  // Sposób 1: klasyczne dodanie 1
  cout << "\nSposob 1 (liczba + 1): " << (liczba + 1) << endl;

  // Sposób 2: inkrementacja przedrostkowa
  int przedrostkowo = liczba;
  cout << "Sposob 2 (przedrostkowo ++liczba): " << (++przedrostkowo) << endl;

  // Sposób 3: inkrementacja przyrostkowa
  int przyrostkowo = liczba;
  cout << "Sposob 3 (przyrostkowo liczba++): " << (przyrostkowo++) << " (przed inkrementacja)" << endl;
  cout << "Wartosc po inkrementacji przyrostkowej: " << przyrostkowo << endl;

  return 0;
}
