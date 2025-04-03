#include <iostream>
using namespace std;

int main()
{
  unsigned long duza_liczba = 3999999999;
  char znak = 'a';
  int liczba_calkowita = 23;
  double zmienna_double = 0.3;
  long double ogromna_liczba = 999e999;

  cout << "Duza liczba (unsigned long): " << duza_liczba << endl;
  cout << "Znak (char): " << znak << endl;
  cout << "Liczba calkowita (int): " << liczba_calkowita << endl;
  cout << "Zmienna zmiennoprzecinkowa (double): " << zmienna_double << endl;
  cout << "Ogromna liczba (long double): " << ogromna_liczba << endl;

  return 0;
}
