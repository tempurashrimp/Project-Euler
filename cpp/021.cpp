
/*  Problem 021:
    Let d(n) be defined as the sum of proper divisors of n 
    (numbers less than n which divide evenly into n).
    If d(a) = b and d(b) = a, where a =/= b, then a and b are 
    an amicable pair and each of a and b are called amicable numbers.
    For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
    therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
    Evaluate the sum of all the amicable numbers under 10000. */

#include "PrimeSieve.h"
#include <algorithm>
#include <set>

inline num d(num n) {
    // The function takes one input n, which the function
    // computes the factors of.
    num sum = 0;

    // TODO: use PrimeSieve to factorize
    for (size_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            // i is a factor of n
            sum += i; 

            if (n / i != i) {
                sum += n / i;
            }
        }
    }

    // Since n is repeated
    return sum - n;
}

num solution(num n) {
    // The function takes one input n, which is the highest
    // possible amicable number.
    PrimeSieve sieve;

    set<num> amicable;
    num amicableSum = 0;

    // Prime numbers cannot be amicable.
    // Also 1 is not amicable since d(1) = 1 = d(1).
    while (n > sieve.primes.back()) {
        sieve.extend();
    }

    vector<num> range(n - 1);
    iota(range.begin(), range.end(), 1);
    
    vector<num> nonPrimes;
    set_difference(range.begin(), range.end(),
                    sieve.primes.begin(), sieve.primes.end(), 
                    inserter(nonPrimes, nonPrimes.begin()));

    range.clear();

    for (num a : nonPrimes) {
        num b = d(a);

        if (a != b && d(b) == a) {
            amicable.insert(a);
            
            // b can be greater than n
            if (b < n) {
                amicable.insert(b);
            }
        }
    }

    for (num i : amicable) {
        amicableSum += i;
    }

    return amicableSum;
}


int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Sum of amicable numbers under "
        << n << " is " << solution(n) << endl;

    return 0;
}

// Solved 7th August 2025.