#include <iostream>
#include <utility>

#include <neuralnet/Neuron.hpp>
#include "testSynapse.hpp"

#include <linalg/linalg.h>

// functions for quickly defining test cases for test suites 
// without dying in the process
std::pair<linalg::vec<double, 2>, bool> testCase1
    (linalg::vec<double, 2> input, bool res) {

    return std::make_pair(input, res);
}

int main() {

    syn::Neuron<bool, 2> neuron({-1, 1}, 0, 
        [](double v) -> bool { return v >= 0; });

    synunittest::unitTestNeuron<bool, 2> unittest(neuron);
    unittest.performUnitTestSuite({
        testCase1({2, 1}, false),
        testCase1({1, 2}, true),
        testCase1({31, 2}, false),
        testCase1({-1, -2}, false)
    });
    return 0;
}