
/*  Problem 018:
    By starting at the top of the triangle below and moving to adjacent numbers 
    on the row below, the maximum total from top to bottom is 23.
    3
    7 4
    2 4 6
    8 5 9 3
    That is, 3+7+4+9=23. Find the maximum total from top to bottom of the triangle below: */

function solution(triangle) {
    // triangle is an array representing
    // the triangle of numbers.

    // The size of the vector at row n is n.
    for (let i = 1; i < triangle.length; i++) {
        for (let j = 0; j <= i; j++) {
            if (j == 0) {
                // Element at the first column
                triangle[i][j] += triangle[i - 1][j];
            } else if (j == i) {
                // Element at the last column
                triangle[i][j] += triangle[i - 1][j - 1];
            } else {
                // Compare and add the maximum
                triangle[i][j] += (triangle[i - 1][j] > triangle[i - 1][j - 1]) ?
                    triangle[i - 1][j] : triangle[i - 1][j - 1];
            }
        }
    }

    return Math.max(...triangle[triangle.length - 1]);
}

// Solved 31st July 2025.