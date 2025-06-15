#include "Kolo.h"
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

Kolo::Kolo() : Figura("Kolo"), srodek(), promien(0) {
    std::cout << "Konstruktor domyslny Kola" << std::endl;
}

Kolo::Kolo(const Punkt& srodek, double promien) 
    : Figura("Kolo"), srodek(srodek), promien(promien) {
    std::cout << "Konstruktor z punktem i promieniem Kola" << std::endl;
    obliczPole();
    obliczObwod();
}

Kolo::Kolo(const Punkt& srodek, double promien, const std::string& nazwa)
    : Figura(nazwa), srodek(srodek), promien(promien) {
    std::cout << "Konstruktor z punktem, promieniem i nazwa Kola" << std::endl;
    obliczPole();
    obliczObwod();
}

Kolo::~Kolo() {
    std::cout << "Destruktor Kola" << std::endl;
}

void Kolo::setSrodek(const Punkt& srodek) {
    this->srodek = srodek;
}

void Kolo::setPromien(double promien) {
    if (promien > 0) {
        this->promien = promien;
        obliczPole();
        obliczObwod();
    }
}

Punkt Kolo::getSrodek() const {
    return srodek;
}

double Kolo::getPromien() const {
    return promien;
}

void Kolo::obliczPole() {
    pole = PI * promien * promien;
}

void Kolo::obliczObwod() {
    obwod = 2 * PI * promien;
}

void Kolo::wyswietl() const {
    std::cout << "Kolo: " << nazwa << std::endl;
    std::cout << "Srodek: ";
    srodek.wyswietl();
    std::cout << "Promien: " << promien << std::endl;
    std::cout << "Pole: " << pole << std::endl;
    std::cout << "Obwod: " << obwod << std::endl;
} 