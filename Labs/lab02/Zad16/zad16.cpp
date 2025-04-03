#include <iostream>
using namespace std;

int main()
{
  const double KM_NA_MILE = 1.6;
  double kilometry, mile;

  cout << "Podaj odleglosc w kilometrach: ";
  cin >> kilometry;

  mile = kilometry / KM_NA_MILE;

  cout << kilometry << " km to " << mile << " mil." << endl;

  return 0;
}
