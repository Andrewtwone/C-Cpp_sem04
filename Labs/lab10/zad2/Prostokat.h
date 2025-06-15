#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include "../zad1/Punkt.h"
#include <string>

class Prostokat {
private:
    std::string nazwa;
    Punkt lewyGorny;
    Punkt prawyDolny;
    double pole;
    double obwod;

    void obliczPole();
    void obliczObwod();

public:
    Prostokat();
    Prostokat(const Punkt& lg, const Punkt& pd);
    Prostokat(const Punkt& lg, const Punkt& pd, const std::string& nazwa);
    ~Prostokat();

    void setNazwa(const std::string& nazwa);
    void setPunkty(const Punkt& lg, const Punkt& pd);

    std::string getNazwa() const;
    double getPole() const;
    double getObwod() const;
    Punkt getLewyGorny() const;
    Punkt getPrawyDolny() const;

    void wyswietl() const;
};

#endif 