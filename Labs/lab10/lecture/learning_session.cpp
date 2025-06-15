#include "learning_session.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <string>

void LearningSession::clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

LearningSession::LearningSession(std::vector<Word> &words, int intensity, bool translateToEnglish, bool showStats, StatsManager &statsManager)
    : words_(words),
      intensity_(intensity),
      translateToEnglish_(translateToEnglish),
      showStats_(showStats),
      statsManager_(statsManager)
{
    statsManager_.initializeStats(currentLearningStats_, words_);
}

const LearningStats &LearningSession::getLearningStats() const
{
    return currentLearningStats_;
}

void LearningSession::startLearning()
{
    std::random_device rd;
    std::mt19937 g(rd());

    while (!words_.empty())
    {
        clearScreen();

        int idx = rand() % words_.size();
        Word &w = words_[idx];

        std::cout << "\033[1;1H";
        std::cout << "\033[2K";
        std::cout << "\033[1;33m" << "Podaj tłumaczenie: ";
        if (translateToEnglish_)
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

        bool correct;
        if (translateToEnglish_)
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
            if (translateToEnglish_)
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

        statsManager_.updateStats(currentLearningStats_, w.polish, correct);
        if (showStats_)
        {
            std::cout << "\033[3;1H";
            std::cout << "\033[2K";
            statsManager_.displayCurrentStats(currentLearningStats_);
            std::cout.flush();
        }

        if (w.correctCount >= intensity_)
        {
            words_.erase(words_.begin() + idx);
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