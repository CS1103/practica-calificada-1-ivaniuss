//
// Created by rudri on 9/12/2019.
//

#include    <stdexcept>
#include <iostream>
#include <cassert>
using std::istream;
using std::ostream;
#include "Polynomial.h"

Polynomial::Polynomial() {

        coeficiente = new float[1];
        assert(coeficiente != 0);
        coeficiente[0] = 0;
        degree = 0;

}

Polynomial::Polynomial(const float *Coef, int Grado ) {
    degree = Grado;
    coeficiente = new float[degree + 1];
    assert(coeficiente != 0);
    for (int i = 0; i <= degree; i++)
        coeficiente[i] = Coef[i];
}

Polynomial::Polynomial(const Polynomial &p) {
    degree = p.degree;
    coeficiente = new float[degree];
    assert(coeficiente != 0);
    for (int i = 0; i <= degree; i++)
        coeficiente[i] = p.coeficiente[i];
}
Polynomial::~Polynomial() {
    delete [] coeficiente;
}

Polynomial &Polynomial::operator+(const Polynomial &p) {
    if (p.degree < degree)
    {
        for (int i = 0; i <= p.degree; i++)
            coeficiente[i] += p.coeficiente[i];
    }
    else
    if (p.degree > degree)
    {
        float * c = new float[p.degree + 1];
        assert (c != 0);
        int i = 0;
        for (; i <= degree; i++)
            c[i] = coeficiente[i] + p.coeficiente[i];
        for (; i <= p.degree; i++)
            c[i] = p.coeficiente[i];
        delete [] coeficiente;
        coeficiente= c;
        degree = p.degree;
    }
    else
    {
        int i = degree;
        while ((coeficiente[i] + p.coeficiente[i]) && (i >= 0))
            --i;
        if (i < 0) {
            delete [] coeficiente;
            degree = 0;
            coeficiente = new float[1];
            coeficiente[0] = 0.0;
        }
        else
        if (i == degree) {
            for (int i = 0; i <= degree; i++)
                coeficiente[i] += p.coeficiente[i];
        }
        else
        {
            degree = i;
            float * c = new float[i + 1];
            assert (c != 0);
            for (; i >= 0; i--)
                c[i] = coeficiente[i] + p.coeficiente[i];
            delete [] coeficiente;
            coeficiente = c;
        }
    }
    return *this;
}




