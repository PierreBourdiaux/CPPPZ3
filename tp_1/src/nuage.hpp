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
};
