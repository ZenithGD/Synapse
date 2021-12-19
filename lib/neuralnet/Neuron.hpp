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
        synmath::SynVector _weights;

        /**
         * @brief Neuron bias value.
         */
        double _bias;

        /**
         * @brief Activation function for the given neuron.
         * Returns a value in T's domain based on the neuron output's value.
         */
        std::function<T(double)> _act_func;
    public:
        /**
         * @brief Construct a new Neuron object
         * Sets the weights, bias and activation function.
         * @param w 
         * @param b 
         * @param fn 
         */
        Neuron(std::initializer_list<double> w, double b, std::function<T(double)> fn)
            : _weights(w), _bias(b), _act_func(fn) {}

        /**
         * @brief Calculate neuron output for the given input x.
         * This returns the following value based on the weights W and bias b on
         * any given input x:
         * \f[
         *      f(n) = f(W^Tx + b) = f(\sum_{i=1}^n (w_ix_i) + b)
         * \f]
         * @param input The neuron input values.
         * @return T 
         */
        inline T output(synmath::SynVector input) {
            return _act_func(_weights * input + _bias);
        }

        /**
         * @brief Set the weights vector
         * 
         * @param wp 
         */
        inline void set_weights(synmath::SynVector wp) {
            _weights = wp;
        }

        /**
         * @brief Set the bias value
         * 
         * @param bp 
         */
        inline void set_bias(synmath::SynVector bp) {
            _bias = bp;
        }

        /**
         * @brief Get the weights vector
         * 
         * @return synmath::SynVector 
         */
        inline synmath::SynVector get_weights() const {
            return _weights;
        }

        /**
         * @brief Get the bias value
         * 
         * @return double
         */
        inline double get_bias() const {
            return _bias;
        }
    };
};

#endif // __NEURON_H__