
/*  Problem 030:
    Surprisingly there are only three numbers that can be written as 
    the sum of fourth powers of their digits: 
    1634 = 1^4 + 6^4 + 3^4 + 4^4 
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4 
    As 1 = 1^4 is not a sum it is not included. The sum of these numbers
    is 1634 + 8208 + 9474 = 19316. Find the sum of all the numbers that can
    be written as the sum of fifth powers of their digits. */

function solution() {
    // Pre-compute fifth powers.
    let sum = 0;
    let fifthPowers = [0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049];

    // The largest meaningful number is 354294 = 6 * 9^5.
    for (let i = 2; i <= 354294; i++) {
        // Computes the sum of the fifth powers of the digits
        // of the input n.
        if (i == i.toString().split("").reduce((acc, cur) => function () {
            return acc + fifthPowers[cur];
        }(), 0)) {
            sum += i;
        }
    }

    return sum;
}

// Solved 2nd September 2025.