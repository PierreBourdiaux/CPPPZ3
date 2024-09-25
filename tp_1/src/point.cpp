#include "point.hpp"


Point::Point(){}

void Point::afficher(std::ostream& ss)const{
    ss<<"afficher de Point"<<std::endl;
}

std::ostream& operator<<(std::ostream& ss, const Point& p){
    p.afficher(ss);
    return ss;
}