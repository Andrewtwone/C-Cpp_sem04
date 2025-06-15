#ifndef KOLO_H
#define KOLO_H

#include "Figura.h"
#include "../zad1/Punkt.h"

class Kolo : public Figura {
private:
    Punkt srodek;
    double promien;

    void obliczPole() override;
    void obliczObwod() override;

public:
    Kolo();
    Kolo(const Punkt& srodek, double promien);
    Kolo(const Punkt& srodek, double promien, const std::string& nazwa);
    ~Kolo() override;

    void setSrodek(const Punkt& srodek);
    void setPromien(double promien);
    Punkt getSrodek() const;
    double getPromien() const;

    void wyswietl() const override;
};

#endif 