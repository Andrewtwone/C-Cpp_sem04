#include "learn_utils.h"
#include "file_utils.h"
#include "stats_utils.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <limits>
#include <string>

extern void clearScreen();

void learnWords(std::vector<Word> &words, int intensity, bool translateToEnglish,
                bool showStats, LearningStats &stats)
{
    srand(static_cast<unsigned>(time(nullptr)));

    while (!words.empty())
    {
        clearScreen();

        int idx = rand() % words.size();
        Word &w = words[idx];

        std::cout << "\033[1;1H";
        std::cout << "\033[2K";
        std::cout << "\033[1;33m" << "Podaj tłumaczenie: ";
        if (translateToEnglish)
        {
            std::cout << w.polish;
        }
        else
        {
            std::cout << w.english[0];
        }
        std::cout << "\033[0m";

        std::cout << "\033[2;1H";
        std::cout << "\033[2K";
        std::cout << "-> ";
        std::cout.flush();

        std::string answer;
        auto startTime = std::chrono::system_clock::now();
        std::getline(std::cin, answer);
        auto endTime = std::chrono::system_clock::now();

        answer.erase(0, answer.find_first_not_of(" \t\r\n"));
        answer.erase(answer.find_last_not_of(" \t\r\n") + 1);

        // Check answer
        bool correct;
        if (translateToEnglish)
        {
            correct = std::any_of(w.english.begin(), w.english.end(),
                                  [&](const std::string &e)
                                  { return answer == e; });
        }
        else
        {
            correct = answer == w.polish;
        }

        std::cout << "\033[2;1H";
        std::cout << "\033[2K";
        if (correct)
        {
            std::cout << "\033[1;32m" << "Poprawnie!" << "\033[0m";
            w.correctCount++;
        }
        else
        {
            std::cout << "\033[1;31m" << "Błąd. Poprawne odpowiedzi: ";
            if (translateToEnglish)
            {
                for (const auto &e : w.english)
                    std::cout << e << " ";
            }
            else
            {
                std::cout << w.polish;
            }
            std::cout << "\033[0m";
        }
        std::cout.flush();

        // Update statistics
        updateStats(stats, w.polish, correct);
        if (showStats)
        {
            std::cout << "\033[3;1H";
            std::cout << "\033[2K";
            displayCurrentStats(stats);
            std::cout.flush();
        }

        // Remove word if learned enough times
        if (w.correctCount >= intensity)
        {
            words.erase(words.begin() + idx);
        }

        std::cout << "\033[5;1H";
        std::cout << "\033[2K";
        std::cout << "Naciśnij Enter aby kontynuować...";
        std::cout.flush();

        std::string dummy;
        std::getline(std::cin, dummy);
    }

    clearScreen();
    std::cout << "\033[1;32m" << "Ukończono naukę zestawu słów!" << "\033[0m" << std::endl;
}
