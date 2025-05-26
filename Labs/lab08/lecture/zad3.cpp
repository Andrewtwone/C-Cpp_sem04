#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

#define FUNC(x) ((x) * (x + 1) * (x) * (x * x - 3))

struct Point
{
    double x;
    double y;
    int extremum;
};

bool isExtremum(double y1, double y2, double y3, int &type)
{
    if (y2 > y1 && y2 > y3)
    {
        type = 1;
        return true;
    }
    if (y2 < y1 && y2 < y3)
    {
        type = -1;
        return true;
    }
    type = 0;
    return false;
}

void writeCSV(const vector<Point> &points, const string &filename)
{
    ofstream file(filename);
    for (auto &p : points)
        file << p.x << "," << p.y << "\n";
}

void writeTXT(const vector<Point> &points, const string &filename, double a, double b, double step)
{
    ofstream file(filename);
    file << "Funkcja: (x)(x+1)(x^2)(x^2-3)\n";
    file << "Zakres: " << a << " do " << b << ", krok: " << step << "\n";
    file << "Ekstrema:\n";
    for (auto &p : points)
        if (p.extremum != 0)
            file << (p.extremum == 1 ? "Maksimum: " : "Minimum: ") << "x=" << p.x << ", y=" << p.y << "\n";
}

void writeBIN(const vector<Point> &points, const string &filename)
{
    ofstream file(filename, ios::binary);
    for (auto &p : points)
        file.write((char *)&p, sizeof(Point));
}

int main(int argc, char *argv[])
{
    double a = -3, b = 3, step = 0.1;

    if (argc == 4)
    {
        a = atof(argv[1]);
        b = atof(argv[2]);
        step = atof(argv[3]);
    }
    else
    {
        cout << "Podaj zakres a b oraz krok: ";
        cin >> a >> b >> step;
    }

    vector<Point> data;
    for (double x = a; x <= b; x += step)
    {
        Point p;
        p.x = x;
        p.y = FUNC(x);
        p.extremum = 0;
        data.push_back(p);
    }

    for (size_t i = 1; i < data.size() - 1; ++i)
    {
        int type;
        if (isExtremum(data[i - 1].y, data[i].y, data[i + 1].y, type))
        {
            data[i].extremum = type;
        }
    }

    writeCSV(data, "wykres.csv");
    writeTXT(data, "info.txt", a, b, step);
    writeBIN(data, "punkty.dat");

    cout << "Wygenerowano pliki: wykres.csv, info.txt, punkty.dat\n";
    return 0;
}
