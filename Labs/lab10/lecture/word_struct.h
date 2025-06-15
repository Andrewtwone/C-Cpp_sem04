#ifndef WORD_STRUCT_H
#define WORD_STRUCT_H

#include <string>
#include <vector>

struct Word
{
    std::string polish;
    std::vector<std::string> english;
    int correctCount;
};

#endif 