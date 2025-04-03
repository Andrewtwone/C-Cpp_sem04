#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double kwota_brutto, podatek_procent, kwota_netto, wartosc_podatku;

  cout << "Podaj kwote brutto (PLN): ";
  cin >> kwota_brutto;

  cout << "Podaj wartosc podatku w procentach (%): ";
  cin >> podatek_procent;

  kwota_netto = kwota_brutto * 100 / (100 + podatek_procent);
  wartosc_podatku = kwota_brutto - kwota_netto;

  cout << fixed << setprecision(2);
  cout << "\nPrzy podatku " << podatek_procent << "% z kwoty brutto "
       << kwota_brutto << " PLN otrzymujemy kwote netto rowna "
       << kwota_netto << " PLN.\nWartosc podatku to " << wartosc_podatku << " PLN." << endl;

  return 0;
}
