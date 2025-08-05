
/*  Problem 020:
    n! means n * (n - 1) * ... * 3 * 2 * 1.
    For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
    and the sum of the digits in the number 10! is 
    3 + 6 + 2 + 8 + 8 + 0 + 0 = 27. Find the sum of the digits 
    in the number 100! */

#include <iostream>
#include "LargeNumber.h"

using namespace std;

int solution(int n) {
    // The function takes one input n,
    // which we calculate its factorial of.
    LargeNumber factorial("1");

    // Recursively multiply
    for (int i = n; i > 1; i--) {
        factorial = factorial * LargeNumber(to_string(i));
    }

    int digitSum = 0;
    for (char digit : factorial.number) {
        digitSum += (digit - '0');
    }

    return digitSum;
}

int main(void) {
    int n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Sum of digits in " << n <<"! is " <<
    solution(n) << endl;

    return 0;
}

// Solved 5th August 2025.