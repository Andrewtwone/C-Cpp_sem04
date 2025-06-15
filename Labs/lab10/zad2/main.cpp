#include "Prostokat.h"
#include "Kolo.h"
#include "Kwadrat.h"
#include <iostream>

int main() {
    std::cout << "Test klas figur geometrycznych\n";
    std::cout << "===========================\n\n";

    // Test prostokata
    std::cout << "Test prostokata:\n";
    Punkt lg(0, 5, "LewyGorny");
    Punkt pd(4, 0, "PrawyDolny");
    Prostokat p1(lg, pd, "Prostokat1");
    p1.wyswietl();
    std::cout << "\n";

    // Test kola
    std::cout << "Test kola:\n";
    Punkt srodek(0, 0, "Srodek");
    Kolo k1(srodek, 5, "Kolo1");
    k1.wyswietl();
    std::cout << "\n";

    // Test kwadratu
    std::cout << "Test kwadratu:\n";
    Punkt lg2(0, 4, "LewyGorny");
    Kwadrat kw1(lg2, 4, "Kwadrat1");
    kw1.wyswietl();
    std::cout << "\n";

    return 0;
} 