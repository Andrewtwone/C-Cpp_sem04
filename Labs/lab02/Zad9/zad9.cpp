#include <iostream>
using namespace std;

int main()
{

  const double STAWKA_STANDARDOWA = 25.0;
  const double NADGODZINOWA_MULTIPLIER = 1.5;

  double godziny_standardowe;
  double godziny_nadliczbowe;
  double wyplata_standard;
  double wyplata_nadgodziny;
  double wyplata_suma;
  double procent_nadgodzin;

  cout << "Podaj liczbe godzin standardowych: ";
  cin >> godziny_standardowe;

  cout << "Podaj liczbe godzin nadliczbowych: ";
  cin >> godziny_nadliczbowe;

  wyplata_standard = godziny_standardowe * STAWKA_STANDARDOWA;

  wyplata_nadgodziny = godziny_nadliczbowe * STAWKA_STANDARDOWA * NADGODZINOWA_MULTIPLIER;

  wyplata_suma = wyplata_standard + wyplata_nadgodziny;

  if (godziny_standardowe > 0)
  {
    procent_nadgodzin = (godziny_nadliczbowe / godziny_standardowe) * 100;
  }

  cout << "\nWynagrodzenie za godziny standardowe: " << wyplata_standard << " zl" << endl;
  cout << "Wynagrodzenie za nadgodziny: " << wyplata_nadgodziny << " zl" << endl;
  cout << "Calkowite wynagrodzenie: " << wyplata_suma << " zl" << endl;
  cout << "Procent godzin nadliczbowych wzgledem standardowych: " << procent_nadgodzin << "%" << endl;

  return 0;
}