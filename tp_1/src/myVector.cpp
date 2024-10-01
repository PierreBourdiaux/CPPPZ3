#include "myVector.hpp"

MyVector::MyVector() : taille(0), capacite(100){
    tab = new int[capacite];
}


MyVector::MyVector(const MyVector& v){
    capacite = v.getCapacite();
    taille = v.getTaille();
    tab = new int[capacite];
    for(int i = 0; i < taille; i++){
        tab[i] = v.tab[i];
    }
}

MyVector::~MyVector(){
    delete[] tab;
}

MyVector&  MyVector::operator=(const MyVector& v){
    capacite = v.capacite;
    taille = v.taille;
    tab = new int[capacite];
    for(int i = 0; i< taille; i++){
        tab[i] = v.tab[i];
    }
    return *this;
}

int& MyVector::operator[](int i){
    if(i < taille ){
        return tab[i];
        
    }
    else return tab[0];
}

std::ostream& operator<<(std::ostream& ss, MyVector& v){
    for(int i = 0; i< v.getTaille(); i++){
        ss << v[i]<< " ";
    }
    return ss;
}

void MyVector::append(int value){
    if(taille >= capacite){
        capacite = capacite *2;
        int* newTab = new int[capacite];
        for(int i= 0; i< taille; i++){
            newTab[i] = tab[i];
        }
        int * tmp = tab;
        tab = newTab;
        delete[] tmp;
    }
    tab[taille] = value;
    taille++;
}
MyVector& MyVector::operator+( MyVector& v){
    for(int i =0; i<v.getTaille(); i++){
        append(v[i]);
    }
    return *this;
}

int MyVector::operator*(MyVector& b){
    int min=taille;
    int total = 0;
    if(min > b.getTaille()) min = b.getTaille();
    for(int i = 0; i< min; i++){
        total = total + tab[i]*b[i];
    }
    for(int i = min; i< b.getTaille(); i++){
        total = total + b[i];
    }
    for(int i = min; i< getTaille(); i++){
        total = total + tab[i];
    }

    return total;
}

MyVector::ItVector MyVector::begin(){
    return ItVector(tab);
}
MyVector::ItVector MyVector::end(){
    return ItVector(tab+(taille-1));
}

int  MyVector::getTaille()const{return taille;}
int MyVector::getCapacite()const{return capacite;}