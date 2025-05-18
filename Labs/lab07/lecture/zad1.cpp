#include <iostream>
#include <string>
using namespace std;

void znajdzNajdluzszy(const string tab[], int n, int &indeks, int &dlugosc, string &napis)
{
    indeks = 0;
    dlugosc = 0;

    for (int i = 0; i < n; i++)
    {
        int lokalna_dlugosc = 0;

        for (char znak : tab[i])
        {
            lokalna_dlugosc++;
        }

        if (lokalna_dlugosc > dlugosc)
        {
            dlugosc = lokalna_dlugosc;
            indeks = i;
            napis = tab[i];
        }
    }
}

int main()
{
    const string TAB[] = {
        "Litwo! Ojczyzno moja! ty jesteś jak zdrowie:", "Ile cię trzeba cenić, ten tylko się dowie",
        "Kto cię stracił. Dziś piękność twą w całej ozdobie", "Widzę i opisuję, bo tęsknię po tobie.",
        "Panno święta, co Jasnej bronisz Częstochowy", "I w Ostrej świecisz Bramie! Ty, co gród zamkowy",
        "Nowogródzki ochraniasz z jego wiernym ludem!", "Jak mnie dziecko do zdrowia powróciłaś cudem",
        "(Gdy od płaczącej matki, pod Twoją opiekę", "Ofiarowany, martwą podniosłem powiekę;",
        "I zaraz mogłem pieszo, do Twych świątyń progu", "Iść za wrócone życie podziękować Bogu),",
        "Tak nas powrócisz cudem na Ojczyzny łono.", "Tymczasem przenoś moją duszę utęsknioną",
        "Do tych pagórków leśnych, do tych łąk zielonych,", "Szeroko nad błękitnym Niemnem rozciągnionych;",
        "Do tych pól malowanych zbożem rozmaitem,", "Wyzłacanych pszenicą, posrebrzanych żytem;",
        "Gdzie bursztynowy świerzop, gryka jak śnieg biała,", "Gdzie panieńskim rumieńcem dzięcielina pała,",
        "A wszystko przepasane jakby wstęgą, miedzą", "Zieloną, na niej z rzadka ciche grusze siedzą.",
        "Właśnie dwukonną bryką wjechał młody panek", "I obiegłszy dziedziniec zawrócił przed ganek",
        "Wysiadł z powozu; konie porzucone same", "Zaszczepkami i kołkiem zaszczepki przetknięto",
        "Szczypiąc trawę ciągnęły powoli pod bramę", "Podróżny do folwarku nie biegł sług zapytać",
        "We dworze pusto: bo drzwi od ganku zamknięto", "Odemknął, wbiegł do domu, pragnął go powitać"};

    int index, length;
    string najdluzszy;

    znajdzNajdluzszy(TAB, sizeof(TAB) / sizeof(TAB[0]), index, length, najdluzszy);

    cout << "Najdluzszy napis to: \"" << najdluzszy << "\"\n";
    cout << "Index: " << index << "\n";
    cout << "Dlugosc: " << length << "\n";

    return 0;
}
