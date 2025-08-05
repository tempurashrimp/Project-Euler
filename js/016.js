
/*  Problem 016:
    2^15= = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. 
    What is the sum of the digits of the number 2^1000? */

function solution() {
    // There has to be a better way to exponentiate surely
    let twoToN = BigInt(2**50);
    for (let i = 0; i < 19; i++) {
        twoToN *= BigInt(2**50);
    }

    let digitSum = 0;
    twoToN.toString().split("").forEach(digit => function () {
        digitSum += Number(digit);
    }());

    return digitSum;
}

// Solved 28th July 2025.