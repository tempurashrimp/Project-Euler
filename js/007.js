
/*  Problem 007:
    By listing the first six prime numbers: 2, 3, 5, 7, 11
    and 13, we can see that the 6th prime is 13. What is the
    10000th prime number? */

function solution(n) {
    // The function takes one input n, which represents the
    // nth prime number.

    // Skip the first three primes.
    let prime = 5;
    let count = 3;

    while (count < n) {
        prime++;
        if (isPrime(prime)) {
            count++;
        }
    }
    
    return prime;
}

// Function to check for primes
function isPrime(n) {    
    // The function takes one input n, which is
    // to be verified as a prime number.

    // Cases when the 6k + 1 or 6k - 1 property does not hold.
    // Actually since we are interested in the 10001th prime we
    // do not really need these cases.
    /*
    if (n == 1) {
        return false;
    } else if (n < 4) {
        return true;
    } else if (n == 4) {
        return false;
    } */

    // For primes 2 and 3
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    
    }

    // For n >= 5:
    for (let i = 5; i * i <= n; i++) {
        if (n % i == 0 || n % (i + 2) == 0) {
            // n is composite
            return false;
        }
    }

    // n is prime
    return true;
}

// Solved 20th July 2025.