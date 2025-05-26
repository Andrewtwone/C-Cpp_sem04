#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[100];
    FILE *file;
    char ch;

    printf("Podaj nazwe pliku: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Blad otwarcia pliku");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
