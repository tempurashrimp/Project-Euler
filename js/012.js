import { PrimeSieve } from "./PrimeSieve";

function solution(n) {
    // The function takes one input n, which represents the
    // number of factors in our smallest triangle number
    let sieve = new PrimeSieve();

    // Generate triangle numbers
    let triangle = 1, numFactors = 1, exponent = 0;
    let primePowers = [];

    // Note that primePowers does not have to be ordered such that,
    // each exponent corresponds to each prime in sieve.primes
    // as we are only interested in the exponents.
    for (let i = 1; true; ++i) {
        primePowers = [];
        triangle = (i * (i + 1)) / 2;

        // Factorize triangle numbers
        if (Math.sqrt(triangle) >= sieve.primes[sieve.primes.length - 1]) {
            sieve.extend();
        }

        sieve.primes.forEach((prime) => function() {
            exponent = 0;
            // prime is a factor of triangle
            while (triangle % prime == 0) {
                exponent++;
                triangle /= prime;
            }

            if (exponent) {
                primePowers.push(exponent);
            }
        }());

        triangle = (i * (i + 1)) / 2;
        // Evaluate numFactors
        primePowers.forEach((power) => numFactors *= (power + 1));

        if (numFactors >= n) {
            return triangle;
        } else {
            numFactors = 1;
        }
    }
}

// Solved 24th July 2025.