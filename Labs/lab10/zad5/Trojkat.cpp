#include "Trojkat.h"
#include <iostream>
#include <cmath>

Trojkat::Trojkat(const Punkt& p1, const Punkt& p2, const Punkt& p3, const std::string& nazwa)
    : Figura(nazwa) {
    wierzcholki[0] = p1;
    wierzcholki[1] = p2;
    wierzcholki[2] = p3;
    obliczPole();
    obliczObwod();
}

Trojkat::~Trojkat() {
    std::cout << "Destruktor Trojkata" << std::endl;
}

void Trojkat::setNazwa(const std::string& nazwa) {
    Figura::setNazwa(nazwa);
}

void Trojkat::setWierzcholki(const Punkt& p1, const Punkt& p2, const Punkt& p3) {
    wierzcholki[0] = p1;
    wierzcholki[1] = p2;
    wierzcholki[2] = p3;
    obliczPole();
    obliczObwod();
}

Punkt* Trojkat::getWierzcholki() {
    return wierzcholki;
}

void Trojkat::obliczPole() {
    // Using Heron's formula
    double a = std::sqrt(std::pow(wierzcholki[1].getX() - wierzcholki[0].getX(), 2) +
                        std::pow(wierzcholki[1].getY() - wierzcholki[0].getY(), 2));
    double b = std::sqrt(std::pow(wierzcholki[2].getX() - wierzcholki[1].getX(), 2) +
                        std::pow(wierzcholki[2].getY() - wierzcholki[1].getY(), 2));
    double c = std::sqrt(std::pow(wierzcholki[0].getX() - wierzcholki[2].getX(), 2) +
                        std::pow(wierzcholki[0].getY() - wierzcholki[2].getY(), 2));
    
    double s = (a + b + c) / 2;
    setPole(std::sqrt(s * (s - a) * (s - b) * (s - c)));
}

void Trojkat::obliczObwod() {
    double a = std::sqrt(std::pow(wierzcholki[1].getX() - wierzcholki[0].getX(), 2) +
                        std::pow(wierzcholki[1].getY() - wierzcholki[0].getY(), 2));
    double b = std::sqrt(std::pow(wierzcholki[2].getX() - wierzcholki[1].getX(), 2) +
                        std::pow(wierzcholki[2].getY() - wierzcholki[1].getY(), 2));
    double c = std::sqrt(std::pow(wierzcholki[0].getX() - wierzcholki[2].getX(), 2) +
                        std::pow(wierzcholki[0].getY() - wierzcholki[2].getY(), 2));
    
    setObwod(a + b + c);
}

void Trojkat::wyswietl() const {
    std::cout << "Trojkat: " << getNazwa() << std::endl;
    std::cout << "Wierzcholki:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "  (" << wierzcholki[i].getX() << ", " << wierzcholki[i].getY() << ")" << std::endl;
    }
    std::cout << "Pole: " << getPole() << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
} 