#include "../include/Vector.h"


Vector::Vector(const int ndim):
    n(ndim), dim(new scal[ndim]){
    for (int i = 0; i < n; i++){
        dim[i]=0;
    }
};

Vector::Vector(const Vector& v):
    n(v.n){
    for (int i = 0; i < n; i++){
        dim[i]=v.dim[i];
    }
};



Vector::~Vector(){
    delete[] dim;
};

Vector& Vector::operator = (const Vector& v2){
    delete[] dim;
    dim = new scal[n];
    for (int i = 0; i < n; i++){
        dim[i]=v2.dim[i];
    }
    return *this;
}

Vector Vector::operator + (const Vector& v2) const {
    Vector res(n);
    for (int i =0; i < n ; i++){
        res.dim[i] += v2.dim[i];
    }
    return res;
};

Vector Vector::operator - (const Vector& v2) const {
    Vector res(n);
    for (int i =0; i < n ; i++){
        res.dim[i] -= v2.dim[i];
    }
    return res;
};

scal Vector::operator [](const int i) {
    return dim[i];
}

const scal Vector::operator [](const int i) const{
    return dim[i];
}