#include "ActivationFunctions.hpp"

#include <cmath>

double __sigmoid_fn(double v) {
    // Compute sigmoid function
    return 1 / ( 1 + exp(-v) );
}

double __relu_fn(double v) {
    // active neuron
    if ( v > 0 ) return v;
    
    // inactive neuron
    return 0;
}