#include "Punkt.h"
#include <iostream>

Punkt::Punkt() : x(0), y(0), nazwa("Punkt") {}

Punkt::Punkt(double x, double y, const std::string& nazwa) : x(x), y(y), nazwa(nazwa) {}

void Punkt::setX(double x) {
    this->x = x;
}

void Punkt::setY(double y) {
    this->y = y;
}

void Punkt::setNazwa(const std::string& nazwa) {
    if (!nazwa.empty()) {
        this->nazwa = nazwa;
    }
}

double Punkt::getX() const {
    return x;
}

double Punkt::getY() const {
    return y;
}

std::string Punkt::getNazwa() const {
    return nazwa;
}

void Punkt::wyswietl() const {
    std::cout << nazwa << "(" << x << ", " << y << ")" << std::endl;
} 