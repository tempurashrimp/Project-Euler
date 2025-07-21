
/*  Problem 009:
    A Pythagorean triplet is a set of three natural numbers, a<b<c, for which,
    a^2 + b^2 = c^2  For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2. 
    There exists exactly one Pythagorean triplet for which a + b + c = 1000. 
    Find the product abc. */

function solution(k) {
    // The function takes one input k, which represents the
    // number we wish to find the Pythagorean triplet for.
    let sumOfABC = 0, productOfABC = 0;
    let m = 2, n = 1;
    // Halt computation if m exceeds this number.
    let maxNumber = 1000000;

    while (sumOfABC != k && m <= maxNumber) {
        // By Euclid's formula, recursively generate
        // Pythagorean triples (without a need to verify.)
        let a = (m * m) - (n * n), b = 2 * m * n,
            c = (m * m) + (n * n);

        sumOfABC = a + b + c;
        productOfABC = a * b * c;

        // m > n > 0.
        n++;
        if (m <= n) {
            m++;
            n = 1;
        }
    }


    if (m > maxNumber) {
        console.error("Unable to find Pythagorean Triplet.");
        return;
    }

    return productOfABC;
}

// Solved 21st July 2025.