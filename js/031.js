
/*  Problem 031:
    In the United Kingdom the currency is made up of pound (£) and pence (p). 
    There are eight coins in general circulation:
    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
    It is possible to make £2 in the following way:
    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
    How many different ways can £2 be made using any number of coins? */

function solution(n) {
    // The function takes in one input n, which represents the
    // total amount of pence.
    let denom = [1, 2, 5, 10, 20, 50, 100, 200];

    let ways = new Array(denom.length).fill(Array(n + 1));
    ways[0][0] = 1;

    // There is always exactly one way to arrange 0p.
    for (let i = 0; i < denom.length; ++i) {
        ways[i][0] = 1;
    }

    // Loop through available coins.
    for (let i = 0; i < denom.length; ++i) {
        let coin = denom[i];

        // Loop through each sum.
        for (let j = 1; j <= n; ++j) {
            // Add newCoin if j is greater than the coin value.
            // This also sets the ways to arrange anything in 1p
            // to 1.
            let newCoin = (j >= coin ? ways[i][j - coin] : 0);
            let previous = (i >= 1) ? ways[i - 1][j] : 0;

            ways[i][j] = newCoin + previous;
        }
    }

    return ways[denom.length - 1][n];
}

// Solved 4th September 2025.