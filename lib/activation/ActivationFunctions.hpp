#pragma once

#include <functional>

#include <linalg/linalg.h>

// Computation functions
double __sigmoid_fn(double v);
double __relu_fn(double v);

/**
 * @brief header for common layer activation functions
 * 
 */
namespace syn {

    template <int M>
    const std::function<linalg::vec<double, M>(linalg::vec<double, M>)> sigmoid(
        [](linalg::vec<double, M> vec) -> linalg::vec<double, M> {
            return linalg::apply(__sigmoid_fn, vec);
        }
    );

    template <int M>
    const std::function<linalg::vec<double, M>(linalg::vec<double, M>)> relu(
        [](linalg::vec<double, M> vec) -> linalg::vec<double, M> {
            return linalg::apply(__relu_fn, vec);
        }
    );
}