#include "Trojkat.h"
#include <iostream>
#include <cmath>

Trojkat::Trojkat(const Punkt& p1, const Punkt& p2, const Punkt& p3, const std::string& nazwa)
    : Figura(nazwa) {
    std::cout << "Konstruktor Trojkata" << std::endl;
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
    if (!nazwa.empty()) {
        this->nazwa = "Trojkat " + nazwa;
    }
}

void Trojkat::setWierzcholki(const Punkt& p1, const Punkt& p2, const Punkt& p3) {
    wierzcholki[0] = p1;
    wierzcholki[1] = p2;
    wierzcholki[2] = p3;
    obliczPole();
    obliczObwod();
}

std::array<Punkt, 3> Trojkat::getWierzcholki() const {
    return wierzcholki;
}

void Trojkat::obliczPole() {
    // Wykorzystanie wzoru Herona
    double a = std::sqrt(std::pow(wierzcholki[1].getX() - wierzcholki[0].getX(), 2) +
                        std::pow(wierzcholki[1].getY() - wierzcholki[0].getY(), 2));
    double b = std::sqrt(std::pow(wierzcholki[2].getX() - wierzcholki[1].getX(), 2) +
                        std::pow(wierzcholki[2].getY() - wierzcholki[1].getY(), 2));
    double c = std::sqrt(std::pow(wierzcholki[0].getX() - wierzcholki[2].getX(), 2) +
                        std::pow(wierzcholki[0].getY() - wierzcholki[2].getY(), 2));
    
    double p = (a + b + c) / 2; // polowa obwodu
    pole = std::sqrt(p * (p - a) * (p - b) * (p - c));
}

void Trojkat::obliczObwod() {
    double a = std::sqrt(std::pow(wierzcholki[1].getX() - wierzcholki[0].getX(), 2) +
                        std::pow(wierzcholki[1].getY() - wierzcholki[0].getY(), 2));
    double b = std::sqrt(std::pow(wierzcholki[2].getX() - wierzcholki[1].getX(), 2) +
                        std::pow(wierzcholki[2].getY() - wierzcholki[1].getY(), 2));
    double c = std::sqrt(std::pow(wierzcholki[0].getX() - wierzcholki[2].getX(), 2) +
                        std::pow(wierzcholki[0].getY() - wierzcholki[2].getY(), 2));
    
    obwod = a + b + c;
}

void Trojkat::wyswietl() const {
    std::cout << "Trojkat: " << nazwa << std::endl;
    std::cout << "Wierzcholki:\n";
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "Punkt " << (i + 1) << ": ";
        wierzcholki[i].wyswietl();
    }
    std::cout << "Pole: " << pole << std::endl;
    std::cout << "Obwod: " << obwod << std::endl;
} 