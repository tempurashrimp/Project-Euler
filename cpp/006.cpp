
/*  Problem 006:
    The sum of the squares of the first ten natural numbers is,
    1^2 + 2^2 + ... + 10^2 = 385.
    The square of the sum of the first ten natural numbers is,
    (1 + 2 + ... +10)^2 = 3025.
    Hence the difference between the sum of the squares of the first 
    ten natural numbers and the square of the sum is 3025 - 385 = 2640. 
    Find the difference between the sum of the squares of the first 
    one hundred natural numbers and the square of the sum */
#include <iostream>
using namespace std;

using num = unsigned long long;

num solution(num n) {
    // The function takes one input n, which is what we
    // sum up (the squares) until.
    // All our calculations are based on summation formulae.
    num sumSquares = n * (n + 1) * (2 * n + 1) / 6;
    num squaresSum = n * (n + 1) / 2;
    squaresSum *= squaresSum;

    return squaresSum - sumSquares;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Difference of the sum of squares until " << n 
        << " and the square of the sum is " << solution(n) << endl;

    return 0;
}

// Solved 20th July 2025.