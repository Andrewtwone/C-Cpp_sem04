#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file;
    char ch;
    int charCount = 0, upperCount = 0, lowerCount = 0, wordCount = 0;
    int minWordLen = 2;
    int inWord = 0, currentWordLen = 0;

    if (argc < 2)
    {
        printf("Uzycie: %s <plik> [minX]\n", argv[0]);
        return 1;
    }

    if (argc == 3 && strncmp(argv[2], "min", 3) == 0)
    {
        minWordLen = atoi(argv[2] + 3);
        if (minWordLen < 1)
        {
            printf("Niepoprawna minimalna dlugosc wyrazu.\n");
            return 2;
        }
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Blad otwarcia pliku");
        return 3;
    }

    while ((ch = fgetc(file)) != EOF)
    {
        charCount++;

        if (isupper(ch))
            upperCount++;
        if (islower(ch))
            lowerCount++;

        if (isalpha(ch))
        {
            inWord = 1;
            currentWordLen++;
        }
        else
        {
            if (inWord && currentWordLen >= minWordLen)
                wordCount++;
            inWord = 0;
            currentWordLen = 0;
        }
    }

    if (inWord && currentWordLen >= minWordLen)
        wordCount++;

    fclose(file);

    printf("Liczba znakow: %d\n", charCount);
    printf("Liczba liter malych: %d\n", lowerCount);
    printf("Liczba liter wielkich: %d\n", upperCount);
    printf("Liczba wyrazow (min %d znaki): %d\n", minWordLen, wordCount);

    return 0;
}
