
/*  Problem 011:
    In the 20 * 20 grid below, four numbers along a diagonal 
    line have been marked in red. The product of these numbers is 
    26 * 63 * 78 * 13 = 1788696. What is the greatest product of four
    adjacent numbers in the same direction (up, down, left, right, or diagonally) 
    in the 20 * 20 grid? */

// Placeholder array (don't know how to implement file I/O in JS yet)
let grid = [8, 2, 22];

function solution(arr) {
    let dimension = arr.length;
    let greatestProduct = 0;

    // Read horizontally.
    for (let i = 0; i < dimension - 3; ++i) {
        for (let j = 0; j < dimension; ++j) {
            let product = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }


    // Read vertically.
    for (let i = 0; i < dimension - 3; ++i) {
        for (let j = 0; j < dimension; ++j) {
            let product = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }

    // Read diagonally (\)
    for (let i = 0; i < dimension - 3; ++i) {
        for (let j = 0; j < dimension - 3; ++j) {
            let product = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }

    // Read diagonally (/)
    for (let i = 0; i < dimension - 3; ++i) {
        for (let j = dimension - 1; j >= 3; --j) {
            let product = arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }

    return greatestProduct;
}

// Solved 24th July 2025.