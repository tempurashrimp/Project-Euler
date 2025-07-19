
/*  Problem 004: 
    A palindromic number reads the same both ways. The largest 
    palindrome made from the product of two 2-digit numbers is 
    9009=91*99. Find the largest palindrome made from the product 
    of two 3-digit numbers. */

function solution(n) {
    // The function takes one input n, which is the
    // maximum number of digits.
    if (n == 1) {
        // Trivial case
        return 9;
    }

    // Define lower and upper bounds.
    let lowerBound = Math.pow(10, n - 1);
    let upperBound = Math.pow(10, n) - 1;
    
    let maxPalindrome = 0;
    // Loop through every single digit.
    for (let i = upperBound; i >= lowerBound; i--) {
        // Only check each unique pair once (i.e. 101 * 102 = 102 * 101)
        for (let j = upperBound; j >= i; j--) {
            let product = i * j;

            // Since we are counting down, we can stop checking
            // as we would have found the largest palindrome first.
            if (product <= maxPalindrome) {
                break;
            }
            
            // Checking for palindrome without string operations
            let reverseProduct = 0;
            while (product != 0) {
                reverseProduct = (10 * reverseProduct) + (product % 10);
                product = Math.floor(product / 10);
            }

            if (i * j == reverseProduct) {
                maxPalindrome = reverseProduct;
            }
        }
    }

    return maxPalindrome;
}

// Solved 18th July 2025.
// Modified (1st time) 19th July 2025.