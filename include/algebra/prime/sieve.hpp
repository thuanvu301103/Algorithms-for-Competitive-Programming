#pragma once
/**
 * @file sieve.hpp
 * @brief Contains the declaration of functions related to prime number computation,
 *        including the Sieve of Eratosthenes algorithm.
 *
 * @namespace algebra::prime
 * Provides utilities for prime number generation and operations.
 */

#include <vector>

namespace algebra::prime {

    /**
     * @brief Generates all prime numbers up to a given limit using the Sieve of Eratosthenes.
     *
     * The function efficiently finds all primes ≤ n by marking the multiples of each prime
     * starting from 2. Time complexity is approximately O(n log log n).
     *
     * @param n Upper bound (inclusive) for prime generation.
     * @return A vector containing all prime numbers ≤ n in ascending order.
     *
     * @example
     * std::vector<int> primes = algebra::prime::sieve(50);
     * // primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}
     */
    std::vector<int> sieve(int n);

}
