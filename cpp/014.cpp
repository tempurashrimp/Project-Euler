
/*  Problem 014:
    The following iterative sequence is defined for the set of positive integers:
        n -> n/2 (n is even)
        n -> 3n + 1 (n is odd)
    Using the rule above and starting with 13, we generate the following sequence:
        13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
    It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
    Although it has not been proved yet (Collatz Problem), it is thought that all starting 
    numbers finish at 1. Which starting number, under one million, produces the longest chain? 
    NOTE: Once the chain starts the terms are allowed to go above one million. */

#include <iostream>

using namespace std;
using num = unsigned long long;

num solution(num n) {
    // The function takes one input n, which is the number
    // we test the Collatz sequence up to.

    num longest = 0, terms = 1, longestTerms = 1, k;
    for (num i = n / 2; i < n; i++) {
        // Because of the recursive property of the Collatz sequence,
        // Collatz(2n) = Collatz(n) + 1, hence we only need to check
        // in the range 0.5n <= i < n.
        terms = 1, k = i;

        while (k != 1) {
            // Apply the Collatz sequence.
            terms++;

            if (k % 2) {
                k = 3 * k + 1;
            } else {
                k = k / 2;
            }

        }

        if (terms > longestTerms) {
            longestTerms = terms;
            longest = i;
        }
    }

    return longest;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Number under " << n << " with longest Collatz sequence is "
        << solution(n) << endl;

    return 0;
}

// Solved 26th July 2025.