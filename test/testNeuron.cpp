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

    synnet::Neuron<bool, 2> neuron({-1, 0}, 225, 
        [](double v) -> bool { return v > 0; });

    synunittest::unitTestNeuron<bool, 2> unittest(neuron);
    unittest.performUnitTestSuite({
        testCase1({150, 0.8}, true),
        testCase1({260, 0.6}, false)
    });
    return 0;
}