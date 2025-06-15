#include "Punkt.h"
#include <vector>
#include <iostream>
#include <string>

int main() {
    std::vector<Punkt> figura;
    double x, y;
    std::string nazwa;
    char wybor;

    std::cout << "Program do tworzenia figury z punktow\n";
    std::cout << "====================================\n\n";

    do {
        std::cout << "Podaj wspolrzedne punktu:\n";
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
        std::cout << "Nazwa punktu: ";
        std::cin >> nazwa;

        figura.push_back(Punkt(x, y, nazwa));

        std::cout << "\nCzy chcesz dodac kolejny punkt? (t/n): ";
        std::cin >> wybor;
        std::cout << "\n";
    } while (wybor == 't' || wybor == 'T');

    std::cout << "\nUtworzona figura:\n";
    for (const auto& punkt : figura) {
        punkt.wyswietl();
    }

    return 0;
} 