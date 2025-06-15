#include "Figura.h"
#include <iostream>

Figura::Figura(const std::string& nazwa) : nazwa(nazwa), pole(0), obwod(0) {}

Figura::~Figura() {
    std::cout << "Destruktor Figury" << std::endl;
}

void Figura::setNazwa(const std::string& nazwa) {
    this->nazwa = nazwa;
}

std::string Figura::getNazwa() const {
    return nazwa;
}

double Figura::getPole() const {
    return pole;
}

double Figura::getObwod() const {
    return obwod;
}

void Figura::setPole(double pole) {
    this->pole = pole;
}

void Figura::setObwod(double obwod) {
    this->obwod = obwod;
} 