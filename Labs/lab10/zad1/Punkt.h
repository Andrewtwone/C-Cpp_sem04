#ifndef PUNKT_H
#define PUNKT_H

#include <string>

class Punkt {
private:
    double x;
    double y;
    std::string nazwa;

public:
    Punkt();
    Punkt(double x, double y, const std::string& nazwa);
    
    void setX(double x);
    void setY(double y);
    void setNazwa(const std::string& nazwa);
    
    double getX() const;
    double getY() const;
    std::string getNazwa() const;
    
    void wyswietl() const;
};

#endif 