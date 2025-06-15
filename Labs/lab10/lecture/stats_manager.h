#ifndef STATS_MANAGER_H
#define STATS_MANAGER_H

#include <string>
#include <vector>
#include <chrono>
#include "word_struct.h"

struct UserStats {
    std::string firstName;
    std::string lastName;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
    int totalWords;
    int learnedWords;
    // std::vector<std::pair<std::string, std::vector<std::chrono::milliseconds>>> wordTimings; // Optional detailed stats
};

struct LearningStats {
    int totalWords;
    int learnedWords;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point currentTime;
};

class StatsManager
{
public:
    StatsManager();
    void initializeStats(LearningStats& stats, const std::vector<Word>& words);
    void updateStats(LearningStats& stats, const std::string& word, bool correct);
    void displayCurrentStats(const LearningStats& stats);
    void saveUserStats(const UserStats& stats);
    void loadUserStats(std::vector<UserStats>& stats);
    void displayUserStats(const std::vector<UserStats>& stats);

private:
    const std::string USER_STATS_FILE = "user_stats.txt";
};

#endif 