#include "Prostokat.h"
#include <iostream>
#include <cmath>

Prostokat::Prostokat(const Punkt& lg, const Punkt& pd, const std::string& nazwa)
    : Figura(nazwa), lewyGorny(lg), prawyDolny(pd) {
    obliczPole();
    obliczObwod();
}

Prostokat::~Prostokat() {
    std::cout << "Destruktor Prostokata" << std::endl;
}

void Prostokat::setNazwa(const std::string& nazwa) {
    Figura::setNazwa(nazwa);
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
    setPole(szerokosc * wysokosc);
}

void Prostokat::obliczObwod() {
    double szerokosc = std::abs(prawyDolny.getX() - lewyGorny.getX());
    double wysokosc = std::abs(lewyGorny.getY() - prawyDolny.getY());
    setObwod(2 * (szerokosc + wysokosc));
}

void Prostokat::wyswietl() const {
    std::cout << "Prostokat: " << getNazwa() << std::endl;
    std::cout << "Lewy gorny: (" << lewyGorny.getX() << ", " << lewyGorny.getY() << ")" << std::endl;
    std::cout << "Prawy dolny: (" << prawyDolny.getX() << ", " << prawyDolny.getY() << ")" << std::endl;
    std::cout << "Pole: " << getPole() << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
} 