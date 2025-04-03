#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double dystans_km, paliwo_litry, srednie_spalanie;

  cout << "Podaj dlugosc trasy w kilometrach: ";
  cin >> dystans_km;

  cout << "Podaj ilosc spalonego paliwa w litrach: ";
  cin >> paliwo_litry;

  srednie_spalanie = (paliwo_litry / dystans_km) * 100;

  cout << fixed << setprecision(2);
  cout << "\nSrednie zuzycie paliwa na 100 km wynosi: " << srednie_spalanie << " l/100km" << endl;

  return 0;
}
