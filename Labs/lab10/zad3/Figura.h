#ifndef FIGURA_H
#define FIGURA_H

#include <string>
#include <iostream>

class Figura {
protected:
    std::string nazwa;
    double pole;
    double obwod;

    virtual void obliczPole() = 0;
    virtual void obliczObwod() = 0;

public:
    Figura();
    Figura(const std::string& nazwa);
    virtual ~Figura();

    void setNazwa(const std::string& nazwa);
    std::string getNazwa() const;
    double getPole() const;
    double getObwod() const;

    virtual void wyswietl() const = 0;
};

#endif 