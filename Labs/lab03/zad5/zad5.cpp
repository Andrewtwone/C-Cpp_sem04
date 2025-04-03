#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int N = 100000000;
    double suma_rosnaco = 0.0;
    double suma_malejaco = 0.0;

    for (int i = 1; i <= N; ++i)
    {
        suma_rosnaco += 1.0 / (i * 1.0 * i);
    }

    for (int i = N; i >= 1; --i)
    {
        suma_malejaco += 1.0 / (i * 1.0 * i);
    }

    cout << fixed << setprecision(10);
    cout << "Suma rosnaco  : " << suma_rosnaco << endl;
    cout << "Suma malejaco : " << suma_malejaco << endl;

    printf("Suma rosnaco  (printf): %.10f\n", suma_rosnaco);
    printf("Suma malejaco (printf): %.10f\n", suma_malejaco);

    return 0;
}
