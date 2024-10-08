
#ifndef TP1_ZZ3_POINT 
#define  TP1_ZZ3_POINT

#include <iostream>

// #ifndef M_PI
//   #define M_PI 3.14159265358979323846
// #endif

class Cartesien;
class Polaire; 

class Point
{
private:

public:
    Point();
    virtual void afficher( std::ostream& ss) const;
    virtual void convertir(Cartesien&) const =0;
    virtual void convertir(Polaire&) const =0;
    
};

std::ostream& operator<<(std::ostream& , const Point&);

#endif