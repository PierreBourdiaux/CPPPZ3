#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <iostream>
#include <vector>
#include <typeinfo>


template<typename T> class Nuage
{
private:
    std::vector<T> v;
    int taille;

public:
    Nuage();
    void ajouter(T);
    int size()const;

    typename std::vector<T>::const_iterator begin() const;

    typename std::vector<T>::const_iterator end() const;
    public:
    using const_iterator = typename std::vector<T>::const_iterator;

};


template<typename T>
Nuage<T>::Nuage(): taille(0){

}

template<typename T>
void Nuage<T>::ajouter(T t){
    taille++;
    v.push_back(t);
}

template<typename T>
int Nuage<T>::size()const{return taille;}

template<typename T>
typename std::vector<T>::const_iterator Nuage<T>::begin() const{
    return v.begin();
}

template<typename T>
typename std::vector<T>::const_iterator Nuage<T>::end() const{
    return v.end();
}

template<typename T>
Cartesien barycentre(Nuage<T> n){
    Cartesien c;
    double x =0;
    double y = 0;
    for(typename Nuage<T>::const_iterator it = n.begin(); it!= n.end(); it++){
        Cartesien tmp = {};
        it->convertir(tmp);
        x = x+ tmp.getX();
        y = y+ tmp.getY();
    }
    c.setX(x / n.size());
    c.setY(y / n.size());

    if(n.size() == 0){c = Cartesien(0.0,0.0);}

    return c;
}




template <typename T>
Cartesien barycentre(Nuage<T> n);
struct BarycentreCartesien
{
    Cartesien operator()(Nuage<Cartesien> n){
        return barycentre(n);
    }
};

struct BarycentrePolaire
{
    Polaire operator()(Nuage<Polaire> n){
        Polaire p;
        barycentre(n).convertir(p);
        return p;
    }
};


template <typename T>
T barycentre_v1(Nuage<T> n){
    Cartesien c = barycentre(n);
    return c;
}

Polaire barycentre_v1(Nuage<Polaire> n){
    if(n.size() == 0){return Polaire(0.0,0.0);}
    float a = 0.0;
    float b = 0.0;

    for(Nuage<Polaire>::const_iterator it = n.begin(); it!= n.end(); it++){

        a+=it->getAngle();
        b+=it->getDistance();

    }

    return Polaire(a/(float)n.size(), b/(float)n.size());
}
