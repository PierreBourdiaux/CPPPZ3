// #include "nuage.hpp"

// Nuage::Nuage(): taille(0){}
// void Nuage::ajouter(Point& p){
//     v.push_back(&p);
//     taille++;
// }

// int Nuage::size()const{return taille;}


// Nuage::const_iterator Nuage::begin()const{
//     return v.begin();
// }
// Nuage::const_iterator Nuage::end()const {
//     return v.end();
// }

// Cartesien barycentre(Nuage n){
//     Cartesien c;
//     double x =0;
//     double y = 0;
//     for(Nuage::const_iterator it = n.begin(); it!= n.end(); it++){
//         Cartesien tmp = {};
//         (*it)->convertir(tmp);
//         x = x+ tmp.getX();
//         y = y+ tmp.getY();
//     }
//     c.setX(x / n.size());
//     c.setY(y / n.size());

//     return c;
// }

