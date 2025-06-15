#ifndef KOLO_H
#define KOLO_H

#include "../zad1/Punkt.h"
#include <string>

class Kolo {
private:
    std::string nazwa;
    Punkt srodek;
    double promien;
    double pole;
    double obwod;

    void obliczPole();
    void obliczObwod();

public:
    Kolo();
    Kolo(const Punkt& srodek, double promien);
    Kolo(const Punkt& srodek, double promien, const std::string& nazwa);
    ~Kolo();

    void setNazwa(const std::string& nazwa);
    void setSrodek(const Punkt& srodek);
    void setPromien(double promien);

    std::string getNazwa() const;
    double getPole() const;
    double getObwod() const;
    Punkt getSrodek() const;
    double getPromien() const;

    void wyswietl() const;
};

#endif 