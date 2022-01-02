#pragma once

#include <vector>
#include <functional>

#include <linalg/linalg.h>

namespace synnet {

    /**
     * @brief Class for representing a neural network neuron.
     * 
     * @tparam T The output parameter from the activation function.
     */
    template <typename T, int N>
    class Neuron {
    private:
        /**
         * @brief Neuron weight vector.
         */
        linalg::vec<double, N> _weights;

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
         * @param w The neuron weights vector.
         * @param b The neuron bias
         * @param fn The neuron activation function
         */
        Neuron(linalg::vec<double, N> w, double b, std::function<T(double)> fn)
            : _weights(w), _bias(b), _act_func(fn) {}

        /**
         * @brief Calculate neuron output for the given input x.
         * This returns the following value based on the weights W and bias b on
         * any given input x:
         * \f[
         *      f(n) = f(W^Tx + b) = f(\sum_{i=1}^n (w_ix_i) + b)
         * \f]
         * @param input The neuron input values.
         * @return T The activation function output for this neuron based on the input
         */
        inline T output(const linalg::vec<double, N> input) {
            return _act_func(dot(_weights,input) + _bias);
        }

        /**
         * @brief Set the weights vector
         * 
         * @param wp 
         */
        inline void set_weights(const linalg::vec<double, N> wp) {
            _weights = wp;
        }

        /**
         * @brief Set the bias value
         * 
         * @param bp 
         */
        inline void set_bias(const double bp) {
            _bias = bp;
        }

        /**
         * @brief Get the weights vector
         * 
         * @return linalg::vec<T, N>
         */
        inline linalg::vec<double, N> get_weights() const {
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
