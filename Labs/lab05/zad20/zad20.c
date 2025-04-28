#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char to_remove;
    int i, j;

    printf("Podaj napis: ");
    fgets(text, sizeof(text), stdin);

    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    printf("Podaj znak do usuniecia: ");
    scanf(" %c", &to_remove);

    for (i = 0, j = 0; text[i] != '\0'; i++) {
        if (text[i] != to_remove) {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';

    printf("\nNapis po usunieciu znaku '%c': %s\n", to_remove, text);

    printf("\nMapa pamieci tablicy:\n");
    for (i = 0; i < sizeof(text); i++) {
        if (text[i] == '\0') {
            printf("! ");
        } else {
            printf("x ");
        }
    }
    printf("\n");

    return 0;
}
