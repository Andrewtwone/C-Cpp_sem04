#include "file_manager.h"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

FileManager::FileManager() {}

std::string FileManager::trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

bool FileManager::validateFileFormat(std::ifstream &file) {
    std::string line;
    int lineCount = 0;
    
    
    while (std::getline(file, line)) {
        lineCount++;
        if (lineCount >= 5) break;
    }
    
    if (lineCount < 5) {
        std::cerr << "Plik jest za krótki. Wymagane minimum 5 linii (4 nagłówkowe + 1 para słów)." << std::endl;
        return false;
    }
    
    
    file.clear();
    file.seekg(0);
    
    for (int i = 0; i < 4; i++) {
        std::getline(file, line);
    }
    
    
    while (std::getline(file, line)) {
        if (trim(line).empty()) {
            std::cerr << "Błąd: pusta linia w pliku (słowo polskie)." << std::endl;
            return false;
        }
        
        if (!std::getline(file, line)) {
            std::cerr << "Błąd: nieparzysta liczba linii w pliku (brak słowa angielskiego)." << std::endl;
            return false;
        }
        
        
        std::istringstream iss(line);
        std::string token;
        bool hasAnyEnglishWord = false;
        while (std::getline(iss, token, ',')) {
            token = trim(token);
            if (!token.empty()) {
                hasAnyEnglishWord = true;
            }
        }
        if (!hasAnyEnglishWord) {
            std::cerr << "Błąd: linia angielskich słów jest pusta lub zawiera tylko puste wpisy." << std::endl;
            return false;
        }
    }
    
    
    file.clear();
    file.seekg(0);
    return true;
}

bool FileManager::loadWordsFromFile(const std::string &filename, std::vector<Word> &words) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Błąd otwarcia pliku!" << std::endl;
        return false;
    }

    if (!validateFileFormat(file)) {
        return false;
    }

    std::string line;
    for (int i = 0; i < 4; i++) {
        std::getline(file, line);
    }

    while (std::getline(file, line)) {
        Word w;
        w.polish = trim(line);
        w.correctCount = 0;

        if (!std::getline(file, line)) {
            showFileFormatError();
            return false;
        }

        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, ',')) {
            token = trim(token);
            if (!token.empty()) {
                w.english.push_back(token);
            }
        }

        if (w.english.empty()) {
            showFileFormatError();
            return false;
        }

        words.push_back(w);
    }

    file.close();
    return true;
}

void FileManager::showFileFormatError() {
    std::cerr << "Nieprawidłowy format pliku. Upewnij się, że:\n"
         << "1. Plik ma minimum 5 linii (4 nagłówkowe + 1 para słów)\n"
         << "2. Słowa angielskie są oddzielone przecinkami\n"
         << "3. Każda para słów składa się z dwóch linii\n"
         << "4. Nie ma pustych linii między parami słów" << std::endl;
} 