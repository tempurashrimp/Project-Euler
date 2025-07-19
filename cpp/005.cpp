
/*  Problem 005 
    2520 is the smallest number that can be divided by each of the numbers 
    from 1 to 10 without any remainder. What is the smallest positive number 
    that is evenly divisible by all of the numbers from 1 to 20? */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using num = unsigned long long;

// Function to check for primes
inline bool isPrime(num n) {    
    // The function takes one input n, which is
    // to be verified as a prime number.
    for (num i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // n is composite
            return false;
        }
    }

    // n is prime
    return true;
}

num solution(num n) {
    // The function takes one input n, which is the
    // highest multiple we wish to consider.
    vector<num> primes;
    num highestMultiple = 1;

    // Check every single prime.
    for (num i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    // Compute the powers of each prime.
    for (num p : primes) {
        highestMultiple *= pow(p, floor(
            (log(n) / log(p))));
    };

    return highestMultiple;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Largest number evenly divisible by 1 through "
        << n << " is " << solution(n) << endl;

    return 0;
}

// Solved 19th July 2025.