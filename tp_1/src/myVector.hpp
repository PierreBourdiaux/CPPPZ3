#include <iostream>
#include <exception>
class MyVector
{
private:
    int taille;
    int capacite;
    int* tab;
public:
    MyVector();
    MyVector(const MyVector&);
    ~MyVector();
    MyVector& operator=(const MyVector&);
    MyVector& operator+( MyVector&);
    int operator*(MyVector&);
    int& operator[](int);
    int getTaille()const;
    int getCapacite()const;
    void append(int);

    class ItVector{
        private :
        int * val;

        public : 
        ItVector(){
            val = nullptr;
        }
        ItVector(int* t):val(t){
            
        }
        
        ItVector& operator++(){
            if(val==nullptr) throw std::invalid_argument("NULLPTR ITERATOR");
            val++;
            return *this;
        }

        ItVector operator++(int){
            ItVector tmp = *this;
            val++;
            return tmp;
        }

        int operator*(){return *val;}

        bool operator==(const ItVector& v){
            return val == v.val;
        }

    };
    ItVector begin();
    ItVector end();
};
std::ostream& operator<<(std::ostream&, MyVector&);

// const defaut , copie, desct, op de copie
