#include "Kolo.h"
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

Kolo::Kolo(const Punkt& srodek, double promien, const std::string& nazwa)
    : Figura(nazwa), srodek(srodek), promien(promien) {
    obliczPole();
    obliczObwod();
}

Kolo::~Kolo() {
    std::cout << "Destruktor Kola" << std::endl;
}

void Kolo::setNazwa(const std::string& nazwa) {
    Figura::setNazwa(nazwa);
}

void Kolo::setSrodek(const Punkt& srodek) {
    this->srodek = srodek;
}

void Kolo::setPromien(double promien) {
    this->promien = promien;
    obliczPole();
    obliczObwod();
}

Punkt Kolo::getSrodek() const {
    return srodek;
}

double Kolo::getPromien() const {
    return promien;
}

void Kolo::obliczPole() {
    setPole(PI * promien * promien);
}

void Kolo::obliczObwod() {
    setObwod(2 * PI * promien);
}

void Kolo::wyswietl() const {
    std::cout << "Kolo: " << getNazwa() << std::endl;
    std::cout << "Srodek: (" << srodek.getX() << ", " << srodek.getY() << ")" << std::endl;
    std::cout << "Promien: " << promien << std::endl;
    std::cout << "Pole: " << getPole() << std::endl;
    std::cout << "Obwod: " << getObwod() << std::endl;
} 