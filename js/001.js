
/*  Problem 001:
    If we list all the natural numbers below 10 that are multiples of 3 or 5, 
    we get 3, 5, 6 and 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000. */


function solution(n) {
    // The function takes one input n, which is the higher limit
    // First note that 3 + 6 + 9 + ... = 3(1 + 2 + 3 + ...).
    // Hence, without the use of loops, we can solve this problem in O(1)
    // by effectively taking the whole number part of the quotient.
    // Also, note that 1 + 2 + 3 + ... + n = [n(n+1)]/2.
    const highest3 = Math.floor((n - 1) / 3);
    const sum3 = 3 * ((highest3 * (highest3 + 1)) / 2);

    // The same logic can be applied to multiples of 5.
    const highest5 = Math.floor((n - 1) / 5);
    const sum5 = 5 * ((highest5 * (highest5 + 1)) / 2);
    
    // Caution must be taken, as multiples of 15 
    // will eventually be double-counted.
    const highest15 = Math.floor((number - 1) / 15);
    const sum15 = 15 * ((highest15 * (highest15 + 1)) / 2);

    return sum3 + sum5 - sum15;
}

console.log(solution(1000));

// Solved on 17th July 2025.