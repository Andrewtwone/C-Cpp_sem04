#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include "word_struct.h"

class FileManager
{
public:
    FileManager();
    bool loadWordsFromFile(const std::string &filename, std::vector<Word> &words);

private:
    static std::string trim(const std::string &str);
    bool validateFileFormat(std::ifstream &file);
    void showFileFormatError();
};

#endif 