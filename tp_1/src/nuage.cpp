#include "nuage.hpp"

Nuage::Nuage(): taille(0){}
void Nuage::ajouter(Point& p){
    v.push_back(&p);
    taille++;
}

int Nuage::size()const{return taille;}
