
/*  Problem 005 
    2520 is the smallest number that can be divided by each of the numbers 
    from 1 to 10 without any remainder. What is the smallest positive number 
    that is evenly divisible by all of the numbers from 1 to 20? */

function solution(n) {
    // The function takes one input n, which is the
    // highest multiple we wish to consider.
    let primes = [];
    let highestMultiple = 1;

    // Check every single prime.
    for (let i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push(i);
        }
    }

    // Compute the powers of each prime.
    primes.forEach(function(p) {
        highestMultiple *= Math.pow(p, Math.floor(
            (Math.log(n) / Math.log(p))));
    });

    return highestMultiple;
}

// Function to check for primes
function isPrime(n) {    
    // The function takes one input n, which is
    // to be verified as a prime number.
    for (let i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // n is composite
            return false;
        }
    }

    // n is prime
    return true;
}

// Solved 19th July 2025.