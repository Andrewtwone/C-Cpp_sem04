#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double liczba;

  cout << "Podaj liczbe rzeczywista: ";
  cin >> liczba;

  double wartosc_bezwzgledna = abs(liczba);

  cout << "Wartosc bezwzgledna z " << liczba << " wynosi: " << wartosc_bezwzgledna << endl;

  return 0;
}
