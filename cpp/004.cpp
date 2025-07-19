
/*  Problem 004: 
    A palindromic number reads the same both ways. The largest 
    palindrome made from the product of two 2-digit numbers is 
    9009=91*99. Find the largest palindrome made from the product 
    of two 3-digit numbers. */
#include <iostream>
#include <cmath>
using namespace std;

using num = unsigned long long;

num solution(num n) {
    // The function takes one input n, which is the
    // maximum number of digits.
    if (n == 1) {
        // Trivial case
        return 9;
    }

    // Define lower and upper bounds.
    num lowerBound = pow(10, n - 1);
    num upperBound = pow(10, n) - 1;
    
    num maxPalindrome = 0;
    // Loop through every single digit.
    for (num i = upperBound; i >= lowerBound; i--) {
        // Only check each unique pair once (i.e. 101 * 102 = 102 * 101)
        for (num j = upperBound; j >= i; j--) {
            num product = i * j;

            // Since we are counting down, we can stop checking
            // as we would have found the largest palindrome first.
            if (product <= maxPalindrome) {
                break;
            }
            
            // Checking for palindrome without string operations
            num reverseProduct = 0;
            while (product != 0) {
                reverseProduct = (10 * reverseProduct) + (product % 10);
                product = floor(product / 10);
            }

            if (i * j == reverseProduct) {
                maxPalindrome = reverseProduct;
            }
        }
    }

    return maxPalindrome;
}

int main(void) {
    for (int n = 1; n < 6; n++) {
        cout << "The largest composite palindrome with two " 
        << n << "-digit products is " << solution(n) << endl;
    }

    return 0;
}

// Solved 18th July 2025.
// Modified (1st time) 19th July 2025.