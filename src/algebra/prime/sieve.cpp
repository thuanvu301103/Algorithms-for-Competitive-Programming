/**
 * @file sieve.cpp
 * @brief Implementation of prime number algorithms defined in sieve.hpp
 */

#include "../include/algebra/prime/sieve.hpp"
#include <cmath>

namespace algebra::prime {

    std::vector<int> sieve(int n) {
        std::vector<int> primes;
        if (n < 2) return primes;

        std::vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= n; ++i)
            if (isPrime[i]) primes.push_back(i);

        return primes;
    }

}
