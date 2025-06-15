#include "Prostokat.h"
#include "Kolo.h"
#include "Kwadrat.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::cout << "Test hierarchii klas figur geometrycznych\n";
    std::cout << "=======================================\n\n";

    
    std::vector<std::unique_ptr<Figura>> figury;

    // Dodawanie prostokatow
    Punkt lg1(0, 5, "LewyGorny1");
    Punkt pd1(4, 0, "PrawyDolny1");
    figury.push_back(std::make_unique<Prostokat>(lg1, pd1, "Prostokat1"));

    Punkt lg2(1, 6, "LewyGorny2");
    Punkt pd2(5, 1, "PrawyDolny2");
    figury.push_back(std::make_unique<Prostokat>(lg2, pd2, "Prostokat2"));

    // Dodawanie kol
    Punkt srodek1(0, 0, "Srodek1");
    figury.push_back(std::make_unique<Kolo>(srodek1, 5, "Kolo1"));

    Punkt srodek2(2, 2, "Srodek2");
    figury.push_back(std::make_unique<Kolo>(srodek2, 3, "Kolo2"));

    // Dodawanie kwadratow
    Punkt lg3(0, 4, "LewyGorny3");
    figury.push_back(std::make_unique<Kwadrat>(lg3, 4, "Kwadrat1"));

    Punkt lg4(1, 5, "LewyGorny4");
    figury.push_back(std::make_unique<Kwadrat>(lg4, 3, "Kwadrat2"));

    
    std::cout << "Wszystkie figury:\n";
    for (const auto& figura : figury) {
        figura->wyswietl();
        std::cout << "\n";
    }

    return 0;
} 