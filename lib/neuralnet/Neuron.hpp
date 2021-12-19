#ifndef __NEURON_H__
#define __NEURON_H__

#include <vector>
#include <functional>

#include <math/Vector.hpp>

namespace synnet {

    /**
     * @brief Class for representing a neural network neuron.
     * 
     * @tparam T The output parameter from the activation function.
     */
    template <typename T>
    class Neuron {
    private:
        Vector _weights;
        std::function<T(double)> _act_func;
    public:
        Neuron(std::initializer_list<double> w, std::function<T(double)> fn)
    };
};

#endif // __NEURON_H__