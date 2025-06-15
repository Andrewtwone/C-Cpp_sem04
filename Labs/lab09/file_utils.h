#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

using namespace std;

struct Word
{
    string polish;
    vector<string> english;
    int correctCount;
};

bool loadWordsFromFile(const string &filename, vector<Word> &words);
void showFileFormatError();

#endif
