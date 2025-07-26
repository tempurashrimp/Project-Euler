
/*  Problem 015:
    Starting in the top left corner of a 2 * 2 grid, and only being able to move to the 
    right and down, there are exactly 6 routes to the bottom right corner. How many such 
    routes are there through a 20 * 20 grid? */

function solution(n) {
    // The function takes one input n, which
    // represents the size of the n * n grid.
    let sum = 1n;

    // Calculate the value of n choose
    // r using the binomial coefficient formula
    for (let i = 1; i <= n; i++){
        // (n + i) is actually (2n - n + i)
        sum = sum * (BigInt(n) + BigInt(i)) / BigInt(i);
    }

    return sum;
}

// Solved 26th July 2025.