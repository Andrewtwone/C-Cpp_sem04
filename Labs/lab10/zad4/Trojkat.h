#ifndef TROJKAT_H
#define TROJKAT_H

#include "Figura.h"
#include "../zad1/Punkt.h"
#include <array>

class Trojkat : public Figura {
private:
    std::array<Punkt, 3> wierzcholki;

    void obliczPole() override;
    void obliczObwod() override;

public:
    Trojkat(const Punkt& p1, const Punkt& p2, const Punkt& p3, const std::string& nazwa);
    ~Trojkat() override;

    void setNazwa(const std::string& nazwa) override;
    void setWierzcholki(const Punkt& p1, const Punkt& p2, const Punkt& p3);
    std::array<Punkt, 3> getWierzcholki() const;

    void wyswietl() const override;
};

#endif 