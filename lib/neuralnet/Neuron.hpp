#ifndef __NEURON_H__
#define __NEURON_H__

#include <vector>
#include <functional>

#include <math/SynVector.hpp>

namespace synnet {

    /**
     * @brief Class for representing a neural network neuron.
     * 
     * @tparam T The output parameter from the activation function.
     */
    template <typename T>
    class Neuron {
    private:
        /**
         * @brief Neuron weight vector.
         */
        Vector _weights;
        /**
         * @brief Activation function for the given neuron.
         * Returns a value in T's domain based on the neuron output's value.
         */
        std::function<T(double)> _act_func;
    public:
        Neuron(std::initializer_list<double> w, std::function<T(double)> fn);
    };
};

#endif // __NEURON_H__