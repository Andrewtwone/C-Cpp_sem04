#ifndef LEARNING_SESSION_H
#define LEARNING_SESSION_H

#include <vector>
#include <string>
#include "word_struct.h"
#include "stats_manager.h"

class LearningSession
{
public:
    LearningSession(std::vector<Word>& words, int intensity, bool translateToEnglish, bool showStats, StatsManager& statsManager);
    void startLearning();
    const LearningStats& getLearningStats() const;

private:
    std::vector<Word>& words_;
    int intensity_;
    bool translateToEnglish_;
    bool showStats_;
    StatsManager& statsManager_;
    LearningStats currentLearningStats_;

    void clearScreen();
    void displayWord(const Word& word);
    bool checkAnswer(const Word& word, const std::string& answer);
};

#endif 