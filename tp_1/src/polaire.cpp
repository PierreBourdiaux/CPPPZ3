#include "polaire.hpp"
#include "cartesien.hpp"


Polaire::Polaire(double a, double b):angle(a), distance(b){}
Polaire::Polaire():angle(0.0), distance(0.0){}
Polaire::Polaire(Cartesien& c)
{
    Polaire p;
    c.convertir(p);
    angle = p.getAngle();
    distance = p.getDistance();
}


void Polaire::afficher(std::ostream& ss)const{ //(a=12;d=24)
    ss<<"(a="<< (int)angle<< ";d="<<(int)distance<<")";
}

double Polaire::getAngle()const { return angle;}
double Polaire::getDistance()const{return distance;}

void Polaire::setAngle(double a){angle = a;}
void Polaire::setDistance(double d){distance = d;}

void Polaire::convertir(Cartesien& c) const{
    c.setX(distance * (cos(angle * M_PI / 180)));
    c.setY(distance * (sin(angle * M_PI / 180)));
}
void Polaire::convertir(Polaire& p) const{
    p.setAngle(angle);
    p.setDistance(distance);
}