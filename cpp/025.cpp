
/*  Problem 025: 
    The Fibonacci sequence is defined by the recurrence relation:
    F_n = F_(n - 1) + F_(n - 2), where F_1 = 1 and F_2 = 2. Hence the first
    12 terms will be 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
    The 12th term, F_12, is the first term to contain three digits. What is the
    index of the first term in the Fibonacci sequence to contain 1000 digits? */
    
#include <iostream>
#include "LargeNumber.h"
using namespace std;

using num = unsigned long long;

num solution(num n) {
    // The function takes one input n, which is the number of digits
    // in the Fibonacci term.
    LargeNumber* fibTerms = new LargeNumber[3]
    {to_string(1), to_string(1), to_string(2)};
    num index = 3;

    while (fibTerms[2].number.length() < n) {
        fibTerms[0].number = fibTerms[1].number;
        fibTerms[1].number = fibTerms[2].number;
        fibTerms[2] = fibTerms[1] + fibTerms[0];

        index++;
    }

    delete[] fibTerms;
    return index;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Index of first Fibonacci term with "
        << n << " digits is " << solution(n) << endl;

    return 0;
}

// Solved 23rd August 2025.