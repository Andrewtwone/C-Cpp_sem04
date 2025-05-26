#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

int main()
{
    const char *filename = "kwadraty.txt";

    try
    {
        ofstream outFile(filename);
        if (!outFile)
            throw runtime_error("Nie mozna otworzyc pliku do zapisu.");

        for (int i = 1; i <= 10; ++i)
            outFile << (i * i) << endl;

        outFile.close();

        ifstream inFile(filename);
        if (!inFile)
            throw runtime_error("Nie mozna otworzyc pliku do odczytu.");

        cout << "\nZawartosc pliku " << filename << ":\n";
        int value;
        while (inFile >> value)
            cout << value << endl;

        inFile.close();
    }
    catch (const exception &e)
    {
        cerr << "Blad: " << e.what() << endl;
        return 1;
    }

    return 0;
}
