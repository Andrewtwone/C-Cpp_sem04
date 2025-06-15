#include "Figura.h"

Figura::Figura() : nazwa("Figura"), pole(0), obwod(0) {
    std::cout << "Konstruktor domyslny Figury" << std::endl;
}

Figura::Figura(const std::string& nazwa) : nazwa(nazwa), pole(0), obwod(0) {
    std::cout << "Konstruktor z nazwa Figury" << std::endl;
}

Figura::~Figura() {
    std::cout << "Destruktor Figury" << std::endl;
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