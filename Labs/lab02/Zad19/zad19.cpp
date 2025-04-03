#include <iostream>
using namespace std;

int main()
{
  int A, B;
  cout << "Podaj pierwsza wartosc logiczna (0 lub 1): ";
  cin >> A;
  cout << "Podaj druga wartosc logiczna (0 lub 1): ";
  cin >> B;

  int wynik = A + B - 2 * A * B;

  cout << "Wynik operacji XOR: " << wynik << endl;

  return 0;
}