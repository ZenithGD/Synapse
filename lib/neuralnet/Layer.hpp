#ifndef __LAYER_H__
#define __LAYER_H__

#include <linalg/linalg.h>

namespace synnet
{
    template <typename T, int M, int N>
    class Layer
    {
    private:
        /**
         * @brief Layer weight matrix.
         */
        linalg::mat<double, M, N> _weights;

        /**
         * @brief Neuron bias values for each neuron in the layer.
         */
        linalg::mat<double, M> _bias;

        /**
         * @brief Activation function for the given layer's M neurons.
         * Returns a value in T's domain based on the neuron output's value.
         */
        std::function<T(double)> _act_func;
    public:
        Layer(/* args */);
        /**
         * @brief Construct a new Layer object
         * Sets the weights, bias and activation function.
         * @param w The layer weights matrix.
         * @param b The layer bias vector.
         * @param fn The neuron activation function
         */
        Neuron(linalg::mat<double, M, N> w, linalg::vec<double, N> b, std::function<T(double)> fn)
            : _weights(w), _bias(b), _act_func(fn) {}
        ~Layer();

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
            return _act_func(mul(_weights,input) + _bias);
        }

        /**
         * @brief Set the weights vector
         * 
         * @param wp 
         */
        inline void set_weights(const linalg::mat<double, M, N> wp) {
            _weights = wp;
        }

        /**
         * @brief Set the bias value
         * 
         * @param bp 
         */
        inline void set_bias(linalg::vec<double, N> bp) {
            _bias = bp;
        }

        /**
         * @brief Get the weights vector
         * 
         * @return linalg::mat<double, M, N>
         */
        inline linalg::mat<double, M, N> get_weights() const {
            return _weights;
        }

        /**
         * @brief Get the bias value
         * 
         * @return linalg::vec<double, N>
         */
        inline linalg::vec<double, N> get_bias() const {
            return _bias;
        }
    };
} // namespace synnet



#endif // __LAYER_H__