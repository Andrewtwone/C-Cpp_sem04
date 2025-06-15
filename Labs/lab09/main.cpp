#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "file_utils.h"
#include "learn_utils.h"
#include "stats_utils.h"

using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void printUsage()
{
    cerr << "Użycie: ./program [opcje]\n"
         << "Opcje:\n"
         << "  -f <plik>     Plik ze słówkami\n"
         << "  -i <liczba>   Poziom intensywności\n"
         << "  -s            Pokaż statystyki nauki\n"
         << "  -r            Pokaż statystyki użytkowników\n"
         << "  -en           Tłumacz z angielskiego na polski\n"
         << "  -pl           Tłumacz z polskiego na angielski\n";
}

int main(int argc, char *argv[])
{
    string filename;
    int intensity = 3;
    bool showStats = false;
    bool showUserStats = false;
    bool translateToEnglish = true; // default: PL->EN

    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if (arg == "-f" && i + 1 < argc)
        {
            filename = argv[++i];
        }
        else if (arg == "-i" && i + 1 < argc)
        {
            try
            {
                intensity = stoi(argv[++i]);
                if (intensity <= 0)
                    throw invalid_argument("Intensywność musi być dodatnia");
            }
            catch (...)
            {
                cerr << "Błędna wartość intensywności!" << endl;
                return 1;
            }
        }
        else if (arg == "-s")
        {
            showStats = true;
        }
        else if (arg == "-r")
        {
            showUserStats = true;
        }
        else if (arg == "-en")
        {
            translateToEnglish = false;
        }
        else if (arg == "-pl")
        {
            translateToEnglish = true;
        }
    }

    if (filename.empty())
    {
        printUsage();
        return 1;
    }

    if (showUserStats)
    {
        vector<UserStats> stats;
        loadUserStats(stats);
        displayUserStats(stats);
        return 0;
    }

    vector<Word> words;
    if (!loadWordsFromFile(filename, words))
    {
        return 1;
    }

    clearScreen();
    LearningStats learningStats;
    initializeStats(learningStats, words);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    UserStats userStats;
    cout << "\033[1;33m" << "Podaj swoje imię: " << "\033[0m";
    getline(cin, userStats.firstName);
    cout << "\033[1;33m" << "Podaj swoje nazwisko: " << "\033[0m";
    getline(cin, userStats.lastName);
    userStats.startTime = chrono::system_clock::now();
    userStats.totalWords = words.size();
    userStats.learnedWords = 0;

    learnWords(words, intensity, translateToEnglish, showStats, learningStats);

    userStats.endTime = chrono::system_clock::now();
    userStats.learnedWords = learningStats.learnedWords;
    saveUserStats(userStats);

    return 0;
}
