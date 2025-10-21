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

        for (long long unsigned int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                for (long long unsigned int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        for (long long unsigned int i = 2; i <= n; ++i)
            if (isPrime[i]) primes.push_back(i);

        return primes;
    }

    std::vector<long long unsigned int> sieve_till_root(long long unsigned int n) {
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

    std::vector<long long unsigned int> sieve_by_odd(long long unsigned int n) {
        std::vector<long long unsigned int> primes;
        if (n < 2) return primes;

        primes.push_back(2);
        if (n == 2) return primes;

        long long unsigned int size = (n - 1) / 2;
        std::vector<bool> isPrime(size, true);

        long long unsigned int limit = static_cast<long long unsigned int>(std::sqrt(n));

        for (long long unsigned int i = 0; (2 * i + 3) <= limit; ++i) {
            if (isPrime[i]) {
                long long unsigned int p = 2 * i + 3;
                for (long long unsigned int j = (p * p - 3) / 2; j < size; j += p)
                    isPrime[j] = false;
            }
        }

        for (long long unsigned int i = 0; i < size; ++i)
            if (isPrime[i])
                primes.push_back(2 * i + 3);
    
        return primes;
    }

    std::vector<long long unsigned int> segmented_sieve(long long unsigned int n, long long unsigned int S) {
        std::vector<long long unsigned int> primes;
        if (n < 2) return primes;

        long long unsigned int limit = static_cast<long long unsigned int>(std::sqrt(n));
        std::vector<long long unsigned int> basePrimes = sieve_by_odd(limit);

        if (n >= 2) {
            primes.push_back(2);
        }
    
        long long unsigned int low = 3; 
        long long unsigned int high = std::min(low + S - 1, n);

        while (low <= n) {
            std::vector<bool> isPrime(high - low + 1, true);

            for (long long unsigned int p : basePrimes) {
                if (p * p > high) break;
            
                long long unsigned int start = std::max(p * p, ((low + p - 1) / p) * p);

                if (start % 2 == 0) {
                    start += p;
                }

                for (long long unsigned int j = start; j <= high; j += p * 2) {
                    isPrime[j - low] = false;
                }
            }

            for (long long unsigned int i = low; i <= high; i += 2) {
                if (isPrime[i - low]) {
                    primes.push_back(i);
                }
            }

            low = high + 1; 
            if (low % 2 == 0) low++;
            high = std::min(low + S - 1, n);
        }

        return primes;
    }

    std::vector<long long unsigned int> find_primes_in_range(long long unsigned int L, long long unsigned int R) {
        long long unsigned int lim = std::sqrt(R);
        std::vector<char> mark(lim + 1, false);
        std::vector<long long> base_primes;

        for (long long unsigned int i = 2; i <= lim; ++i) {
            if (!mark[i]) {
                base_primes.emplace_back(i);
                for (long long unsigned int j = i * i; j <= lim; j += i)
                    mark[j] = true;
            }
        }

        std::vector<char> isPrime(R - L + 1, true);

        for (long long unsigned int p : base_primes) {
            long long start = std::max(p * p, ((L + p - 1) / p) * p);
            for (long long unsigned int j = start; j <= R; j += p)
                isPrime[j - L] = false;
        }

        if (L == 1)
            isPrime[0] = false;

        std::vector<long long unsigned int> primes;
        for (long long unsigned int i = L; i <= R; ++i) {
            if (isPrime[i - L])
                primes.emplace_back(i);
        }

        return primes;
    }
}