
/*  Problem 008:
    The four adjacent digits in the 1000-digit number that have the 
    greatest product are 9 * 9 * 8 * 9 = 5832. Find the thirteen adjacent 
    digits in the 1000-digit number that have the greatest product. 
    What is the value of this product? */

// Placeholder array (don't know how to implement file I/O in JS yet)
let thousandDigits = [7, 3, 1];

function solution(n) {
    // The function takes one input n, which represents the
    // number of consecutive digits to calculate.
    let largestProduct = 0, product = 0;

    // Repeatedly multiply each sequence of digits.
    for (let i = 0; i < 1000 - n; i++) {
        product = 1;

        for (let j = i; j < i + n; j++) {
            product *= thousandDigits[j];
            if (product == 0) {
                // 0 is present in the sequence
                break;
            }

            // Set largestProduct = product if it is greater.
            largestProduct = product > largestProduct ? product : largestProduct;
        }
    }

    return largestProduct;
}

// Solved 21st July 2025.