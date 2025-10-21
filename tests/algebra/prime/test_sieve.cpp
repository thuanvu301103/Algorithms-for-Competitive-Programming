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

void test_sieve_till_root() {
    std::vector<long long unsigned int> expected = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<long long unsigned int> result = sieve_till_root(20);

    if (result != expected) {
        std::cerr << "Test failed: sieve_till_root(20)\n";
    } else {
        std::cout << "Test passed: sieve_till_root(20)\n";
    }
}

void test_sieve_by_odd() {
    std::vector<long long unsigned int> expected = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<long long unsigned int> result = sieve_by_odd(20);

    if (result != expected) {
        std::cerr << "Test failed: sieve_by_odd(20)\n";
    } else {
        std::cout << "Test passed: sieve_by_odd(20)\n";
    }
}

void test_segmented_sieve() {
    std::vector<long long unsigned int> expected = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<long long unsigned int> result = segmented_sieve(20, 5);

    if (result != expected) {
        std::cerr << "Test failed: segmented_sieve(20, 5)\n";
    } else {
        std::cout << "Test passed: segmented_sieve(20, 5)\n";
    }
}

void test_find_primes_in_range() {
    std::vector<long long unsigned int> expected = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    std::vector<long long unsigned int> result = find_primes_in_range(10, 50);

    if (result != expected) {
        std::cerr << "Test failed: find_primes_in_range(10, 50)\n";
    } else {
        std::cout << "Test passed: find_primes_in_range(10, 50)\n";
    }
}