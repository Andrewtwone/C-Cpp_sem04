#ifndef KWADRAT_H
#define KWADRAT_H

#include "Figura.h"
#include "../zad1/Punkt.h"

class Kwadrat : public Figura {
private:
    Punkt lewyGorny;
    double bok;

    void obliczPole() override;
    void obliczObwod() override;

public:
    Kwadrat();
    Kwadrat(const Punkt& lg, double bok);
    Kwadrat(const Punkt& lg, double bok, const std::string& nazwa);
    ~Kwadrat() override;

    void setPunkt(const Punkt& lg);
    void setBok(double bok);
    Punkt getLewyGorny() const;
    double getBok() const;

    void wyswietl() const override;
};

#endif 