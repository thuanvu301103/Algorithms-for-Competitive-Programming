#include "./algebra/prime/test_sieve.cpp"

int main() {
    test_sieve_basic();
    test_sieve_till_root();
    test_sieve_by_odd();
    test_segmented_sieve();
    test_find_primes_in_range();
    return 0;
}