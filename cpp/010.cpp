
/*  Problem 010:
    The sum of the primes below 10 is 2+3+5+7=17. Find the sum 
    of all the primes below two million. */

#include <iostream>
#include <vector>
#include "PrimeSieve.h"

num solution(num n) {
    // The function takes one input n, which represents the
    // limit where we sum prime numbers under.
    num primeSum = 0;
    PrimeSieve sieve;

    while (sieve.primes.back() < n) {
        sieve.extend();
    } 

    for (num prime: sieve.primes) {
        if (prime < n) {
            primeSum += prime;
        } else {
            break;
        }
    }

    return primeSum;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;

    cout << "The sum of prime numbers under " << n 
    << " is " << solution(n) << endl;

    return 0;
}

// Solved 22nd July 2025.
// Modified (1st time) 23rd July 2025.