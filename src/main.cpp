#include <iostream>

#include <neuralnet/Neuron.hpp>

int main() {

    synnet::Neuron<bool> neuron({-1, 0}, 225, 
        [](double v) -> bool { return v > 0; });

    std::cout << neuron.output(synmath::SynVector({150, 0.8})) << std::endl;
    std::cout << neuron.output(synmath::SynVector({260, 0.8})) << std::endl;
    return 0;
}