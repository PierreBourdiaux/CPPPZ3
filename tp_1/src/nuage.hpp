#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"
#include <iostream>
#include <vector>

class Nuage
{
private:
    std::vector<Point *> v;
    int taille;

public:
    Nuage();
   void ajouter(Point &p);
   int size()const;
    std::vector<Point*>::const_iterator begin() const;
    std::vector<Point*>::const_iterator end() const;
    public:
        using const_iterator = std::vector<Point*>::const_iterator;

};


Cartesien barycentre(Nuage n);
struct BarycentreCartesien
{
    Cartesien operator()(Nuage n){
        return barycentre(n);
    }
};

struct BarycentrePolaire
{
    Polaire operator()(Nuage n){
        Polaire p;
        barycentre(n).convertir(p);
        return p;
    }
};