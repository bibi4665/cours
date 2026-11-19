#ifndef VECTOR_H
#define VECTOR_H
#include "scal.h"

class Vector {

    scal* dim;
    int n;

    public:
        Vector(const Vector& v = 1);
        Vector(const int ndim);
        ~Vector();

        Vector& operator = (const Vector& v2);
        scal operator [] (const int i);
        const scal operator [] (const int i) const;

        Vector operator + (const Vector& v2) const;
        Vector operator - (const Vector& v2) const;
/*
        Vector& operator * (Vector&) const;
        Vector& operator ^ (Vector&) const;

        Vector& operator * (scal) const;

        Vector& operator += (Vector&) const;
        Vector& operator -= (Vector&) const;
        Vector& operator *= (Vector&) const;
        Vector& operator ^= (Vector&) const;*/

        const int size();
        //... norm();


};

#endif