#include <iostream>
#include <vector>
#include <cstdlib>

#include "NeuralNetwork.h"


int main() {
	NeuralNetwork nn {{2, 2, 1}};
	srand(time(nullptr));

	for (size_t i {0}; i < 100000; ++i) {
		float a {static_cast<float>(rand() % 10)};
		float b {static_cast<float>(rand() % 10)};

		std::vector<float> input {a, b};
		std::vector<float> output {3 * (a + 2) + 2 * (b + 8) + 5};

		nn.propagateBackwards(input, output);
	}

	for (size_t i {0}; i < 50; ++i) {
		float a {static_cast<float>(rand() % 10)};
		float b {static_cast<float>(rand() % 10)};

		std::vector<float> input {a, b};
		std::vector<float> output {3 * (a + 2) + 2 * (b + 8) + 5};

		std::cout << "f(" << a << ", " << b << ") = " << 3 * (a + 2) + 2 * (b + 8) + 5
		          << " (predicted: " << nn.feedforward(input)[0] << ", loss: "
		          << NeuralNetwork::error(Matrix {nn.feedforward(input)}, Matrix {output}) << ")" << std::endl;
	}

	return 0;
}
