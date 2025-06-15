#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include "Figura.h"
#include "../zad1/Punkt.h"

class Prostokat : public Figura {
private:
    Punkt lewyGorny;
    Punkt prawyDolny;

public:
    Prostokat(const Punkt& lg, const Punkt& pd, const std::string& nazwa);
    ~Prostokat() override;

    void setNazwa(const std::string& nazwa);
    void setPunkty(const Punkt& lg, const Punkt& pd);
    Punkt getLewyGorny() const;
    Punkt getPrawyDolny() const;

    void obliczPole() override;
    void obliczObwod() override;
    void wyswietl() const override;
};

#endif 