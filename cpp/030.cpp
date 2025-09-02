
/*  Problem 030:
    Surprisingly there are only three numbers that can be written as 
    the sum of fourth powers of their digits: 
    1634 = 1^4 + 6^4 + 3^4 + 4^4 
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4 
    As 1 = 1^4 is not a sum it is not included. The sum of these numbers
    is 1634 + 8208 + 9474 = 19316. Find the sum of all the numbers that can
    be written as the sum of fifth powers of their digits. */

#include <iostream>
#include <string>

using num = unsigned long long;
using namespace std;

// Pre-compute fifth powers.
static int fifthPowers[10] = {0, 1, 32, 243, 1024, 3125, 
7776, 16807, 32768, 59049};

inline int fifthPowerSum(int n) {
    // Computes the sum of the fifth powers of the digits
    // of the input n.

    string m = to_string(n);
    int sum = 0;
    for (char digit : m) {
        sum += fifthPowers[digit - '0'];
    }

    return sum;
}


int solution() {
    int sum = 0;

    // The largest meaningful number is 354294 = 6 * 9^5.
    for (int i = 2; i <= 354294; ++i) {
        if (fifthPowerSum(i) == i) {
            sum += i;
        }
    }

    return sum;
}


int main (void) {
    cout << "Sum of all the numbers that equal the sum of 5th powers of their digits is " 
    << solution();

    return 0;
}

// Solved 2nd September 2025.