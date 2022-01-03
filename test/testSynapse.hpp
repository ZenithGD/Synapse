#pragma once

// Standard libraries
#include <iostream>
#include <vector>
#include <chrono>

// Main libraries
#include <neuralnet/Neuron.hpp>
#include <neuralnet/Layer.hpp>

// Vendor libraries
#include <linalg/linalg.h>
using namespace linalg::ostream_overloads;

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
        syn::Neuron<T, N>& _neuron;

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
        unitTestNeuron(syn::Neuron<T, N>& n)
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
        syn::Layer<T, M, N>& _layer;

        // Performs one unit test based on input and expected output.
        bool performUnitTest(const linalg::vec<double, N> input, linalg::vec<T, M> expectedOutput) noexcept {
            return performFunctionUnitTest<T>(input, [](T v){return v;}, expectedOutput);
        }

        // Performs one unit test based on input and expected output after 
        // applying a function over every element in the output.
        template <typename R>
        bool performFunctionUnitTest(const linalg::vec<double, N> input, 
            const std::function<R(T)> fn, const linalg::vec<R, M> expectedOutput) noexcept {
            bool result;
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

            try {
                auto r = linalg::apply(fn, _layer.output(input));
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
        unitTestLayer(syn::Layer<T, M, N>& n)
            : _layer(n) {}

        // Performs a suite of tests based on input and expected output pairs
        // and outputs basic stats.
        bool performUnitTestSuite(const std::vector<std::pair<linalg::vec<double, N>, linalg::vec<T, M>>> testsuite) {
            return performFunctionUnitTestSuite<T>(testsuite, [](T v) { return v; });
        }

        // Performs a suite of tests based on input and expected output pairs
        // and outputs basic stats.
        template <typename R>
        bool performFunctionUnitTestSuite(const std::vector<std::pair<linalg::vec<double, N>, linalg::vec<R, M>>> testsuite,
            const std::function<R(T)> fn) {
            unsigned int passed = 0;
            ssize_t testsize = testsuite.size();
            for ( unsigned int i = 0; i < testsize; ++i ) {
                std::cout << "<============================>" << std::endl;
                std::cout << ANSI_MAGENTA << "Test " << i << ANSI_NONE << std::endl; 
                std::cout << "<============================>" << std::endl;
                if ( performFunctionUnitTest<R>(testsuite[i].first, fn, testsuite[i].second) ) {
                    passed++;
                }
            }
            return passed == testsize;
        }
    };
}
