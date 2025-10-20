#include <iostream>
#include "../../../include/algebra/prime/sieve.hpp"

using namespace algebra::prime;

void test_sieve_basic() {
    std::vector<long long unsigned int> expected = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<long long unsigned int> result = sieve(20);

    if (result != expected) {
        std::cerr << "Test failed: sieve(20)\n";
    } else {
        std::cout << "Test passed: sieve(20)\n";
    }
}