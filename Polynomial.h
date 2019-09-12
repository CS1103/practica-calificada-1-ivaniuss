//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <vector>
#include <ostream>
using namespace std;

class Polynomial {

    int degree;
    float *coeficiente;


public:
    Polynomial();
    Polynomial(const float*, int);
    Polynomial(const Polynomial &);
    ~Polynomial();

    float operator () (float x) const;
    Polynomial &operator + (const Polynomial & p);
    Polynomial &operator * (const Polynomial & p);
    Polynomial &operator * (const float x);
    friend Polynomial &operator * (float x, Polynomial & p);
    Polynomial &operator = (const Polynomial & p);
    friend istream& operator>>(istream&,Polynomial& );
    friend ostream& operator<<(ostream&,const Polynomial&);
};

#endif //POLINOMIO_POLINOMIO_H
