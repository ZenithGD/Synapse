#include <iostream>

#include <math/SynVector.hpp>

int main() {

    std::cout << synmath::SynVector({1,1,1,1}) * synmath::SynVector({1,-1,1,-1})<< std::endl;
    return 0;
}