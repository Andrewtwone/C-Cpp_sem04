#include "Kwadrat.h"
#include <iostream>
#include <cmath>

Kwadrat::Kwadrat(const Punkt& lg, double bok, const std::string& nazwa)
    : Figura(nazwa), lewyGorny(lg), bok(bok) {
    obliczPole();
    obliczObwod();
}

Kwadrat::~Kwadrat() {
    std::cout << "Destruktor Kwadratu" << std::endl;
}

void Kwadrat::setNazwa(const std::string& nazwa) {
    Figura::setNazwa(nazwa);
}

void Kwadrat::setPunkt(const Punkt& lg) {
    lewyGorny = lg;
}

void Kwadrat::setBok(double bok) {
    this->bok = bok;
    obliczPole();
    obliczObwod();
}

Punkt Kwadrat::getLewyGorny() const {
    return lewyGorny;
}

double Kwadrat::getBok() const {
    return bok;
}

void Kwadrat::obliczPole() {
    setPole(bok * bok);
}

void Kwadrat::obliczObwod() {
    setObwod(4 * bok);
}

void Kwadrat::wyswietl() const {
    std::cout << "Kwadrat: " << getNazwa() << std::endl;
    std::cout << "Lewy gorny: (" << lewyGorny.getX() << ", " << lewyGorny.getY() << ")" << std::endl;
    std::cout << "Bok: " << bok << std::endl;
    std::cout << "Pole: " << getPole() << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
} 