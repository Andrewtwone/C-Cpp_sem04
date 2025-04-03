#include <iostream>
using namespace std;

int main()
{
  int x;
  cout << "Enter your number: ";
  cin >> x;

  int wynik = (x >= -10 && x < 22) || (x > 30 && x < 40) || (x > 0 && x <= 3) || (x >= 5 && x < 7);

  cout << wynik << endl;
  return 0;
}
