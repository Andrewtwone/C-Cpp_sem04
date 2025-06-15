#ifndef KWADRAT_H
#define KWADRAT_H

#include "../zad1/Punkt.h"
#include <string>

class Kwadrat {
private:
    std::string nazwa;
    Punkt lewyGorny;
    double bok;
    double pole;
    double obwod;

    void obliczPole();
    void obliczObwod();

public:
    Kwadrat();
    Kwadrat(const Punkt& lg, double bok);
    Kwadrat(const Punkt& lg, double bok, const std::string& nazwa);
    ~Kwadrat();

    void setNazwa(const std::string& nazwa);
    void setPunkt(const Punkt& lg);
    void setBok(double bok);

    std::string getNazwa() const;
    double getPole() const;
    double getObwod() const;
    Punkt getLewyGorny() const;
    double getBok() const;

    void wyswietl() const;
};

#endif 