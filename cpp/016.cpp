
/*  Problem 016:
    2^15= = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. 
    What is the sum of the digits of the number 2^1000? */

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "LargeNumber.h"

using namespace std;

int solution() {
    // 2^1000 = (2^50)^20
    LargeNumber twoToFifty(to_string(
        static_cast<unsigned long long>(pow(2, 50))));
    LargeNumber twoToAThousand(to_string(
        static_cast<unsigned long long>(pow(2, 50))));

    for (int i = 0; i < 19; i++) {
        twoToAThousand = twoToAThousand * twoToFifty;
    }

    int digitSum = 0;
    for (char digit : twoToAThousand.number) {
        digitSum += (digit - '0');
    }

    return digitSum;
}

int main(void) {
    cout << "The sum of digits in 2^1000 is " << solution();

    return 0;
}

// Solved 28th July 2025.
// Modified (1st time) 30th July 2025.