#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
using namespace std;

#define FUNCTION(x) ((x - 1) * (x - 3) * (x + 1))

typedef double (*FunctionPointer)(double);

struct Range
{
    double a, b, step;
};

double functionMacro(double x)
{
    return FUNCTION(x);
}

double rectangleMethod(FunctionPointer f, Range r)
{
    double result = 0.0;
    for (double x = r.a; x < r.b; x += r.step)
    {
        result += f(x) * r.step;
    }
    return result;
}

double trapezoidMethod(FunctionPointer f, Range r)
{
    double result = 0.0;
    for (double x = r.a; x < r.b; x += r.step)
    {
        double x_next = x + r.step;
        if (x_next > r.b)
            x_next = r.b;
        result += ((f(x) + f(x_next)) / 2.0) * (x_next - x);
    }
    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Uzycie: " << argv[0] << " <a> <b> <krok>" << endl;
        return 1;
    }

    Range r;
    try
    {
        r.a = stod(argv[1]);
        r.b = stod(argv[2]);
        r.step = stod(argv[3]);

        if (r.step <= 0)
            throw invalid_argument("Krok musi byc dodatni.");
        if (r.a > r.b)
            throw invalid_argument("a musi byc mniejsze niz b.");
    }
    catch (exception &e)
    {
        cerr << "Blad danych: " << e.what() << endl;
        return 2;
    }

    FunctionPointer f = functionMacro;
    double rect = rectangleMethod(f, r);
    double trap = trapezoidMethod(f, r);

    cout << fixed << setprecision(4);
    cout << "Metoda prostokatow: " << rect << endl;
    cout << "Metoda trapezow:     " << trap << endl;
    cout << "Roznica:             " << fabs(rect - trap) << endl;

    return 0;
}
