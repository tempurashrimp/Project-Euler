
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

import { PrimeSieve } from "./PrimeSieve";

let sieve = new PrimeSieve();
let primes = new Map();
let primesUnderOneThousand = [];
let lastPrime = 0;

function initialize() {
    // Since the maximum value of b is 1000, for the term at n = 0
    // to be prime, we only need to consider prime values for b.
    while (sieve.primes[sieve.primes.length - 1] < 1000) {
        sieve.extend();
    }

    primesUnderOneThousand = sieve.primes.filter(p => p < 1000);

    // Pre-compute primes and store them in a hash-map to speed up ease of checking.
    while (sieve.primes[sieve.primes.length - 1] < 1000000) {
        sieve.extend();
    }

    for (const prime of sieve.primes) {
        primes.set(prime, true);
    }
}


function isPrime(n) {
    // In case the number is greater than the last prime, extend the list of primes.
    if (n < 2) {
        return false;
    }

    while (n > lastPrime) {
        let lastIndex = sieve.primes.length - 1;
        sieve.extend();

        for (let i = lastIndex; i < sieve.primes.length; ++i) {
            primes[sieve.primes[i]] = true;
        }

        lastPrime = sieve.primes[sieve.primes.length - 1];
    }

    // Prime is found
    if (primes.has(n)) {
        return true;
    }

    return false;
}


function quadratic(a, b) {
    // Compute the number of consecutive primes for any given a or b.
    let n = 0;
    
    while (isPrime((n * n) + (a * n) + b)) {
        n++;
    }

    return n;
}


function solution() {
    initialize();

    let longestA = 0, longestB = 0;
    let longestSequence = 0;

    for (const b of primesUnderOneThousand) {
        for (let a = 1 - b; a < 1000; ++a) {
            let sequence = quadratic(a, b);

            if (sequence > longestSequence) {
                longestSequence = sequence;
                longestA = a, longestB = b;
            }
        }
    }

    return longestA * longestB;
}

// Solved 27th August 2025.