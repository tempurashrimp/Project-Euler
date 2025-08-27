
/*  Problem 027:
    Euler discovered the remarkable quadratic formula n^2 + n + 41.
    It turns out that the formula will produce 40 primes for the consecutive integer values 
    0 <= n <= 39. However, when n = 40,  40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, 
    and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
    The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the 
    consecutive values 0 <= n <= 79. The product of the coefficients -79, and 1601, is
    -126479. Considering quadratics of the form n^2 + an + b, |a| < 1000 and |b| <= 1000,
    Find the product of the coefficients, a and b, for the quadratic expression that produces
    the maximum number of primes for consecutive values of n, starting with n = 0. */

#include "PrimeSieve.h"
#include <unordered_map>
#include <algorithm>

static PrimeSieve sieve;
static unordered_map<num, bool> primes;
static vector<num> primesUnderOneThousand;
static num lastPrime;

void initialize(void) {
    // Since the maximum value of b is 1000, for the term at n = 0
    // to be prime, we only need to consider prime values for b.
    while (sieve.primes.back() < 1000) {
        sieve.extend();
    }

    copy(sieve.primes.begin(), sieve.primes.end(), 
    back_inserter(primesUnderOneThousand));
    primesUnderOneThousand.erase(
    remove_if(primesUnderOneThousand.begin(), primesUnderOneThousand.end(),
        [](num p) { 
            return p > 1000;
        }), primesUnderOneThousand.end()
    );


    // Pre-compute primes and store them in a hash-map to speed up ease of checking.
    while (sieve.primes.back() < 1000000) {
        sieve.extend();
    }

    for (num prime: sieve.primes) {
        primes[prime] = true;
    }

    lastPrime = sieve.primes.back();
}


inline bool isPrime(int n) {
    // In case the number is greater than the last prime, extend the list of primes.
    if (n < 2) {
        return false;
    }

    while (n > lastPrime) {
        size_t lastIndex = sieve.primes.size() - 1;
        sieve.extend();

        for (size_t i = lastIndex; i < sieve.primes.size(); ++i) {
            primes[sieve.primes[i]] = true;
        }

        lastPrime = sieve.primes.back();
    }

    // Prime is found
    if (primes.count(n)) {
        return true;
    }

    return false;
}


num quadratic(int a, int b) {
    // Compute the number of consecutive primes for any given a or b.
    num n = 0;

    while (isPrime((n * n) + (a * n) + b)) {
        n++;
    }

    return n;
}


void solution() {
    initialize();

    int longestA = 0, longestB = 0;
    num longestSequence = 0;

    for (num b : primesUnderOneThousand) {
        for (int a = 1 - b; a < 1000; ++a) {
            num sequence = quadratic(a, b);

            if (sequence > longestSequence) {
                longestSequence = sequence;
                longestA = a, longestB = b;
            }
        }
    }

    cout << "The quadratic equation that satisfies the problem condition is ";
    cout << "n^2 + (" << longestA << ") + " << longestB;
    cout << ", and the product of coefficients is " << (longestA * longestB) << endl;
}


int main(void) {
    solution();

    return 0;
}

// Solved 27th August 2025.