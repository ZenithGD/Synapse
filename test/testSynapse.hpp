#ifndef __TESTSYNAPSE_H__
#define __TESTSYNAPSE_H__

// Standard libraries
#include <iostream>
#include <vector>
#include <chrono>

// Main libraries
#include <neuralnet/Neuron.hpp>
#include <neuralnet/Layer.hpp>

// Vendor libraries
#include <linalg/linalg.h>

// Constants
const std::string ANSI_GREEN   = "\u001b[32m";
const std::string ANSI_RED     = "\u001b[31m";
const std::string ANSI_YELLOW  = "\u001b[33m";
const std::string ANSI_MAGENTA = "\u001b[35m";
const std::string ANSI_NONE    = "\u001b[0m";

namespace synunittest {

    // Improve/refactor for test class hierarchy
    template <typename T, int N>
    class unitTestNeuron
    {
    private:
        // Neuron under test
        synnet::Neuron<T, N>& _neuron;

        // Performs one unit test based on input and expected output.
        bool performUnitTest(const linalg::vec<double, N> input, T expectedOutput) noexcept {
            bool result;
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

            try {
                auto r = _neuron.output(input);
                result = r == expectedOutput;
                if ( result ) {
                    std::cout << ANSI_GREEN << "[PASSED] " 
                        << "->> " << r << ANSI_NONE << std::endl;
                } else {
                    std::cout << ANSI_RED << "[FAILED] " 
                        << "->> " << r << ", expected" << expectedOutput << ANSI_NONE << std::endl;
                }
            } catch ( std::exception& xc ) {
                std::cout << ANSI_YELLOW << "[EXCEPTION] " << xc.what() << ANSI_NONE << std::endl;
                result = false;
            }
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            std::cout << "Time elapsed (sec) = " << diff / 1000000.0 << std::endl;
            return result;
        }
    public:
        unitTestNeuron(synnet::Neuron<T, N>& n)
            : _neuron(n) {}

        // Performs a suite of tests based on input and expected output pairs
        // and outputs basic stats.
        bool performUnitTestSuite(const std::vector<std::pair<linalg::vec<double, N>, T>> testsuite) {
            unsigned int passed = 0;
            ssize_t testsize = testsuite.size();
            for ( unsigned int i = 0; i < testsize; ++i ) {
                std::cout << "<============================>" << std::endl;
                std::cout << ANSI_MAGENTA << "Test " << i << ANSI_NONE << std::endl; 
                std::cout << "<============================>" << std::endl;
                if ( performUnitTest(testsuite[i].first, testsuite[i].second) ) {
                    passed++;
                }
            }

            return passed == testsize;
        }
    };
    
    template <typename T, int M, int N>
    class unitTestLayer
    {
    private:
        // Neuron under test
        synnet::Layer<T, M, N>& _layer;

        // Performs one unit test based on input and expected output.
        bool performUnitTest(const linalg::vec<double, N> input, T expectedOutput) noexcept {
            bool result;
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

            try {
                auto r = _layer.output(input);
                result = r == expectedOutput;
                if ( result ) {
                    std::cout << ANSI_GREEN << "[PASSED] " 
                        << "->> " << r << ANSI_NONE << std::endl;
                } else {
                    std::cout << ANSI_RED << "[FAILED] " 
                        << "->> " << r << ", expected" << expectedOutput << ANSI_NONE << std::endl;
                }
            } catch ( std::exception& xc ) {
                std::cout << ANSI_YELLOW << "[EXCEPTION] " << xc.what() << ANSI_NONE << std::endl;
                result = false;
            }
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            std::cout << "Time elapsed (sec) = " << diff / 1000000.0 << std::endl;
            return result;
        }
    public:
        unitTestLayer(synnet::Layer<T, M, N>& n)
            : _layer(n) {}

        // Performs a suite of tests based on input and expected output pairs
        // and outputs basic stats.
        bool performUnitTestSuite(const std::vector<std::pair<linalg::vec<double, N>, T>> testsuite) {
            unsigned int passed = 0;
            ssize_t testsize = testsuite.size();
            for ( unsigned int i = 0; i < testsize; ++i ) {
                std::cout << "<============================>" << std::endl;
                std::cout << ANSI_MAGENTA << "Test " << i << ANSI_NONE << std::endl; 
                std::cout << "<============================>" << std::endl;
                if ( performUnitTest(testsuite[i].first, testsuite[i].second) ) {
                    passed++;
                }
            }

            return passed == testsize;
        }
    };
}

#endif // __TESTSYNAPSE_H__