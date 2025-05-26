#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream file("wiersze.txt");
    if (!file.is_open())
    {
        cerr << "Nie mozna otworzyc pliku." << endl;
        return 1;
    }

    vector<string *> lines;
    string line;

    while (getline(file, line))
    {
        string *ptr = new string(line);
        lines.push_back(ptr);
    }

    file.close();

    cout << "\nZawartosc pliku:\n";
    for (const auto &ptr : lines)
    {
        cout << *ptr << endl;
    }

    for (auto ptr : lines)
        delete ptr;

    return 0;
}
