
/*  Problem 020:
    n! means n * (n - 1) * ... * 3 * 2 * 1.
    For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
    and the sum of the digits in the number 10! is 
    3 + 6 + 2 + 8 + 8 + 0 + 0 = 27. Find the sum of the digits 
    in the number 100! */

function solution(n) {
    // The function takes one input n,
    // which we calculate its factorial of.
    let factorial = 1n;
    for (let i = n; i > 1; i--) {
        factorial *= BigInt(i);
    }

    let digitSum = 0;
    factorial.toString().split("").forEach(digit => function () {
        digitSum += Number(digit);
    }());

    return digitSum;
}

// Solved 5th August 2025.