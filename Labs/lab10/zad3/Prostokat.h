#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include "Figura.h"
#include "../zad1/Punkt.h"

class Prostokat : public Figura {
private:
    Punkt lewyGorny;
    Punkt prawyDolny;

    void obliczPole() override;
    void obliczObwod() override;

public:
    Prostokat();
    Prostokat(const Punkt& lg, const Punkt& pd);
    Prostokat(const Punkt& lg, const Punkt& pd, const std::string& nazwa);
    ~Prostokat() override;

    void setPunkty(const Punkt& lg, const Punkt& pd);
    Punkt getLewyGorny() const;
    Punkt getPrawyDolny() const;

    void wyswietl() const override;
};

#endif 