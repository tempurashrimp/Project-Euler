
/*  Problem 023:
    A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
    For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect 
    number. A number n is called deficient if the sum of its proper divisors is less than  n and it is called 
    abundant if this sum exceeds n. As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number 
    that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers 
    greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further 
    by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is 
    less than this limit. Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers. */

function divisorSum(n) {
    // The function takes one input n, which the function
    // computes the factors of.
    let sum = 0;

    // TODO: use PrimeSieve to factorize
    for (let i = 1; i * i <= n; i++) {
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

function solution(LIMIT) {
    // Implements a sieve of numbers which cannot be written
    // as the sum of two abundant numbers.
    LIMIT = LIMIT > 28124 ? 28124 : LIMIT;

    let deficient = 0;
    let notAbundantSum = new Array(LIMIT + 1);
    notAbundantSum.fill(true);
    let abundantNumbers = [];

    // 12 is the smallest abundant number.
    for (let i = 12; i < LIMIT + 1; i++) {
        if ((divisorSum(i) > i) && notAbundantSum[i]) {
            abundantNumbers.push(i);
            let abundant = 2 * i;

            while (abundant < LIMIT) {
                // Multiples of an abundant number are abundant.
                notAbundantSum[abundant] = false;
                abundantNumbers.push(abundant);
                abundant += i;
            }
        }
    }

    // Sort and drop duplicates
    abundantNumbers = [...new Set(abundantNumbers)].sort((a, b) => a - b);

    // Mark all numbers that are sums of abundant numbers.
    for (let i = 0; i < abundantNumbers.length; i++) {
        for (let j = 0; j < abundantNumbers.length; j++) {
            if (abundantNumbers[i] + abundantNumbers[j] <= LIMIT) {
                notAbundantSum[abundantNumbers[i] + abundantNumbers[j]] = false;
            } else {
                break;
            }
        }
    }

    for (let i = 1; i < LIMIT + 1; i++) {
        if (notAbundantSum[i]) {
            deficient += i;
        }
    }

    return deficient;
}

// Solved 20th August 2025.