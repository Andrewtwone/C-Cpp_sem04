#ifndef KOLO_H
#define KOLO_H

#include "Figura.h"
#include "../zad1/Punkt.h"

class Kolo : public Figura {
private:
    Punkt srodek;
    double promien;

public:
    Kolo(const Punkt& srodek, double promien, const std::string& nazwa);
    ~Kolo() override;

    void setNazwa(const std::string& nazwa);
    void setSrodek(const Punkt& srodek);
    void setPromien(double promien);
    Punkt getSrodek() const;
    double getPromien() const;

    void obliczPole() override;
    void obliczObwod() override;
    void wyswietl() const override;
};

#endif 