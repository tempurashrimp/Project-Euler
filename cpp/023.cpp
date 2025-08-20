
/*  Problem 023:
    A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
    For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect 
    number. A number n is called deficient if the sum of its proper divisors is less than  n and it is called 
    abundant if this sum exceeds n. As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number 
    that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers 
    greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further 
    by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is 
    less than this limit. Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers. */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

inline int divisorSum(int n) {
    // The function takes one input n, which the function
    // computes the factors of.
    int sum = 0;

    // TODO: use PrimeSieve to factorize
    for (size_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            // i is a factor of n
            sum += i; 

            if (n / i != i) {
                sum += n / i;
            }
        }
    }

    // Since n is repeated
    return sum - n;
}

int solution(int LIMIT) {
    // Implements a sieve of numbers which cannot be written
    // as the sum of two abundant numbers.
    LIMIT = LIMIT > 28124 ? 28124 : LIMIT;

    int deficient = 0;
    vector<bool> notAbundantSum(LIMIT + 1, true);
    set<int> abundantSet;

    // 12 is the smallest abundant number.
    for (size_t i = 12; i < LIMIT + 1; i++) {
        if (notAbundantSum[i] && (divisorSum(i) > i)) {
            abundantSet.insert(i);
            int abundant = 2 * i;

            while (abundant < LIMIT) {
                // Multiples of an abundant number are abundant.
                notAbundantSum[abundant] = false;
                abundantSet.insert(abundant);
                abundant += i;
            }
        }
    }

    // Convert set to vector
    vector<int> abundantVec(abundantSet.size());
    copy(abundantSet.begin(), abundantSet.end(), abundantVec.begin());
    abundantSet.clear();

    // Mark all numbers that are sums of abundant numbers.
    for (size_t i = 0; i < abundantVec.size(); i++) {
        for (size_t j = 0; j < abundantVec.size(); j++) {
            if (abundantVec[i] + abundantVec[j] <= LIMIT) {
                notAbundantSum[abundantVec[i] + abundantVec[j]] = false;
            } else {
                break;
            }
        }
    }

    for (size_t i = 1; i < LIMIT + 1; i++) {
        if (notAbundantSum[i]) {
            deficient += i;
        }
    }

    return deficient;
}

int main(void) {
    int n;
    cout << "Input an integer: ";
    cin >> n;

    
    cout << "Sum of numbers under " << n << 
    " that cannot be written as abundant numbers is " << solution(n);
    return 0;
}

// Solved 20th August 2025.