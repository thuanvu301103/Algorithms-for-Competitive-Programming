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
    std::vector<long long unsigned int> sieve(long long unsigned int n);

    /**
     * @brief Generates all prime numbers up to the square root of a given limit using the Sieve of Eratosthenes.
     *
     * This function is similar to `sieve(n)`, but it only computes primes ≤ √n.  
     * It is particularly useful in algorithms such as prime factorization or segmented sieve,
     * where only primes up to √n are needed to process larger ranges efficiently.
     *
     * Time complexity: approximately O(√n log log √n).
     *
     * @param n Upper bound for which primes are needed (the sieve runs up to √n).
     * @return A vector containing all prime numbers ≤ √n in ascending order.
     *
     * @example
     * std::vector<int> primes = algebra::prime::sieve_till_root(100);
     * // primes = {2, 3, 5, 7}
     */
    std::vector<long long unsigned int> sieve_till_root(long long unsigned int n);

    /**
     * @brief Generates all prime numbers up to a given limit using an optimized Sieve of Eratosthenes that skips even numbers.
     *
     * This function improves memory and time efficiency compared to the standard `sieve(n)` 
     * by ignoring even numbers (except 2). It stores and processes only odd numbers, 
     * effectively halving the sieve space and iteration count.
     *
     * Time complexity: approximately O(n log log n), but with reduced constant factors.
     *
     * @param n Upper bound (inclusive) for prime generation.
     * @return A vector containing all prime numbers ≤ n in ascending order.
     *
     * @example
     * std::vector<int> primes = algebra::prime::sieve_by_odd(50);
     * // primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}
     */
    std::vector<long long unsigned int> sieve_by_odd(long long unsigned int n);

    /**
     * @brief Generates all prime numbers up to a given limit using the segmented sieve algorithm.
     *
     * This function efficiently finds all prime numbers ≤ n by dividing the range [2, n] into smaller
     * continuous blocks (segments) of size S. Each block is processed independently using a list of
     * base primes (those ≤ √n), which allows handling very large upper bounds without excessive memory usage.
     *
     * The segmented sieve is particularly useful when n is too large to fit an entire sieve array
     * in memory, such as n ≥ 10⁸. Unlike the traditional sieve, it only stores a portion of the range
     * at any time, reducing memory complexity from O(n) to approximately O(√n + S), where S is the
     * segment size.
     *
     * A larger S reduces the number of segment iterations (faster) but increases memory usage,
     * while a smaller S uses less memory but may run slightly slower due to more iterations.
     *
     * Time complexity: approximately O(n log log n).
     *
     * @param n Upper bound (inclusive) for prime generation.
     * @param S Segment size — number of integers processed per block (default suggestion: 10,000 to 1,000,000).
     * @return A vector containing all prime numbers ≤ n in ascending order.
     *
     * @example
     * std::vector<int> primes = algebra::prime::segmented_sieve(100, 10000);
     * // primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}
     */
    std::vector<long long unsigned int> segmented_sieve(long long unsigned int n, long long unsigned int S);

    /**
     * @brief Finds all prime numbers within a given interval [L, R] using the segmented sieve method.
     *
     * This function generates all prime numbers in the specified range [L, R], inclusive,
     * without computing all primes up to R. It first computes all base primes up to √R
     * (using a traditional sieve or a precomputed list), then uses these base primes to
     * mark non-prime numbers in the current segment [L, R].
     *
     * This approach is efficient for querying primes in large numeric ranges, such as
     * [10⁹, 10⁹ + 10⁶], where building a full sieve up to R would be infeasible.
     *
     * Time complexity: approximately O((R − L + 1) log log R)
     * Space complexity: O(√R + (R − L + 1))
     *
     * @param L Lower bound (inclusive) of the search interval.
     * @param R Upper bound (inclusive) of the search interval.
     * @return A vector containing all prime numbers within the range [L, R].
     *
     * @example
     * std::vector<int> primes = algebra::prime::find_primes_in_range(10, 50);
     * // primes = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}
     */
    std::vector<long long unsigned int> find_primes_in_range(long long unsigned int L, long long unsigned int R);
}
