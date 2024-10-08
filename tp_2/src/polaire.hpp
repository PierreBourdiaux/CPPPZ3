
#ifndef TP1_ZZ3_POLAIRE 
#define  TP1_ZZ3_POLAIRE

#include "point.hpp"
#include <iostream>
#include <math.h>
#include <typeinfo>



class Polaire : public Point
{
private:
    double angle;
    double distance;
public:
    Polaire(double a, double b);
    Polaire();
    Polaire(const Cartesien& );
    void afficher(std::ostream& ss)const;
    double getDistance()const;
    double getAngle()const;
    void setAngle(double a);
    void setDistance(double d);
    void convertir(Cartesien&) const;
    void convertir(Polaire&) const;

};

#endif