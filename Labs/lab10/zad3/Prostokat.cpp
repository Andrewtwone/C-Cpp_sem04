#include "Prostokat.h"
#include <iostream>
#include <cmath>

Prostokat::Prostokat() : Figura("Prostokat"), lewyGorny(), prawyDolny() {
    std::cout << "Konstruktor domyslny Prostokata" << std::endl;
}

Prostokat::Prostokat(const Punkt& lg, const Punkt& pd) 
    : Figura("Prostokat"), lewyGorny(lg), prawyDolny(pd) {
    std::cout << "Konstruktor z punktami Prostokata" << std::endl;
    obliczPole();
    obliczObwod();
}

Prostokat::Prostokat(const Punkt& lg, const Punkt& pd, const std::string& nazwa)
    : Figura(nazwa), lewyGorny(lg), prawyDolny(pd) {
    std::cout << "Konstruktor z punktami i nazwa Prostokata" << std::endl;
    obliczPole();
    obliczObwod();
}

Prostokat::~Prostokat() {
    std::cout << "Destruktor Prostokata" << std::endl;
}

void Prostokat::setPunkty(const Punkt& lg, const Punkt& pd) {
    lewyGorny = lg;
    prawyDolny = pd;
    obliczPole();
    obliczObwod();
}

Punkt Prostokat::getLewyGorny() const {
    return lewyGorny;
}

Punkt Prostokat::getPrawyDolny() const {
    return prawyDolny;
}

void Prostokat::obliczPole() {
    double szerokosc = std::abs(prawyDolny.getX() - lewyGorny.getX());
    double wysokosc = std::abs(lewyGorny.getY() - prawyDolny.getY());
    pole = szerokosc * wysokosc;
}

void Prostokat::obliczObwod() {
    double szerokosc = std::abs(prawyDolny.getX() - lewyGorny.getX());
    double wysokosc = std::abs(lewyGorny.getY() - prawyDolny.getY());
    obwod = 2 * (szerokosc + wysokosc);
}

void Prostokat::wyswietl() const {
    std::cout << "Prostokat: " << nazwa << std::endl;
    std::cout << "Lewy gorny: ";
    lewyGorny.wyswietl();
    std::cout << "Prawy dolny: ";
    prawyDolny.wyswietl();
    std::cout << "Pole: " << pole << std::endl;
    std::cout << "Obwod: " << obwod << std::endl;
} 