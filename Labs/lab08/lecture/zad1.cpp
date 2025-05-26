#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

struct Arguments
{
    string filename;
    double a, b, dx;
};

double func(double x)
{
    return x * x * (x + 3) * (x - 4) * pow(x - 7, 3);
}

void printHelp()
{
    cout << "Uzycie: zad1 <nazwa_pliku.csv> <poczatek_zakresu> <koniec_zakresu> <krok>\n";
    cout << "Przyklad: zad1 dane.csv -5 10 0.1\n";
}

Arguments parseArguments(int argc, char *argv[])
{
    if (argc != 5)
        throw invalid_argument("Nieprawidlowa liczba argumentow.");

    Arguments args;
    args.filename = argv[1];

    stringstream(argv[2]) >> args.a;
    stringstream(argv[3]) >> args.b;
    stringstream(argv[4]) >> args.dx;

    if (args.dx <= 0)
        throw invalid_argument("Krok dx musi byc dodatni.");

    if (args.a > args.b)
        throw invalid_argument("Poczatek zakresu a musi byc <= b.");

    return args;
}

int main(int argc, char *argv[])
{
    try
    {
        Arguments args = parseArguments(argc, argv);

        ifstream checkFile(args.filename);
        if (checkFile.good())
        {
            char wybor;
            cout << "Plik " << args.filename << " juz istnieje. Nadpisac? (t/n): ";
            cin >> wybor;
            if (tolower(wybor) != 't')
            {
                cout << "Zakonczono.\n";
                return 0;
            }
        }

        ofstream outFile(args.filename);
        if (!outFile.is_open())
        {
            cerr << "Nie mozna otworzyc pliku do zapisu.\n";
            return 1;
        }

        outFile << fixed << setprecision(4);

        for (double x = args.a; x <= args.b; x += args.dx)
        {
            double y = func(x);
            outFile << x << ";" << y << "\n";
        }

        cout << "Dane zostaly zapisane do pliku: " << args.filename << "\n";
    }
    catch (const exception &e)
    {
        cerr << "Blad: " << e.what() << "\n";
        printHelp();
        return 1;
    }

    return 0;
}
