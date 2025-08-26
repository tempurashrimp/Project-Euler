
/*  Problem 010:
    The sum of the primes below 10 is 2+3+5+7=17. Find the sum 
    of all the primes below two million. */

import { PrimeSieve } from "./PrimeSieve";

function solution(n) {
    // The function takes one input n, which represents the
    // limit where we sum prime numbers under.
    let primeSum = 0;
    let sieve = new PrimeSieve();

    while (n > sieve.primes[sieve.primes.length - 1]) {
        sieve.extend();
    }

    sieve.primes.forEach(prime => {
        if (prime < n) {
            primeSum += prime;
        }
    }); 

    return primeSum;
}

// Solved 22nd July 2025.
// Modified (1st time) 23rd July 2025.