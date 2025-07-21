
/*  Problem 009:
    A Pythagorean triplet is a set of three natural numbers, a<b<c, for which,
    a^2 + b^2 = c^2  For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc. */

#include <iostream>
using namespace std;

using num = unsigned long long;
num solution(num k) {
    // The function takes one input k, which represents the
    // number we wish to find the Pythagorean triplet for.
    num sumOfABC = 0, productOfABC = 0;
    num m = 2, n = 1;
    // Halt computation if m exceeds this number.
    const num maxNumber = 1000000;

    while (sumOfABC != k && m <= maxNumber) {
        // By Euclid's formula, recursively generate
        // Pythagorean triples (without a need to verify.)
        num a = (m * m) - (n * n), b = 2 * m * n,
            c = (m * m) + (n * n);

        sumOfABC = a + b + c;
        productOfABC = a * b * c;

        // m > n > 0.
        n++;
        if (m <= n) {
            m++;
            n = 1;
        }
    }

    if (m > maxNumber) {
        throw "Unable to find Pythagorean Triplet.";
        return 1;
    }

    return productOfABC;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;

    cout << "The product of the Pythagorean triplet with the sum of "
        << n << " is " << solution(n) << endl;

    return 0;
}

// Solved 21st July 2025.