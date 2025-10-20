/**
 * @file sieve.cpp
 * @brief Implementation of prime number algorithms defined in sieve.hpp
 */

#include "../../../include/algebra/prime/sieve.hpp"
#include <cmath>

namespace algebra::prime {

    std::vector<long long unsigned int> sieve(long long unsigned int n) {
        std::vector<long long unsigned int> primes;
        if (n < 2) return primes;

        std::vector<bool> isPrime(static_cast<size_t>(n + 1), true);
        isPrime[0] = isPrime[1] = false;

        for (long long unsigned int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (long long unsigned int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        for (long long unsigned int i = 2; i <= n; ++i)
            if (isPrime[i]) primes.push_back(i);

        return primes;
    }

}
