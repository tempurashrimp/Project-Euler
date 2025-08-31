
/*  Problem 028:
    Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 
    spiral is formed as follows:
    21 22 23 24 25
    20  7  8  9 10
    19  6  1  2 11
    18  5  4  3 12
    17 16 15 14 13
    It can be verified that the sum of the numbers on the diagonals is 101. What is the sum 
    of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way? */

function exponentiate(a, b) {
    // Compute a ^ b
    a = BigInt(a);
    let outcome = BigInt(a);

    for (let i = 1; i < b; i++) {
        outcome *= a;
    }

    return outcome;
}


function solution(n) {
    // The function takes in one input n, which represents the upper bounds
    // of both a and b,

    let numbers = new Set();

    for (let a = 2; a <= n; ++a) {
        for (let b = 2; b <= n; ++b) {
            numbers.add(exponentiate(a, b));
        }
    }

    return numbers.size;
}

// Solved 31st August 2025.