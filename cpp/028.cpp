
/*  Problem 028:
    Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 
    spiral is formed as follows:
    21 22 23 24 25
    20  7  8  9 10
    19  6  1  2 11
    18  5  4  3 12
    17 16 15 14 13
    It can be verified that the sum of the numbers on the diagonals is 101. What is the sum 
    of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way? */

#include <iostream>

using num = unsigned long long;
using namespace std;

num solution(num n) {
    // The function takes one input n, which represents the
    // dimension of the spiral.

    if (!(n % 2)) {
        cout << " [Dimension must be odd.] ";
        return 0;
    }

    // From the working, we obtain the formula (16/3)k^3 + 10k^2 + 26/3(k) + 1
    num k = (n - 1) / 2;
    num solution = (16 * k * k * k) + (30 * k * k) + (26 * k) + 3;

    return solution / 3;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Sum of diagonals formed by an " << n << " by " << n <<
    " spiral is " << solution(n);

    return 0;
}

// Solved 29th August 2025.