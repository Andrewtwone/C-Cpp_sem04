#include <iostream>
using namespace std;

// Stałe w C
#define LICZBA1 100
#define LICZBA2 200
#define LICZBA3 300

// Stałe w C++
const int stalaA = 500;
const unsigned int stalaB = 400u;
const unsigned long stalaC = 600ul;

int main()
{
  int suma = LICZBA1 + LICZBA2 + LICZBA3;
  double srednia = suma / 3.0;

  cout << "Suma: " << suma << endl;
  cout << "Srednia: " << srednia << endl;

  int zmienna1 = 100;
  int zmienna2 = 200;
  unsigned int zmienna3 = 50u;

  cout << "\nTesty odejmowania:" << endl;
  cout << "int - int: " << zmienna1 - zmienna2 << " (może być ujemne)" << endl;
  cout << "unsigned int - int: " << zmienna3 - zmienna2 << " (może wyjść bardzo duża liczba z powodu konwersji na unsigned)" << endl;
  cout << "unsigned int - unsigned int: " << zmienna3 - (unsigned int)zmienna2 << " (unsigned minus większe unsigned)" << endl;

  cout << "\nOperacje na stalych:" << endl;
  cout << "stałaA - stałaB: " << stalaA - stalaB << endl;
  cout << "stałaB - stałaC: " << stalaB - stalaC << " (unsigned - unsigned long)" << endl;

  return 0;
}