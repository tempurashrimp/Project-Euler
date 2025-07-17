
/*  Problem 003: 
    The prime factors of 13195 are 5, 7, 13 and 29. 
    What is the largest prime factor of 600851475143? */
#include <iostream>
using namespace std;

#define num unsigned long long int

num solution(num n) {
    // The function takes one input n, which is the number
    // we want to find the largest prime factor of.
    num largestPrime = 1;

    // Start by repeatedly dividing n by 2
    while (n % 2 == 0) {
        largestPrime = 2;
        n /= 2;
    }

    // Repeat the same procedure for 3
    while (n % 3 == 0) {
        largestPrime = 3;
        n /= 3;
    }

    // Divide by numbers in the form (6k + 1) or (6k - 1),
    // as every prime number (except 2 or 3) can be expressed such.
    // The smallest prime that follows this form is 5.
    // (Hence, why we first brute-force 2 and 3)
    for (num m = 5; (m * m) <= n; m += 6) {
        while (n % m == 0) {
            largestPrime = m;
            n /= m;
        }

        while (n % (m + 2) == 0) {
            largestPrime = m + 2;
            n /= (m + 2);
        }
    }

    // Whatever remains of n (given n >= 3) must then be the largest prime.
    if (n > 4) {
        return n;
    } else {
        return largestPrime;
    }
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Largest prime factor of "
        << n << " is " << solution(n) << endl;

    return 0;
}

// Solved 18th July 2025.