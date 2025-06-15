#include "learning_app.h"
#include <iostream>
#include <limits>
#include <stdexcept>

LearningApp::LearningApp()
    : intensity_(3),
      showStats_(false),
      showUserStats_(false),
      translateToEnglish_(true) // Default: PL->EN
{
}

void LearningApp::printUsage()
{
    std::cerr << "Użycie: ./program [opcje]\n"
              << "Opcje:\n"
              << "  -f <plik>     Plik ze słówkami\n"
              << "  -i <liczba>   Poziom intensywności\n"
              << "  -s            Pokaż statystyki nauki\n"
              << "  -r            Pokaż statystyki użytkowników\n"
              << "  -en           Tłumacz z angielskiego na polski\n"
              << "  -pl           Tłumacz z polskiego na angielski\n";
}

bool LearningApp::parseArguments(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg == "-f" && i + 1 < argc)
        {
            filename_ = argv[++i];
        }
        else if (arg == "-i" && i + 1 < argc)
        {
            try
            {
                intensity_ = std::stoi(argv[++i]);
                if (intensity_ <= 0)
                    throw std::invalid_argument("Intensywność musi być dodatnia");
            }
            catch (const std::exception &e)
            {
                std::cerr << "Błędna wartość intensywności: " << e.what() << std::endl;
                return false;
            }
        }
        else if (arg == "-s")
        {
            showStats_ = true;
        }
        else if (arg == "-r")
        {
            showUserStats_ = true;
        }
        else if (arg == "-en")
        {
            translateToEnglish_ = false;
        }
        else if (arg == "-pl")
        {
            translateToEnglish_ = true;
        }
        else
        {
            std::cerr << "Nieznana opcja: " << arg << std::endl;
            printUsage();
            return false;
        }
    }

    if (filename_.empty() && !showUserStats_)
    {
        printUsage();
        return false;
    }
    return true;
}

int LearningApp::run(int argc, char *argv[])
{
    if (!parseArguments(argc, argv))
    {
        return 1;
    }

    if (showUserStats_)
    {
        std::vector<UserStats> stats;
        statsManager_.loadUserStats(stats);
        statsManager_.displayUserStats(stats);
        return 0;
    }

    std::vector<Word> words;
    if (!fileManager_.loadWordsFromFile(filename_, words))
    {
        return 1;
    }

    UserStats userStats;
    std::cout << "\033[1;33m" << "Podaj swoje imię: " << "\033[0m";
    std::getline(std::cin, userStats.firstName);
    std::cout << "\033[1;33m" << "Podaj swoje nazwisko: " << "\033[0m";
    std::getline(std::cin, userStats.lastName);
    userStats.startTime = std::chrono::system_clock::now();
    userStats.totalWords = words.size();
    userStats.learnedWords = 0;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    LearningSession session(words, intensity_, translateToEnglish_, showStats_, statsManager_);
    session.startLearning();

    userStats.endTime = std::chrono::system_clock::now();
    userStats.learnedWords = session.getLearningStats().learnedWords;
    statsManager_.saveUserStats(userStats);

    return 0;
}