#include <iostream>

#include <neuralnet/Layer.hpp>
#include "testSynapse.hpp"

#include <linalg/linalg.h>

// functions for quickly defining test cases for test suites 
// without dying in the process
std::pair<linalg::vec<double, 2>, linalg::vec<bool, 3>> testCase1
    (linalg::vec<double, 2> input, linalg::vec<bool, 3> res) {

    return std::make_pair(input, res);
}

int main() {

    synnet::Layer<linalg::vec<bool, 3>, 3, 2> l(
        {{0, 1, -1}, {-1, 0, 100}}, 
        {0.55, -240, 150}, 
        [](linalg::vec<double, 3> vec) -> linalg::vec<bool, 3> { 
            return linalg::apply([](double v) {
                std::cout << v << std::endl;
                return v >= 0;
            }, vec);
        }
    );

    synunittest::unitTestLayer<linalg::vec<bool, 3>, 3, 2> unittest(l);
    unittest.performUnitTestSuite({
        testCase1({200, 0.2}, {true, false, false}),
        testCase1({150, 0.8}, {false, false, true}),
        testCase1({300, 0.8}, {false, true, false})
    });
    return 0;
}