#include "../include/Vector.h"
#include "Vector.cpp"
#include <iostream>

int main(){

    Vector v1(10);
    v1[0] = 1;
    std::cout << v1[0] << std::endl;
    

    return 0;
};