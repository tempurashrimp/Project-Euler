
/*  Problem 025: 
    The Fibonacci sequence is defined by the recurrence relation:
    F_n = F_(n - 1) + F_(n - 2), where F_1 = 1 and F_2 = 2. Hence the first
    12 terms will be 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
    The 12th term, F_12, is the first term to contain three digits. What is the
    index of the first term in the Fibonacci sequence to contain 1000 digits? */

function solution(n) {
    // The function takes one input n, which is the number of digits
    // in the Fibonacci term.
    let fibTerms = [1n, 1n, 2n];
    let index = 3;

    while (fibTerms[2].toString().length < n) {
        // Compute next term
        fibTerms[0] = fibTerms[1];
        fibTerms[1] = fibTerms[2];
        fibTerms[2] = fibTerms[1] + fibTerms[0];

        index++;
    }

    return index;
}

// Solved 23rd August 2025.