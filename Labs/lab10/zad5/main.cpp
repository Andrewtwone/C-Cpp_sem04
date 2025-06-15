#include "Figura.h"
#include "Prostokat.h"
#include "Kolo.h"
#include "Kwadrat.h"
#include "Trojkat.h"
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

void wyswietlWszystkieFigury(const std::vector<std::unique_ptr<Figura>>& figury) {
    std::cout << "\nWszystkie figury:" << std::endl;
    std::cout << std::setw(15) << "Nazwa" << std::setw(15) << "Pole" << std::setw(15) << "Obwod" << std::endl;
    std::cout << std::string(45, '-') << std::endl;
    
    for (const auto& figura : figury) {
        std::cout << std::setw(15) << figura->getNazwa()
                  << std::setw(15) << figura->getPole()
                  << std::setw(15) << figura->getObwod() << std::endl;
    }
}

int main() {
    std::cout << "Demonstracja polimorfizmu w klasach geometrycznych" << std::endl;
    std::cout << "================================================" << std::endl;

    std::vector<std::unique_ptr<Figura>> figury;

    // Tworzenie różnych figur
    figury.push_back(std::make_unique<Prostokat>(
        Punkt(0, 0, "LewyGorny1"),
        Punkt(4, 3, "PrawyDolny1"),
        "Prostokat1"
    ));

    figury.push_back(std::make_unique<Kolo>(
        Punkt(0, 0, "Srodek1"),
        5,
        "Kolo1"
    ));

    figury.push_back(std::make_unique<Kwadrat>(
        Punkt(0, 0, "LewyGorny2"),
        4,
        "Kwadrat1"
    ));

    figury.push_back(std::make_unique<Trojkat>(
        Punkt(0, 0, "P1"),
        Punkt(4, 0, "P2"),
        Punkt(2, 3, "P3"),
        "Trojkat1"
    ));

    
    wyswietlWszystkieFigury(figury);

    // Test polimorfizmu na pojedynczej figurze
    std::cout << "\nTest polimorfizmu na pojedynczej figurze:" << std::endl;
    std::cout << "=========================================" << std::endl;
    Figura* figura = figury[0].get();
    figura->wyswietl();

    // Test polimorfizmu na wszystkich figurach
    std::cout << "\nTest polimorfizmu na wszystkich figurach:" << std::endl;
    std::cout << "=========================================" << std::endl;
    for (const auto& figura : figury) {
        figura->wyswietl();
        std::cout << std::endl;
    }

    return 0;
} 