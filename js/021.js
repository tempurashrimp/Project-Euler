
/* Problem 021:
    Let d(n) be defined as the sum of proper divisors of n 
    (numbers less than n which divide evenly into n).
    If d(a) = b and d(b) = a, where a =/= b, then a and b are 
    an amicable pair and each of a and b are called amicable numbers.
    For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
    therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
    Evaluate the sum of all the amicable numbers under 10000. */

import { PrimeSieve } from "./PrimeSieve";

function d(n) {
    let sum = 0;

    // TODO: use PrimeSieve to factorize
    for (let i = 1; i * i <= n; i++) {
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

function solution(n) {
    let sieve = new PrimeSieve();

    let amicable = [];
    let amicableSum = 0;

    // Prime numbers cannot be amicable.
    // Also 1 is not amicable since d(1) = 1 = d(1).
    while (n > sieve.primes[sieve.primes.length - 1]) {
        sieve.extend();
    }

    let range = [...Array(n - 2).keys()].map(i => i + 1);
    let nonPrimes = range.filter(prime => !sieve.primes.includes(prime));

    nonPrimes.forEach(a => function () {
        let b = d(a);

        if (a != b && d(b) == a) {
            amicable.push(a);

            // b can be greater than n
            if (b < n) {
                amicable.push(b);
            }
        }
    }());

    // Drop duplicates
    amicable = new Set(amicable);
    amicable.forEach(i => (amicableSum += i));
    return amicableSum;
}

// Solved 7th August 2025.