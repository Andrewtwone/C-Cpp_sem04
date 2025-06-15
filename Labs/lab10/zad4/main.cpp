#include "Trojkat.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::cout << "Test klasy Trojkat i nadpisywania metod\n";
    std::cout << "=====================================\n\n";

    Punkt p1(0, 0, "P1");
    Punkt p2(4, 0, "P2");
    Punkt p3(0, 3, "P3");

    Punkt p4(1, 1, "P4");
    Punkt p5(5, 1, "P5");
    Punkt p6(1, 4, "P6");

    Trojkat t1(p1, p2, p3, "Trojkat1");
    Trojkat t2(p4, p5, p6, "Trojkat2");

    std::cout << "Pierwszy trojkat:\n";
    t1.wyswietl();
    std::cout << "\n";

    std::cout << "Drugi trojkat:\n";
    t2.wyswietl();
    std::cout << "\n";

    // Test nadpisywania metody setNazwa
    std::cout << "Test nadpisywania metody setNazwa:\n";
    t1.setNazwa("NowaNazwa1");
    t2.setNazwa("NowaNazwa2");

    std::cout << "\nTrojkaty po zmianie nazwy:\n";
    t1.wyswietl();
    std::cout << "\n";
    t2.wyswietl();

    return 0;
} 