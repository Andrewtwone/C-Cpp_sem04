#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Config
{
    string filename;
    int maxWidth = 50;
    string mode = "both";
    string outputFile = "";
};

void printHelp()
{
    cout << "Uzycie: ./zad2 --file plik.txt --width 40 --mode both [--out wynik.txt]\n";
    cout << "Tryby: count (tylko liczby), hist (tylko histogram), both (domyslnie)\n";
}

Config parseArguments(int argc, char *argv[])
{
    Config cfg;
    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if ((arg == "--file" || arg == "-f") && i + 1 < argc)
        {
            cfg.filename = argv[++i];
        }
        else if ((arg == "--width" || arg == "-w") && i + 1 < argc)
        {
            cfg.maxWidth = stoi(argv[++i]);
        }
        else if ((arg == "--mode" || arg == "-m") && i + 1 < argc)
        {
            cfg.mode = argv[++i];
        }
        else if ((arg == "--out") && i + 1 < argc)
        {
            cfg.outputFile = argv[++i];
        }
        else
        {
            throw invalid_argument("Nieznany lub niekompletny argument: " + arg);
        }
    }

    if (cfg.filename.empty())
        throw invalid_argument("Nie podano pliku wejsciowego.");
    if (cfg.maxWidth <= 0)
        throw invalid_argument("Szerokosc histogramu musi byc > 0.");
    if (cfg.mode != "count" && cfg.mode != "hist" && cfg.mode != "both")
        throw invalid_argument("Nieprawidlowy tryb wyswietlania.");

    return cfg;
}

vector<int> analyzeDigits(const string &filename)
{
    ifstream file(filename);
    if (!file)
        throw runtime_error("Nie mozna otworzyc pliku.");

    vector<int> counts(10, 0);
    char ch;
    while (file >> ch)
    {
        if (isdigit(ch))
            counts[ch - '0']++;
    }
    return counts;
}

void outputResult(const vector<int> &counts, int maxWidth, const string &mode, ostream &out)
{
    int maxCount = *max_element(counts.begin(), counts.end());

    for (int i = 0; i < 10; ++i)
    {
        out << i << ": ";
        if (mode != "hist")
            out << setw(5) << counts[i];
        if (mode != "count")
            out << " " << string((maxCount ? counts[i] * maxWidth / maxCount : 0), '*');
        out << "\n";
    }
}

int main(int argc, char *argv[])
{
    try
    {
        Config cfg = parseArguments(argc, argv);
        vector<int> digitCounts = analyzeDigits(cfg.filename);

        if (!cfg.outputFile.empty())
        {
            ofstream out(cfg.outputFile);
            outputResult(digitCounts, cfg.maxWidth, cfg.mode, out);
            cout << "Wynik zapisano do pliku: " << cfg.outputFile << endl;
        }
        else
        {
            outputResult(digitCounts, cfg.maxWidth, cfg.mode, cout);
        }
    }
    catch (exception &e)
    {
        cerr << "Blad: " << e.what() << "\n";
        printHelp();
        return 1;
    }

    return 0;
}
