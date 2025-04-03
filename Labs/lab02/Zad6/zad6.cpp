#include <iostream>

using namespace std;

void spr(int number)
{
  int result = 0;
  if (number >= -10 && number < 20)
  {
    result = 1;
  }
  printf("Liczba %d przedział <-10, 20): %d\n", number, result);

  result = 0;
  if (number > 0 && number <= 10)
  {
    result = 1;
  }
  printf("Liczba %d przedział (0, 10>: %d\n", number, result);

  result = 0;
  if (number >= 3 && number <= 3)
  {
    result = 1;
  }
  printf("Liczba %d przedział <-3, 3>: %d\n\n", number, result);
}

int main()
{
  int i1 = 10, i2 = 20, i3 = 0, i4 = 10, i5 = -3, i6 = 3, i7 = 2, i8 = -5;
  spr(i1);
  spr(i2);
  spr(i3);
  spr(i4);
  spr(i5);
  spr(i6);
  spr(i7);
  spr(i8);

  return 0;
}