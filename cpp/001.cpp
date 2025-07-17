
/*  Problem 001:
    If we list all the natural numbers below 10 that are multiples of 3 or 5, 
    we get 3, 5, 6 and 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000. */

#include <iostream>
#include <cmath>
using namespace std;

#define num long long int

num solution(num n) {
    // The function takes one input n, which is the higher limit
    // First note that 3 + 6 + 9 + ... = 3(1 + 2 + 3 + ...).
    // Hence, without the use of loops, we can solve this problem in O(1)
    // by effectively taking the whole number part of the quotient.
    // Also, note that 1 + 2 + 3 + ... + n = [n(n+1)]/2.
    num highest3 = (n - 1) / 3;
    num sum3 = 3 * ((highest3 * (highest3 + 1)) / 2);

    // The same logic can be applied to multiples of 5.
    num highest5 = (n - 1) / 5;
    num sum5 = 5 * ((highest5 * (highest5 + 1)) / 2);

    
    // Caution must be taken, as multiples of 15 
    // will eventually be double-counted.
    num highest15 = (n - 1) / 15;
    num sum15 = 15 * ((highest15 * (highest15 + 1)) / 2);

    return sum3 + sum5 - sum15;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Sum of all the multiples of 3 or 5 below "
        << n << " is " << solution(n) << endl;

    return 0;
}

// Solved on 17th July 2025.