
#ifndef TP1_ZZ3_CARTESIEN 
#define  TP1_ZZ3_CARTESIEN
#include <iostream>
#include "point.hpp"
#include <cmath>
#include "polaire.hpp"

class Polaire;

class Cartesien : public Point
{
private:
    double x;
    double y;
public:
    Cartesien(double x,double y);
    Cartesien();
    Cartesien(Polaire&);
    double getX()const;
    double getY()const;
    void setX(double newx);
    void setY(double newy);
    void afficher(std::ostream& ss)const;
    void convertir(Cartesien&) const;
    void convertir(Polaire&) const;
};





#endif