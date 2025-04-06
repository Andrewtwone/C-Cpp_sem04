#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265358979323846

using namespace std;

int main()
{
    double x, alpha, y;
    printf("Wczytaj x: ");
    cin >> x;
    printf("Wczytaj alfa(w stopniach): ");
    cin >> alpha;

    double radAlpha = alpha * PI / 180;

    y = sqrt(pow(x, 2) + 7) / 2 * x - pow(x, 2) + sin(radAlpha) / abs(pow(x, 3));

    cout << fixed << setprecision(3);
    cout << "Result = " << y << endl;
}