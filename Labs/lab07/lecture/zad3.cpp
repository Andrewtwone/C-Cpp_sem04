#include <iostream>
#include <cmath>
using namespace std;

void calculateAngleAndDistance(double x, double y, double &angleDegrees, double *distance)
{
    *distance = sqrt(x * x + y * y);
    double angleRadians = atan2(y, x);
    angleDegrees = angleRadians * (180.0 / M_PI);

    if (angleDegrees < 0)
        angleDegrees += 360;
}

int main()
{
    double x, y;
    cout << "Podaj wspolrzedne punktu P (x y): ";
    cin >> x >> y;

    double angle, distance;
    calculateAngleAndDistance(x, y, angle, &distance);

    cout << "Odleglosc punktu P od srodka kola: " << distance << endl;
    cout << "Kat miedzy promieniem a pozioma osia X: " << angle << " stopni" << endl;

    return 0;
}
