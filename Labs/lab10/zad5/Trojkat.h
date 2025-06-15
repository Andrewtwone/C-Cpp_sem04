#ifndef TROJKAT_H
#define TROJKAT_H

#include "Figura.h"
#include "../zad1/Punkt.h"

class Trojkat : public Figura {
private:
    Punkt wierzcholki[3];

public:
    Trojkat(const Punkt& p1, const Punkt& p2, const Punkt& p3, const std::string& nazwa);
    ~Trojkat() override;

    void setNazwa(const std::string& nazwa);
    void setWierzcholki(const Punkt& p1, const Punkt& p2, const Punkt& p3);
    Punkt* getWierzcholki();

    void obliczPole() override;
    void obliczObwod() override;
    void wyswietl() const override;
};

#endif 