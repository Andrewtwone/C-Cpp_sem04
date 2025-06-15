#include "Figura.h"

Figura::Figura(const std::string& nazwa) : nazwa(nazwa), pole(0), obwod(0) {
    std::cout << "Konstruktor Figury z nazwa: " << nazwa << std::endl;
}

Figura::~Figura() {
    std::cout << "Destruktor Figury: " << nazwa << std::endl;
}

void Figura::setNazwa(const std::string& nazwa) {
    if (!nazwa.empty()) {
        this->nazwa = nazwa;
    }
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