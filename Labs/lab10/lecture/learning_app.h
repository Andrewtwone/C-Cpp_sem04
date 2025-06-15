#ifndef LEARNING_APP_H
#define LEARNING_APP_H

#include <string>
#include <vector>
#include <memory>
#include "file_manager.h"
#include "stats_manager.h"
#include "learning_session.h"

class LearningApp
{
public:
    LearningApp();
    int run(int argc, char *argv[]);

private:
    std::string filename_;
    int intensity_;
    bool showStats_;
    bool showUserStats_;
    bool translateToEnglish_;

    FileManager fileManager_;
    StatsManager statsManager_;

    void printUsage();
    bool parseArguments(int argc, char *argv[]);
};

#endif 