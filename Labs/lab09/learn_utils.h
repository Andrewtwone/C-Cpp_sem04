#ifndef LEARN_UTILS_H
#define LEARN_UTILS_H

#include <vector>
#include <string>
#include "file_utils.h"
#include "stats_utils.h"

using namespace std;

struct Word;

void learnWords(std::vector<Word>& words, int intensity, bool translateToEnglish, 
                bool showStats, LearningStats& stats);

#endif
