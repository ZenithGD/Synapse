#include <iostream>

#include <neuralnet/Layer.hpp>
#include "testSynapse.hpp"

#include <linalg/linalg.h>

// functions for quickly defining test cases for test suites 
// without dying in the process
std::pair<linalg::vec<double, 2>, bool> testCase1
    (linalg::vec<double, 2> input, bool res) {

    return std::make_pair(input, res);
}

int main() {

    synnet::Layer<bool, 3, 2> l(
        {{0, 1, -1}, {-1, 0, 100}}, 
        {0.55, 240, -150}, 
        [](double v) -> bool { return v > 0; });

    synunittest::unitTestLayer<bool, 3, 2> unittest(l);
    unittest.performUnitTestSuite({
        testCase1({150, 0.8}, true),
        testCase1({260, 0.6}, false)
    });
    return 0;
}