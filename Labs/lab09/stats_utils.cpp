#include "stats_utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

void initializeStats(LearningStats& stats, const std::vector<Word>& words) {
    stats.totalWords = words.size();
    stats.learnedWords = 0;
    stats.startTime = std::chrono::system_clock::now();
    stats.currentTime = stats.startTime;
}

void updateStats(LearningStats& stats, const std::string& word, bool correct) {
    stats.currentTime = std::chrono::system_clock::now();
    if (correct) {
        stats.learnedWords++;
    }
}

void displayCurrentStats(const LearningStats& stats) {
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(
        stats.currentTime - stats.startTime);
    
    int hours = duration.count() / 3600;
    int minutes = (duration.count() % 3600) / 60;
    int seconds = duration.count() % 60;

    std::cout << "\033[1;33m" << "Status: " << "\033[0m";
    std::cout << "Nauczono się " << stats.learnedWords << " z " << stats.totalWords << " słów, ";
    std::cout << "czas nauki: " << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
    std::cout.flush();
}

void saveUserStats(const UserStats& stats) {
    std::ofstream file("user_stats.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Błąd otwarcia pliku statystyk!" << std::endl;
        return;
    }

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(
        stats.endTime - stats.startTime);

    file << stats.firstName << " " << stats.lastName << " "
         << std::chrono::system_clock::to_time_t(stats.startTime) << " "
         << duration.count() << " "
         << stats.totalWords << " "
         << stats.learnedWords << "\n";

    file.close();
}

void loadUserStats(std::vector<UserStats>& stats) {
    std::ifstream file("user_stats.txt");
    if (!file.is_open()) {
        return;
    }

    UserStats stat;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> stat.firstName >> stat.lastName;
        
        time_t startTime;
        iss >> startTime;
        stat.startTime = std::chrono::system_clock::from_time_t(startTime);
        
        int duration;
        iss >> duration;
        stat.endTime = stat.startTime + std::chrono::seconds(duration);
        
        iss >> stat.totalWords >> stat.learnedWords;
        stats.push_back(stat);
    }
}

void displayUserStats(const std::vector<UserStats>& stats) {
    std::cout << "\033[1;33m" << "Statystyki użytkowników:" << "\033[0m" << std::endl;
    for (const auto& stat : stats) {
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(
            stat.endTime - stat.startTime);
        
        std::cout << stat.firstName << " " << stat.lastName << " - "
                  << "Nauczono " << stat.learnedWords << " z " << stat.totalWords << " słów, "
                  << "czas: " << duration.count() / 3600 << "h "
                  << (duration.count() % 3600) / 60 << "m "
                  << duration.count() % 60 << "s" << std::endl;
    }
} 