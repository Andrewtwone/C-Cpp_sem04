#include "Kwadrat.h"
#include <iostream>
#include <cmath>

Kwadrat::Kwadrat() : nazwa("Kwadrat"), lewyGorny(), bok(0), pole(0), obwod(0) {
    std::cout << "Konstruktor domyslny Kwadratu" << std::endl;
}

Kwadrat::Kwadrat(const Punkt& lg, double bok) 
    : nazwa("Kwadrat"), lewyGorny(lg), bok(bok) {
    std::cout << "Konstruktor z punktem i bokeim Kwadratu" << std::endl;
    obliczPole();
    obliczObwod();
}

Kwadrat::Kwadrat(const Punkt& lg, double bok, const std::string& nazwa)
    : nazwa(nazwa), lewyGorny(lg), bok(bok) {
    std::cout << "Konstruktor z punktem, bokeim i nazwa Kwadratu" << std::endl;
    obliczPole();
    obliczObwod();
}

Kwadrat::~Kwadrat() {
    std::cout << "Destruktor Kwadratu" << std::endl;
}

void Kwadrat::setNazwa(const std::string& nazwa) {
    if (!nazwa.empty()) {
        this->nazwa = nazwa;
    }
}

void Kwadrat::setPunkt(const Punkt& lg) {
    lewyGorny = lg;
}

void Kwadrat::setBok(double bok) {
    if (bok > 0) {
        this->bok = bok;
        obliczPole();
        obliczObwod();
    }
}

std::string Kwadrat::getNazwa() const {
    return nazwa;
}

double Kwadrat::getPole() const {
    return pole;
}

double Kwadrat::getObwod() const {
    return obwod;
}

Punkt Kwadrat::getLewyGorny() const {
    return lewyGorny;
}

double Kwadrat::getBok() const {
    return bok;
}

void Kwadrat::obliczPole() {
    pole = bok * bok;
}

void Kwadrat::obliczObwod() {
    obwod = 4 * bok;
}

void Kwadrat::wyswietl() const {
    std::cout << "Kwadrat: " << nazwa << std::endl;
    std::cout << "Lewy gorny: ";
    lewyGorny.wyswietl();
    std::cout << "Bok: " << bok << std::endl;
    std::cout << "Pole: " << pole << std::endl;
    std::cout << "Obwod: " << obwod << std::endl;
} 