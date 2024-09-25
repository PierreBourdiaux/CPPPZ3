#include "cartesien.hpp"


Cartesien::Cartesien(double x,double y) : x(x), y(y){}
Cartesien::Cartesien():x(0.0), y(0.0){}
Cartesien::Cartesien(Polaire& p){
    Cartesien c;
    p.convertir(c);
    x = c.getX();
    y = c.getY();
}

double Cartesien::getX()const{return x;}
double Cartesien::getY()const {return y;}
void Cartesien::setX(double newx){x = newx;}
void Cartesien::setY(double newy){y = newy;}

void Cartesien::afficher(std::ostream& ss)const{ 
    ss<<"(x="<< (int)x<< ";y="<<(int)y<<")";
}

void Cartesien::convertir(Cartesien& c) const{
    c.setX(x);
    c.setY(y);
}
void Cartesien::convertir(Polaire& p) const{
    p.setDistance(hypot(x,y));
    p.setAngle(atan2(y,x)*180 / M_PI); // a = std::atan2(y, x) * 180 / M_PI
}