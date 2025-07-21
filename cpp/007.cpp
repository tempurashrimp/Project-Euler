
/*  Problem 007:
    By listing the first six prime numbers: 2, 3, 5, 7, 11
    and 13, we can see that the 6th prime is 13. What is the
    10000th prime number? */
#include <iostream>
using namespace std;

using num = unsigned long long;

// Function to check for primes
inline bool isPrime(num n) {    
    // The function takes one input n, which is
    // to be verified as a prime number.
    // Note that n > 3.

    // For primes 2 and 3
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    
    }

    // For larger primes
    for (num i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            // n is composite
            return false;
        }
    }

    // n is prime
    return true;
}

num solution(num n) {
    // The function takes one input n, which represents the
    // nth prime number.

    // Skip the first three primes.
    num prime = 5;
    num count = 3;
    
    while (count < n) {
        prime++;
        if (isPrime(prime)) {
            count++;
        }
    }
    
    return prime;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;

    // Pardon the grammatical inaccuracy.
    cout << "The " << n << "th prime is " << solution(n) << endl;

    return 0;
}

// Solved 20th July 2025.