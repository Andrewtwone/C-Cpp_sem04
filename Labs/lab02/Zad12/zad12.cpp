#include <iostream>
#include <limits.h>
#include <float.h>
using namespace std;

int main()
{
  // int test
  int max_int = INT_MAX;
  int min_int = INT_MIN;
  cout << "INT_MAX: " << max_int << endl;
  cout << "INT_MIN: " << min_int << endl;
  max_int += 1; // przekroczenie zakresu
  min_int -= 1; // underflow
  cout << "INT_MAX + 1: " << max_int << " (overflow!)" << endl;
  cout << "INT_MIN - 1: " << min_int << " (underflow!)" << endl;

  // unsigned int test
  unsigned int u = 0;
  cout << "\nUnsigned int start: " << u << endl;
  u -= 1; // underflow
  cout << "Unsigned int - 1: " << u << " (underflow!)" << endl;

  // bool test
  bool b = 0;
  cout << "\nBool 0 (false): " << b << endl;
  b = 1;
  cout << "Bool 1 (true): " << b << endl;
  b = 1000;
  cout << "Bool 1000 (true): " << b << endl;

  // long test
  long max_long = LONG_MAX;
  cout << "\nLONG_MAX: " << max_long << endl;
  max_long += 1;
  cout << "LONG_MAX + 1: " << max_long << " (overflow!)" << endl;

  // char test
  char max_char = CHAR_MAX;
  char min_char = CHAR_MIN;
  cout << "\nCHAR_MAX: " << (int)max_char << endl;
  cout << "CHAR_MIN: " << (int)min_char << endl;
  max_char += 1;
  min_char -= 1;
  cout << "CHAR_MAX + 1: " << (int)max_char << " (overflow!)" << endl;
  cout << "CHAR_MIN - 1: " << (int)min_char << " (underflow!)" << endl;

  // float test
  float f = FLT_MAX;
  cout << "\nFLT_MAX: " << f << endl;
  f *= 10; // overflow do inf
  cout << "FLT_MAX * 10: " << f << " (może być inf)" << endl;

  float fmin = FLT_MIN;
  cout << "FLT_MIN: " << fmin << endl;
  fmin /= 10; // underflow - może być 0
  cout << "FLT_MIN / 10: " << fmin << " (może być 0)" << endl;

  return 0;
}
